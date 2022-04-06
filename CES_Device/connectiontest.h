#ifndef CONNECTIONTEST_H
#define CONNECTIONTEST_H

#include <QObject>
#include <QTimer>

class connectionTest: public QObject
{
    Q_OBJECT
public:
    connectionTest();
    //enum LR;
    //enum RE;
    QTimer *blink;

    void sendcheckConnection();
    void sendblink_modeLight();
    void senddisplayConnection(int);
    void sendsoftOn();
    void sendsoftOff();
    void sendclearDisplay();
    void sendwetEarLobes();
    int checkConnection(bool, bool, bool, bool);

signals:
    //void checkConnection();
    void blink_modeLight();
    void displayConnection(int);
    void softOn();
    void softOff();
    void clearDisplay();
    void wetEarLobes();
};

#endif // CONNECTIONTEST_H
