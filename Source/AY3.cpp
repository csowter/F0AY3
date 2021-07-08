#include "AY3.h"

AY3::AY3(AY3IOInterface *ioInterface)
: mIOInterface(ioInterface)
{
	for(uint32_t i = 0; i < 16; i++)
		mRegisters[i] = 0;
	mRegisters[AY3Registers::Enable] = 0xff;
}

void AY3::SetTonePeriod(uint16_t period, uint32_t channel)
{
	uint8_t periodLSB = (period & 0xFF);
	uint8_t periodMSB = ((period & 0x0F00) >> 8);
	
	switch(channel)
	{
		case 0:
			mRegisters[AY3Registers::ChannelACoarseTune] = periodMSB;
			mRegisters[AY3Registers::ChannelAFineTune] = periodLSB;
		
			mIOInterface->WriteAddress(AY3Registers::ChannelACoarseTune);
			mIOInterface->WriteData(mRegisters[AY3Registers::ChannelACoarseTune]);
		
			mIOInterface->WriteAddress(AY3Registers::ChannelAFineTune);
			mIOInterface->WriteData(mRegisters[AY3Registers::ChannelAFineTune]);
			break;
		case 1:
			mRegisters[AY3Registers::ChannelBCoarseTune] = periodMSB;
			mRegisters[AY3Registers::ChannelBFineTune] = periodLSB;
		
			mIOInterface->WriteAddress(AY3Registers::ChannelBCoarseTune);
			mIOInterface->WriteData(mRegisters[AY3Registers::ChannelBCoarseTune]);
		
			mIOInterface->WriteAddress(AY3Registers::ChannelBFineTune);
			mIOInterface->WriteData(mRegisters[AY3Registers::ChannelBFineTune]);
			break;
		case 2:
			mRegisters[AY3Registers::ChannelCCoarseTune] = periodMSB;
			mRegisters[AY3Registers::ChannelCFineTune] = periodLSB;
		
			mIOInterface->WriteAddress(AY3Registers::ChannelCCoarseTune);
			mIOInterface->WriteData(mRegisters[AY3Registers::ChannelCCoarseTune]);
		
			mIOInterface->WriteAddress(AY3Registers::ChannelCFineTune);
			mIOInterface->WriteData(mRegisters[AY3Registers::ChannelCFineTune]);
			break;
	}
}

void AY3::SetNoisePeriod(uint8_t period)
{
	mRegisters[AY3Registers::NoisePeriod] = (period & NoisePeriodRegister::Mask);
	mIOInterface->WriteAddress(AY3Registers::NoisePeriod);
	mIOInterface->WriteData(mRegisters[AY3Registers::NoisePeriod]);
}

void AY3::EnableNoise(bool enable, uint32_t channel)
{
	switch(channel)
	{
		case 0:
			if(enable)
				mRegisters[AY3Registers::Enable] &= ~EnableRegister::NoiseAEnable;
			else
				mRegisters[AY3Registers::Enable] |= EnableRegister::NoiseAEnable;
			break;
		case 1:
			if(enable)
				mRegisters[AY3Registers::Enable] &= ~EnableRegister::NoiseBEnable;
			else
				mRegisters[AY3Registers::Enable] |= EnableRegister::NoiseBEnable;
			break;
		case 2:
			if(enable)
				mRegisters[AY3Registers::Enable] &= ~EnableRegister::NoiseCEnable;
			else
				mRegisters[AY3Registers::Enable] |= EnableRegister::NoiseCEnable;
			break;
	}
	
	mIOInterface->WriteAddress(AY3Registers::Enable);
	mIOInterface->WriteData(mRegisters[AY3Registers::Enable]);
}
	
void AY3::EnableTone(bool enable, uint32_t channel)
{
	switch(channel)
	{
		case 0:
			if(enable)
				mRegisters[AY3Registers::Enable] &= ~EnableRegister::ToneAEnable;
			else
				mRegisters[AY3Registers::Enable] |= EnableRegister::ToneAEnable;
			break;
		case 1:
			if(enable)
				mRegisters[AY3Registers::Enable] &= ~EnableRegister::ToneBEnable;
			else
				mRegisters[AY3Registers::Enable] |= EnableRegister::ToneBEnable;
			break;
		case 2:
			if(enable)
				mRegisters[AY3Registers::Enable] &= ~EnableRegister::ToneCEnable;
			else
				mRegisters[AY3Registers::Enable] |= EnableRegister::ToneCEnable;
			break;
	}
	
	mIOInterface->WriteAddress(AY3Registers::Enable);
	mIOInterface->WriteData(mRegisters[AY3Registers::Enable]);
}

