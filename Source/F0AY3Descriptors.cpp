#include "F0AY3Descriptors.h"

const sStandardDeviceDescriptor AY3Descriptors::DeviceDescriptor = 
{
	0x12, //uint8_t bLength;
	DescriptorType::Device, //uint8_t bDescriptorType;
	0x0110, //uint16_t bcdUSB;
	0x00, //uint8_t bDeviceClass;
	0x00, //uint8_t bDeviceSubClass;
	0x00, //uint8_t bDeviceProtocol;
	0x08, //uint8_t bMaxPacketSize0;
	0x4568, //uint16_t idVendor;
	0x0002, //uint16_t idProduct;
	0x0100, //uint16_t bcdDevice;
	0x01,//uint8_t iManufacturer;
	0x02,//uint8_t iProduct;
	0x0,//uint8_t iSerialNumber;
	0x01//uint8_t bNumConfigurations;
};

const AY3Descriptors::sConfigurationDescriptor AY3Descriptors::ConfigurationDescriptor = 
{
	{ //Standard Configuration descriptor
		0x09, //uint8_t bLength;
		DescriptorType::Configuration, //uint8_t bDescriptorType;
		sizeof(AY3Descriptors::sConfigurationDescriptor), //uint16_t wTotalLength;
		0x02, //uint8_t bNumInterfaces;
		0x01, //uint8_t bConfigurationValue;
		0x00, //uint8_t iConfiguration;
		0x80, //uint8_t bmAttributes;
		0x64, //uint8_t bMaxPower;
	},
	{ //standard ac interface descriptor
		0x09, //uint8_t bLength;
		DescriptorType::Interface, //uint8_t bDescriptorType;
		0x00, //uint8_t bInterfaceNumber;
		0x00, //uint8_t bAlternateSetting;
		0x00, //uint8_t bNumEndpoints;
		0x01, //uint8_t bInterfaceClass;
		0x01, //uint8_t bInterfaceSubClass;
		0x00, //uint8_t bInterfaceProtocol;
		0x00//uint8_t iInterface;
	},
	{ //class specific ac interface descriptor
		0x09, //uint8_t bLength;
		0x24, //uint8_t bDescriptorType;
		0x01, //uint8_t bDescriptorSubtype;
		0x0100, //uint16_t bcdADC;
		0x0009, //uint16_t wTotalLength;
		0x01, //uint8_t bInCollection;
		0x01 //uint8_t baInterfaceNr;
	},
	{ // sStandardMIDIStreamingInterfaceDescriptor
		0x09, //uint8_t bLength;
		0x04, //uint8_t bDescriptorType;
		0x01, //uint8_t bInterfaceNumber;
		0x00, //uint8_t bAlternateSetting;
		0x02, //uint8_t bNumEndpoints;
		0x01, //uint8_t bInterfaceClass;
		0x03, //uint8_t bInterfaceSubClass;
		0x00, //uint8_t bInterfaceProtocol;
		0x00, //uint8_t iInterface;
	},
	{ //sClassSpecificMIDIStreamingInterfaceDescriptor
		0x07, //uint8_t bLength;
		0x24, //uint8_t bDescriptorType;
		0x01, //uint8_t bDescriptorSubtype;
		0x0100, //uint16_t bcdMSC;
		0x0041 //uint16_t wTotalLength;
	},
	{ //sMIDIInJackDescriptor
		0x06, //uint8_t bLength;
		0x24, //uint8_t bDescriptorType;
		0x02, //uint8_t bDescriptorSubtype;
		0x01, //uint8_t bJackType;
		0x01, //uint8_t bJackID;
		0x00 //uint8_t iJack;
	},
	{ //sMIDIInJackDescriptor
		0x06, //uint8_t bLength;
		0x24, //uint8_t bDescriptorType;
		0x02, //uint8_t bDescriptorSubtype;
		0x02, //uint8_t bJackType;
		0x02, //uint8_t bJackID;
		0x00//uint8_t iJack;
	},
	{ //sMIDIOutJackDescriptor
		0x09, // uint8_t bLength;
		0x24, // uint8_t bDescriptorType;
		0x03, // uint8_t bDescriptorSubtype;
		0x01, // uint8_t bJackType;
		0x03, // uint8_t bJackID;
		0x01, // uint8_t bNrInputPins;
		0x02, // uint8_t baSourceID;
		0x01, // uint8_t baSourcePin;
		0x00// uint8_t iJack;	
	},
	{ //sMIDIOutJackDescriptor
		0x09, // uint8_t bLength;
		0x24, // uint8_t bDescriptorType;
		0x03, // uint8_t bDescriptorSubtype;
		0x02, // uint8_t bJackType;
		0x04, // uint8_t bJackID;
		0x01, // uint8_t bNrInputPins;
		0x01,// uint8_t baSourceID;
		0x01,// uint8_t baSourcePin;
		0x00// uint8_t iJack;	
	},
	{ //sStandardMIDIStreamingBulkDataEndpointDescriptor
		0x09, //uint8_t bLength;
		0x05, //uint8_t bDescriptorType;
		0x01, //uint8_t bEndpointAddress;
		0x02, //uint8_t bmAttributes;
		0x0040, //uint16_t wMaxPacketSize;
		0x00, //uint8_t bInterval;
		0x00, //uint8_t bRefresh;
		0x00//uint8_t bSynchAddress;
	},
	{ //sClassSpecificMIDIStreamingBulkDataEndpointDescriptor
		0x05, //uint8_t bLength;
		0x25, //uint8_t bDescriptorType;
		0x01, //uint8_t bDescriptorSubtype;
		0x01, //uint8_t bNumEmbMIDIJack;
		0x01 //uint8_t baAssocJackId;
	},
	{ //sStandardMIDIStreamingBulkDataEndpointDescriptor
		0x09, //uint8_t bLength;
		0x05, //uint8_t bDescriptorType;
		0x81, //uint8_t bEndpointAddress;
		0x02, //uint8_t bmAttributes;
		0x0040, //uint16_t wMaxPacketSize;
		0x00, //uint8_t bInterval;
		0x00, //uint8_t bRefresh;
		0x00//uint8_t bSynchAddress;
	},
	{//sClassSpecificMIDIStreamingBulkDataEndpointDescriptor
		0x05, //uint8_t bLength;
		0x25, //uint8_t bDescriptorType;
		0x01, //uint8_t bDescriptorSubtype;
		0x01, //uint8_t bNumEmbMIDIJack;
		0x03 //uint8_t baAssocJackId;
	}
};
