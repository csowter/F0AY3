#ifndef mididescriptors_h
#define mididescriptors_h

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
} sStandardMIDIStreamingInterfaceDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint16_t bcdMSC;
	uint16_t wTotalLength;
} sClassSpecificMIDIStreamingInterfaceDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bJackType;
	uint8_t bJackID;
	uint8_t iJack;
} sMIDIInJackDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
    uint8_t bJackType;
	uint8_t bJackID;
	uint8_t bNrInputPins;
	uint8_t baSourceID;
	uint8_t baSourcePin;
	uint8_t iJack;	
} sMIDIOutJackDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bElementID;
	uint8_t bNrInputPins;
	uint8_t baSourceID;
	uint8_t baSourcePin;
	uint8_t bNrOutputPins;
	uint8_t bInTerminalLink;
	uint8_t bOutTerminalLink;
	uint8_t bElCapsSize;
	uint16_t bmElementCaps;
	uint8_t iElement;	
} sMIDIElementDescriptor;

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
} sStandardMIDIStreamingBulkDataEndpointDescriptor;

typedef __packed struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bNumEmbMIDIJack;
	uint8_t baAssocJackId;
	//more jacks can be added here
} sClassSpecificMIDIStreamingBulkDataEndpointDescriptor;

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
} sStandardMIDIStreamingTransferBulkDataEndpointDescriptor;
#endif
