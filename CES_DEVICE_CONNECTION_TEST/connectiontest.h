#ifndef CONNECTIONTEST_H
#define CONNECTIONTEST_H
#include <iostream>
#include <QObject>
#include <QTimer>

class ConnectionTest: public QObject
{
    Q_OBJECT
public:
    ConnectionTest();
    //enum LR;
    //enum RE;

    int checkConnetion();

    void blink_modeLight();
    void displayConnection();
    void softOn();
    void softOff();
    void clearDisplay();
    void wetEarLobes();


    void test();
};

#endif // CONNECTIONTEST_H
