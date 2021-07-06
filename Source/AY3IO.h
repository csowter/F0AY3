#ifndef ay3io_h
#define ay3io_h

#include "AY3IOInterface.h"
#include <stdint.h>

class AY3IO : public AY3IOInterface
{
	
public:
	virtual void WriteData(uint8_t data) override;
	virtual uint8_t ReadData() override;
	virtual void WriteAddress(uint8_t address) override;
};

#endif
