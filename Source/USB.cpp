#include "USB.h"
#include "SoftTimer.h"

const STM32F072USB::BufferDescription USBDevice::PMABufferDescriptorTable[] = 
{
    STM32F072USB::BufferDescription(STM32F072USB::Address0Tx, STM32F072USB::Count0Tx, STM32F072USB::Address0Rx, STM32F072USB::Count0Rx),
    STM32F072USB::BufferDescription(STM32F072USB::Address1Tx, STM32F072USB::Count1Tx, STM32F072USB::Address1Rx, STM32F072USB::Count1Rx),
    STM32F072USB::BufferDescription(STM32F072USB::Address2Tx, STM32F072USB::Count2Tx, STM32F072USB::Address2Rx, STM32F072USB::Count2Rx),
    STM32F072USB::BufferDescription(STM32F072USB::Address3Tx, STM32F072USB::Count3Tx, STM32F072USB::Address3Rx, STM32F072USB::Count3Rx),
    STM32F072USB::BufferDescription(STM32F072USB::Address4Tx, STM32F072USB::Count4Tx, STM32F072USB::Address4Rx, STM32F072USB::Count4Rx),
    STM32F072USB::BufferDescription(STM32F072USB::Address5Tx, STM32F072USB::Count5Tx, STM32F072USB::Address5Rx, STM32F072USB::Count5Rx),
    STM32F072USB::BufferDescription(STM32F072USB::Address6Tx, STM32F072USB::Count6Tx, STM32F072USB::Address6Rx, STM32F072USB::Count6Rx),
    STM32F072USB::BufferDescription(STM32F072USB::Address7Tx, STM32F072USB::Count7Tx, STM32F072USB::Address7Rx, STM32F072USB::Count7Rx),
};

namespace
{
	USBDevice *USBInstance = nullptr;
}

USBDevice::USBDevice(USB_TypeDef *usb, Timer *timer)
: mUSB{usb}
, mTimer{timer}
{
	USBInstance = this;
}

void USBDevice::HardwareInit()
{
	mUSB->CNTR &= ~USB_CNTR_PDWN;
	SoftTimer delay(mTimer, mTimer->UsToTicks(4));
	while(!delay.Elapsed()){} //wait for analogue transceiver to settle
    
    mUSB->ISTR = 0;
	EnableInterrupts();
	
    mUSB->CNTR &= ~USB_CNTR_FRES; //release from reset
}

void USBDevice::EnableInterrupts()
{
	mUSB->CNTR = USB_CNTR_CTRM   
		| USB_CNTR_PMAOVRM
		| USB_CNTR_ERRM   
		| USB_CNTR_WKUPM  
		| USB_CNTR_SUSPM  
		| USB_CNTR_RESETM 
		| USB_CNTR_SOFM   
		| USB_CNTR_ESOFM  
		| USB_CNTR_L1REQM;

	NVIC_EnableIRQ(USB_IRQn);
}

//interrupts
void USBDevice::CorrectTransferIRQ()
{}
void USBDevice::PacketMemoryIRQ()
{}
void USBDevice::ErrorIRQ()
{}
void USBDevice::WakeUpIRQ()
{}
void USBDevice::SuspendIRQ()
{}
	
void USBDevice::ResetIRQ()
{
	//make space in the buffer ram for control transfers
	*PMABufferDescriptorTable[0].TxAddress = STM32F072USB::BufferTableFirstAddress;
    *PMABufferDescriptorTable[0].TxCount = 0x0;
    *PMABufferDescriptorTable[0].RxAddress = *PMABufferDescriptorTable[0].TxAddress + 0x40;
    *PMABufferDescriptorTable[0].RxCount = 1 << 15 | 1 << 10;

	//allocate space for midi end points 
	*PMABufferDescriptorTable[1].TxAddress = *PMABufferDescriptorTable[0].RxAddress + 0x40;
    *PMABufferDescriptorTable[1].TxCount = 0x0;
    *PMABufferDescriptorTable[1].RxAddress = *PMABufferDescriptorTable[1].TxAddress + 0x40;
    *PMABufferDescriptorTable[1].RxCount = 1 << 15 | 1 << 10;
	
	//tell usb peripheral where the buffer address table is
	mUSB->BTABLE = STM32F072USB::BufferTableOffset;
    
	//configure EP0 as control, ready to receive, NAK tx
	mUSB->EP0R = USB_EP_CONTROL | USB_EP_RX_VALID | USB_EP_TX_NAK;
	
	mUSB->DADDR = USB_DADDR_EF; //enable on address 0
    
    mUSB->BCDR = USB_BCDR_DPPU; //enable pullup
}
	
void USBDevice::StartOfFrameIRQ()
{}
void USBDevice::ExpectedStartOfFrameIRQ()
{}
void USBDevice::L1RequestIRQ()
{}

extern "C" void USB_IRQHandler(void)
{
	if(USB->ISTR & USB_ISTR_CTR)
	{
		USBInstance->CorrectTransferIRQ();
	}
	
	if(USB->ISTR & USB_ISTR_PMAOVR)
	{
		USBInstance->PacketMemoryIRQ();
		USB->ISTR = (0xFFFF & ~USB_ISTR_PMAOVR);
	}
	
	if(USB->ISTR & USB_ISTR_ERR)
	{
		USBInstance->ErrorIRQ();
		USB->ISTR = (0xFFFF & ~USB_ISTR_ERR);
	}
	
	if(USB->ISTR & USB_ISTR_WKUP)
	{
		USBInstance->WakeUpIRQ();
		USB->ISTR = (0xFFFF & ~USB_ISTR_WKUP);
	}
	
	if(USB->ISTR & USB_ISTR_SUSP)
	{
		USBInstance->SuspendIRQ();
		USB->ISTR = (0xFFFF & ~USB_ISTR_SUSP);
	}
	
	if(USB->ISTR & USB_ISTR_RESET)
	{
		USBInstance->ResetIRQ();
		USB->ISTR = (0xFFFF & ~USB_ISTR_RESET);
	}
	
	if(USB->ISTR & USB_ISTR_SOF)
	{
		USBInstance->StartOfFrameIRQ();
		USB->ISTR = (0xFFFF & ~USB_ISTR_SOF);
	}
	
	if(USB->ISTR & USB_ISTR_ESOF)
	{
		USBInstance->ExpectedStartOfFrameIRQ();
		USB->ISTR = (0xFFFF & ~USB_ISTR_ESOF);
	}
	
	if(USB->ISTR & USB_ISTR_L1REQ)
	{
		USBInstance->L1RequestIRQ();
		USB->ISTR = (0xFFFF & ~USB_ISTR_L1REQ);
	}
}