void AY3::SetAmplitude(uint32_t amplitude, uint32_t channel)
{
	amplitude &= AmplitudeRegister::AmplitudeMask;
	switch(channel)
	{
		case 0:
			mRegisters[AY3Registers::ChannelAAmplitude] &= ~AmplitudeRegister::AmplitudeMask;
			mRegisters[AY3Registers::ChannelAAmplitude] |= amplitude;
		
			mIOInterface->WriteAddress(AY3Registers::ChannelAAmplitude);
			mIOInterface->WriteData(mRegisters[AY3Registers::ChannelAAmplitude]);
			break;
		
		case 1:
			mRegisters[AY3Registers::ChannelBAmplitude] &= ~AmplitudeRegister::AmplitudeMask;
			mRegisters[AY3Registers::ChannelBAmplitude] |= amplitude;
		
			mIOInterface->WriteAddress(AY3Registers::ChannelBAmplitude);
			mIOInterface->WriteData(mRegisters[AY3Registers::ChannelBAmplitude]);
			break;
		case 2:
			mRegisters[AY3Registers::ChannelCAmplitude] &= ~AmplitudeRegister::AmplitudeMask;
			mRegisters[AY3Registers::ChannelCAmplitude] |= amplitude;
		
			mIOInterface->WriteAddress(AY3Registers::ChannelCAmplitude);
			mIOInterface->WriteData(mRegisters[AY3Registers::ChannelCAmplitude]);
			break;
	}
}

void AY3::EnableEnvelope(bool enable, uint32_t channel)
{
	switch(channel)
	{
		case 0:
			if(enable)
				mRegisters[AY3Registers::ChannelAAmplitude] |= AmplitudeRegister::EnableEnvelope;
			else
				mRegisters[AY3Registers::ChannelAAmplitude] &= ~AmplitudeRegister::EnableEnvelope;
		
			mIOInterface->WriteAddress(AY3Registers::ChannelAAmplitude);
			mIOInterface->WriteData(mRegisters[AY3Registers::ChannelAAmplitude]);
			break;
		
		case 1:
			if(enable)
				mRegisters[AY3Registers::ChannelAAmplitude] |= AmplitudeRegister::EnableEnvelope;
			else
				mRegisters[AY3Registers::ChannelAAmplitude] &= ~AmplitudeRegister::EnableEnvelope;
		
			mIOInterface->WriteAddress(AY3Registers::ChannelBAmplitude);
			mIOInterface->WriteData(mRegisters[AY3Registers::ChannelBAmplitude]);
			break;
		case 2:
			if(enable)
				mRegisters[AY3Registers::ChannelAAmplitude] |= AmplitudeRegister::EnableEnvelope;
			else
				mRegisters[AY3Registers::ChannelAAmplitude] &= ~AmplitudeRegister::EnableEnvelope;
		
			mIOInterface->WriteAddress(AY3Registers::ChannelCAmplitude);
			mIOInterface->WriteData(mRegisters[AY3Registers::ChannelCAmplitude]);
			break;
	}
}

void AY3::SetEnvelopePeriod(uint16_t period)
{
	mRegisters[AY3Registers::EnvelopePeriodFine] = (period & 0xFF);
	mRegisters[AY3Registers::EnvelopePeriodCoarse] = ((period & 0xFF00) >> 8);
	
	mIOInterface->WriteAddress(AY3Registers::EnvelopePeriodFine);
	mIOInterface->WriteData(mRegisters[AY3Registers::EnvelopePeriodFine]);
	
	mIOInterface->WriteAddress(AY3Registers::EnvelopePeriodCoarse);
	mIOInterface->WriteData(mRegisters[AY3Registers::EnvelopePeriodCoarse]);
}

void AY3::SetEnvelopeMode(uint8_t envelopeMode)
{
	mRegisters[AY3Registers::EnvelopeShape] = envelopeMode;
	
	mIOInterface->WriteAddress(AY3Registers::EnvelopeShape);
	mIOInterface->WriteData(mRegisters[AY3Registers::EnvelopeShape]);
}
