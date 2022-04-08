#include "battery.h"

battery::battery()
{
    //Max battery level
    batteryLevel = 8;
}

void battery::replaceBattery()
{
    batteryLevel = 8;
}

int battery::getBatteryLevel()
{
    return batteryLevel;
}
