#ifndef CONNECTIONTEST_H
#define CONNECTIONTEST_H

#include <QObject>
#include <QTimer>

class connectionTest: public QObject
{
    Q_OBJECT
public:
    connectionTest();
    QTimer *blink; //The Timer object

    //Functions for sending signals
    void sendcheckConnection();
    void sendblink_modeLight();
    void senddisplayConnection(int);
    void sendclearDisplay();
    int checkConnection(bool, bool, bool, bool);
    void stopTimer();

    //The signals
signals:
    void blink_modeLight();
    void displayConnection(int);
    void clearDisplay();
};

#endif // CONNECTIONTEST_H
