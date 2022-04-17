#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPixmap>
#include <QTimer>
#include "connectiontest.h"
#include "therapy.h"
#include "session.h"
#include "duration.h"
#include "battery.h"

//dbmanager
#include "DBManager.h"
#include <QString>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //Timers
    QTimer *batteryLevelTimer;
    QTimer *powerOffTimer;
    QTimer *batteryLow_blinkTimer;
    QTimer *sessionTimer;
    QTimer *softOnOffTimer = new QTimer();
    QTimer *intensityTimer = new QTimer();

    QString state = "off";
    QString lowBattery_blinkStatus = "off";
    connectionTest connectionObject;
    int alternatingNum = 0;

    //Therapy
    Therapy* therapy = NULL;
    int session = 0;
    int duration = 0;
    int softOnOffLevel = 1;
    bool ongoingTherapy = false;

    //dbmanager
    QDateTime dateTime;
    DBManager db;

    //Battery
    battery *deviceBattery;
    bool displayingBattery = false;

    //Delay function
    void delay();

private slots:
    //Sean's functions
    void power_on();
    void displayBatteryLevel();
    void batteryDisplay_off();
    void lowBattery_blink();
    void power_off();
    void replaceBattery();

    //Israels Functions
    void blink_modeLight();
    void displayConnection(int);
    void clearDisplay();
    void checkConnection();

    //Erica's functions
    int getDuration();
    void setDuration();
    void setSession();
    void startTherapy();
    void endTherapy();
    void incIntensity();
    void decIntensity();
    void displaySoftOn();
    void displaySoftOff();
    void blinkOnIntensity();
    void blinkOffIntensity();

    //dbmanager
    void recordSession();
    void viewDatabase();


};
#endif // MAINWINDOW_H
