#ifndef usb_h
#define usb_h

#include "stm32f0xx.h"
#include "Timer.h"
#include "USBStructures.h"

namespace STM32F072USB
{
	const uint32_t PMABaseAddress = 0x40006000;
	const uint32_t BufferTableOffset = 0x0; //place buffer descriptors at start of PMA
	const uint32_t BufferTableFirstAddress = 0x40;
	
	struct BufferDescription
	{
		volatile uint16_t * const TxAddress;
		volatile uint16_t * const TxCount;
		volatile uint16_t * const RxAddress;
		volatile uint16_t * const RxCount;
		
		BufferDescription(volatile uint16_t * const txAddress, volatile  uint16_t * const txCount, volatile  uint16_t * const rxAddress, volatile uint16_t * const rxCount)
		: TxAddress(txAddress)
		, TxCount(txCount)
		, RxAddress(rxAddress)
		, RxCount(rxCount)
		{}
	};
	
	volatile uint16_t * const Address0Tx     = (uint16_t *)0x40006000;
    volatile uint16_t * const Count0Tx       = (uint16_t *)0x40006002;
    volatile uint16_t * const Address0Rx     = (uint16_t *)0x40006004;
    volatile uint16_t * const Count0Rx       = (uint16_t *)0x40006006;

    volatile uint16_t * const Address1Tx     = (uint16_t *)0x40006008;
    volatile uint16_t * const Count1Tx       = (uint16_t *)0x4000600A;
    volatile uint16_t * const Address1Rx     = (uint16_t *)0x4000600C;
    volatile uint16_t * const Count1Rx       = (uint16_t *)0x4000600E;

    volatile uint16_t * const Address2Tx     = (uint16_t *)0x40006010;
    volatile uint16_t * const Count2Tx       = (uint16_t *)0x40006012;
    volatile uint16_t * const Address2Rx     = (uint16_t *)0x40006014;
    volatile uint16_t * const Count2Rx       = (uint16_t *)0x40006016;

    volatile uint16_t * const Address3Tx     = (uint16_t *)0x40006018;
    volatile uint16_t * const Count3Tx       = (uint16_t *)0x4000601A;
    volatile uint16_t * const Address3Rx     = (uint16_t *)0x4000601C;
    volatile uint16_t * const Count3Rx       = (uint16_t *)0x4000601E;

    volatile uint16_t * const Address4Tx     = (uint16_t *)0x40006020;
    volatile uint16_t * const Count4Tx       = (uint16_t *)0x40006022;
    volatile uint16_t * const Address4Rx     = (uint16_t *)0x40006024;
    volatile uint16_t * const Count4Rx       = (uint16_t *)0x40006026;

    volatile uint16_t * const Address5Tx     = (uint16_t *)0x40006028;
    volatile uint16_t * const Count5Tx       = (uint16_t *)0x4000602A;
    volatile uint16_t * const Address5Rx     = (uint16_t *)0x4000602C;
    volatile uint16_t * const Count5Rx       = (uint16_t *)0x4000602E;

    volatile uint16_t * const Address6Tx     = (uint16_t *)0x40006030;
    volatile uint16_t * const Count6Tx       = (uint16_t *)0x40006032;
    volatile uint16_t * const Address6Rx     = (uint16_t *)0x40006034;
    volatile uint16_t * const Count6Rx       = (uint16_t *)0x40006036;

    volatile uint16_t * const Address7Tx     = (uint16_t *)0x40006038;
    volatile uint16_t * const Count7Tx       = (uint16_t *)0x4000603A;
    volatile uint16_t * const Address7Rx     = (uint16_t *)0x4000603C;
    volatile uint16_t * const Count7Rx       = (uint16_t *)0x4000603E;
	
	enum class EpStates
	{
		Disabled,
		Stall,
		NAK,
		Valid
	};
}

class USBDevice
{
	static const STM32F072USB::BufferDescription PMABufferDescriptorTable[];
	USB_TypeDef *mUSB;
	Timer *mTimer;
	
	uint8_t mEP0RxBuffer[64];
	USBStructures::SetupPacket mRxSetupPacket;

	DeviceState mDeviceState;
	
public:
	USBDevice(USB_TypeDef *usb, Timer *timer);
	void HardwareInit();
	void EnableInterrupts();

	//interrupts
	void CorrectTransferIRQ();
	void PacketMemoryIRQ();
	void ErrorIRQ();
	void WakeUpIRQ();
	void SuspendIRQ();
	void ResetIRQ();
	void StartOfFrameIRQ();
	void ExpectedStartOfFrameIRQ();
	void L1RequestIRQ();

	//Control endpoint
	void EP0CorrectTransferRx();
	void EP0CorrectTransferTx();
	
	//misc
	void PMAToUserBufferCopy(uint8_t *pbUsrBuf, uint16_t wPMABufAddr, uint16_t wNBytes);
	void UserToPMABufferCopy(uint8_t *pbUsrBuf, uint16_t wPMABufAddr, uint16_t wNBytes);
};

#endif
