#ifndef uac1descriptors_h
#define uac1descriptors_h

#include <stdint.h>

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bInterfaceNumber;
	uint8_t bAlternateSetting;
	uint8_t bNumEndpoints;
	uint8_t bInterfaceClass;
	uint8_t bInterfaceSubClass;
	uint8_t bInterfaceProtocol;
	uint8_t iInterface;
} sStandardAudioControlInterfaceDescriptor;

typedef __packed struct 
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint16_t bcdADC;
	uint16_t wTotalLength;
	uint8_t bInCollection;
	uint8_t baInterfaceNr;
	//more interface numbers can be added here
} sClassSpecificAudioControlInterfaceDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bTerminalID;
	uint16_t wTerminalType;
	uint8_t bAssocTerminal;
	uint8_t bNrChannels;
	uint16_t wChannelConfig;
	uint8_t iChannelNames;
	uint8_t iTerminal;
} sInputTerminalDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bTerminalID;
	uint16_t wTerminalType;
	uint8_t bAssocTerminal;
	uint8_t bSourceID;
	uint8_t iTerminal;
} sOutputTerminalDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bEndpointAddress;
	uint8_t bmAttributes;
	uint16_t mMaxPacketSize;
	uint8_t bInterval;
	uint8_t bRefresh;
	uint8_t bSynchAddress;
} sStandardAudioControlInterruptEndpointDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bInterfaceNumber;
	uint8_t bAlternateSetting;
	uint8_t bNumEndpoints;
	uint8_t bInterfaceClass;
	uint8_t bInterfaceSubClass;
	uint8_t bInterfaceProtocol;
	uint8_t iInterface;
} sStandardAudioStreamingInterfaceDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bTerminalLink;
	uint8_t bDelay;
	uint16_t wFormatTag;
} sClassSpecificAudioStreamingInterfaceDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bFormatType;
	uint8_t bNrChannels;
	uint8_t bSubframeSize;
	uint8_t bBitResolution;
	uint8_t bSamFreqType;
#ifdef TYPE1_FORMAT_CONTINUOUS_SAMPLING_FREQUENCY
	uint8_t tLowerSamFreq[3];
	uint8_t tUpperSamFreq[3];
#else
	uint8_t tSamFreq[3]; 
	//more sampling frequencies can be added here
#endif		
} sClassSpecificAudioStreamingTypeIFormatTypeDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bEndpointAddress;
	uint8_t bmAtributes;
	uint16_t wMaxPacketSize;
	uint8_t bInterval;
	uint8_t bRefresh;
	uint8_t bSynchAddress;
} sStandardAudioStreamingIsochronousAudioDataEndpointDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bmAttributes;
	uint8_t bLockDelayUnits;
	uint16_t wLockDelay;
} sClassSpecificAudioStreamingIsochronousAudioDataEndpointDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bEndpointAddress;
	uint8_t bmAttributes;
	uint16_t wMaxPacketSize;
	uint8_t bInterval;
	uint8_t bRefresh;
	uint8_t bSynchAddress;
} sStandardAudioStreamingIsochronousSynchEndpointDescriptor;

#endif
