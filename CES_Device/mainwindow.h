#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPixmap>
#include <QTimer>
#include "connectiontest.h"

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
    QTimer *doNothingTimer;

    QString state = "off";
    QString lowBattery_blinkStatus = "off";
    bool firstCommand;
    connectionTest thingsIDK;

private slots:
    //Sean's functions
    void power_on();
    void displayBatteryLevel();
    void batteryDisplay_off();
    void lowBattery_blink();
    void doNothing();
    void power_off();

    //Israels Functions
    void blink_modeLight();
    void displayConnection();
    void softOn();
    void softOff();
    void clearDisplay();
    void wetEarLobes();
    void connectionThing();
    void connectionThing2();


};
#endif // MAINWINDOW_H
