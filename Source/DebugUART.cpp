#include "DebugUART.h"

namespace
{
	DebugUART *debugUART;
}

DebugUART::DebugUART(USART_TypeDef *uart, uint32_t busFrequency, uint32_t baudRate)
: mUart(uart)
, mBusFrequency(busFrequency)
, mBaudRate(baudRate)
{
	debugUART = this;
	
	mUart->BRR = mBusFrequency / mBaudRate;
	
	NVIC_EnableIRQ(USART2_IRQn);
}

void DebugUART::DebugTx(uint8_t *txData, uint32_t txLength)
{
	for(uint32_t i = 0; i < txLength; i++)
	{
		CocoLib::BufferStatus status = mTxBuffer.Add(txData[i]);
		if(status != CocoLib::BufferStatus::OK)
		{
			break;
		}
		
		EnableTx();
	}
}

void DebugUART::EnableTx()
{
	mUart->CR1 = USART_CR1_TXEIE | USART_CR1_TE | USART_CR1_UE;
}

void DebugUART::TxEmptyIRQ()
{
	uint8_t data;
	CocoLib::BufferStatus status = mTxBuffer.Remove(data);
	if(status == CocoLib::BufferStatus::OK)
	{
		mUart->TDR = data;
	}
	else if(status == CocoLib::BufferStatus::Empty)
	{
		//nothing else to send, enable tc irq
		mUart->CR1 |= USART_CR1_TCIE;
	}
}

void DebugUART::TxCompleteIRQ()
{
	if(mTxBuffer.IsEmpty())
	{
		mUart->CR1 = 0;
	}
}

extern "C" void USART2_IRQHandler()
{
	if(USART2->ISR & USART_ISR_TXE)
		debugUART->TxEmptyIRQ();
	
	if(USART2->ISR & USART_ISR_TC)
		debugUART->TxCompleteIRQ();
}
