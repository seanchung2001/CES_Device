#include "battery.h"

battery::battery()
{
    //Max battery level
    batteryLevel = 800;
}

void battery::drainBattery(Session sessionType, int dur)
{
    int multiplier;
    if (sessionType == DELTA) {
        multiplier = 1;
    }
    else if (sessionType == THETA) {
        multiplier = 2;
    }
    else if (sessionType == ALPHA) {
        multiplier = 3;
    }
    else if (sessionType == HZ) {
        multiplier = 10;
    }

    if (dur > 300000) {
        //Max duration
        dur = 80;
        qDebug() << "Max time limit is 3 hours";
    }
    batteryLevel -= multiplier * dur;
    qDebug() << "duration: " << dur;
}

void battery::replaceBattery()
{
    batteryLevel = 800;
    qDebug() << "Battery level: " << batteryLevel;
}

int battery::getBatteryLevel()
{
    return batteryLevel;
}
