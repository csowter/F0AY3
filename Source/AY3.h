#ifndef ay3_h
#define ay3_h

#include "AY3IOInterface.h"
#include <stdint.h>

namespace AY3Registers
{
	const uint32_t ChannelAFineTune = 0;
	const uint32_t ChannelACoarseTune = 1;
	const uint32_t ChannelBFineTune = 2;
	const uint32_t ChannelBCoarseTune = 3;
	const uint32_t ChannelCFineTune = 4;
	const uint32_t ChannelCCoarseTune = 5;
	const uint32_t NoisePeriod = 6;
	const uint32_t Enable = 7;
	const uint32_t ChannelAAmplitude = 8;
	const uint32_t ChannelBAmplitude = 9;
	const uint32_t ChannelCAmplitude = 10;
	const uint32_t EnvelopePeriodFine = 11;
	const uint32_t EnvelopePeriodCoarse = 12;
	const uint32_t EnvelopeShape = 13;
	const uint32_t IOPortA = 14;
	const uint32_t IOPortB = 15;
}

namespace TonePeriodRegister
{
	const uint32_t Mask = 0xFFF;
}

namespace NoisePeriodRegister
{
	const uint32_t Mask = 0x1F;
}

namespace EnableRegister
{
	const uint32_t ToneAEnable = 0x01;
	const uint32_t ToneBEnable = 0x02;
	const uint32_t ToneCEnable = 0x04;
	const uint32_t NoiseAEnable = 0x08;
	const uint32_t NoiseBEnable = 0x10;
	const uint32_t NoiseCEnable = 0x20;
	const uint32_t IOA = 0x40;
	const uint32_t IOB = 0x80;
}

namespace AmplitudeRegister
{
	const uint32_t AmplitudeMask = 0x0F;
	const uint32_t EnableEnvelope = 0x10;
}

namespace EnvelopeModeRegisters
{
	const uint32_t Hold = 0x01;
	const uint32_t Alternate = 0x02;
	const uint32_t Attack = 0x04;
	const uint32_t Continue = 0x08;
}

class AY3
{
	
	uint8_t mRegisters[16];
	AY3IOInterface *mIOInterface;
	
public:
	AY3(AY3IOInterface *ioInterface);
	void SetTonePeriod(uint16_t period, uint32_t channel);
	void SetNoisePeriod(uint8_t period);
	void EnableNoise(bool enable, uint32_t channel);
	void EnableTone(bool enable, uint32_t channel);
	void SetAmplitude(uint32_t amplitude, uint32_t channel);
	void EnableEnvelope(bool enable, uint32_t channel);
	void SetEnvelopePeriod(uint16_t period);
	void SetEnvelopeMode(uint8_t mode);
};


#endif
