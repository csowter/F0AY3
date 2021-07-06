#ifndef ay3iointerface_h
#define ay3iointerface_h

#include <stdint.h>

class AY3IOInterface
{
public:
	virtual ~AY3IOInterface(){}
	virtual void WriteData(uint8_t data) = 0;
	virtual uint8_t ReadData() = 0;
	virtual void WriteAddress(uint8_t address) = 0;
};

#endif
