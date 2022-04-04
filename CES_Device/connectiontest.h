#ifndef CONNECTIONTEST_H
#define CONNECTIONTEST_H

#include <QObject>

class connectionTest: public QObject
{
    Q_OBJECT
public:
    connectionTest();
    //enum LR;
    //enum RE;

    void sendcheckConnection();
    void sendblink_modeLight();
    void senddisplayConnection();
    void sendsoftOn();
    void sendsoftOff();
    void sendclearDisplay();
    void sendwetEarLobes();
signals:
    void checkConnection();
    void blink_modeLight();
    void displayConnection();
    void softOn();
    void softOff();
    void clearDisplay();
    void wetEarLobes();
};

#endif // CONNECTIONTEST_H
