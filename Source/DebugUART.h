#ifndef debuguart_h
#define debuguart_h

#include <stdint.h>
#include "LockFreeCircularBuffer.h"
#include "stm32f0xx.h"

class DebugUART
{
	CocoLib::LockFreeCircularBuffer<uint8_t, 256> mTxBuffer;
	USART_TypeDef *mUart;
	uint32_t mBusFrequency;
	uint32_t mBaudRate;
	
	void EnableTx();
	
public:
	DebugUART(USART_TypeDef *uart, uint32_t busFrequency, uint32_t baudRate);
	void DebugTx(uint8_t *txData, uint32_t txLength);

	void TxEmptyIRQ();
	void TxCompleteIRQ();
};	

#endif
