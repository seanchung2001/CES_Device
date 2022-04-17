#ifndef BATTERY_H
#define BATTERY_H

#include "session.h"
#include "therapy.h"
#include <QDebug>

class battery
{
public:
    battery();
    void drainBattery(Session, int);
    void replaceBattery();
    int getBatteryLevel();

private:
    int batteryLevel;

};

#endif // BATTERY_H
