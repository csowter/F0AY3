#ifndef usbstructures_h
#define usbstructures_h

#include <stdint.h>
namespace USBStructures
{
__packed struct SetupPacket
{
    uint8_t bmRequestType;
    uint8_t bRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;
};

static_assert(sizeof(SetupPacket) == 8, "sizeof(SetupPacket) is wrong");
}

enum class DeviceState
{
	Attached,
	Powered,
	Default,
	Address,
	Configured,
	Suspended
};

#endif
