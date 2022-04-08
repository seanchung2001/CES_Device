#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPixmap>
#include <QTimer>
#include "connectiontest.h"
#include "therapy.h"
#include "session.h"
#include "battery.h"

//dbmanager
#include "DBManager.h"
#include <QString>
#include <string>
#include <QDate>

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

    QString state = "off";
    QString lowBattery_blinkStatus = "off";
    connectionTest connectionObject;
    int alternatingNum = 0;

    //Therapy
    Therapy* therapy = NULL;
    int session;
    int duration;
    int softOnOffLevel = 1;

    //dbmanager
    QDate date;
    DBManager db;

    //Battery
    battery *deviceBattery;
    bool displayingBattery = false;

private slots:
    //Sean's functions
    void power_on();
    void displayBatteryLevel();
    void batteryDisplay_off();
    void lowBattery_blink();
    void power_off();

    //Israels Functions
    void blink_modeLight();
    void displayConnection(int);
    void clearDisplay();
    void checkConnection();

    //Erica's functions
    void startSession();
    void endSession();
    void incIntensity();
    void decIntensity();
    void displaySoftOn();
    void displaySoftOff();

    //dbmanager
    void recordSession();
    void viewDatabase();


};
#endif // MAINWINDOW_H
