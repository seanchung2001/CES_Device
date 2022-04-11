#include "battery.h"

battery::battery()
{
    //Max battery level
    batteryLevel = 800;
}

void battery::drainBattery(Session sessionType, int dur)
{
    int multiplier;
    //Delta uses the least amount of hz. The multiplier will be the smallest of the 4 sessions.
    if (sessionType == DELTA) {
        multiplier = 1;
    }
    //Theta uses the second least amount of hz. The multiplier will be the second smallest of the 4 sessions.
    else if (sessionType == THETA) {
        multiplier = 2;
    }
    //Alpha uses the second most amount of hz. The multiplier will be the second largest of the 4 sessions.
    else if (sessionType == ALPHA) {
        multiplier = 3;
    }
    //100hz uses the most amount of hz by a significant amount. The multiplier will be significantly larger.
    else if (sessionType == HZ) {
        multiplier = 10;
    }

    if (dur > 180) {
        //Max duration
        dur = 180;
        qDebug() << "Max time limit is 3 hours";
    }
    //Drain the battery
    batteryLevel -= multiplier * dur;

    //Check if the battery level is negative
    if (batteryLevel < 0) {
        batteryLevel = 0;
    }
    qDebug() << "batteryLevel: " << batteryLevel;
}

void battery::replaceBattery()
{
    //Change the batteryLevel to be the maximum battery level (800)
    batteryLevel = 800;
    qDebug() << "Battery level: " << batteryLevel;
}

int battery::getBatteryLevel()
{
    return batteryLevel;
}
