#ifndef BATTERY_H
#define BATTERY_H


class battery
{
public:
    battery();
    //void drainBattery(); TODO
    void replaceBattery();
    int getBatteryLevel();

private:
    int batteryLevel;

};

#endif // BATTERY_H
