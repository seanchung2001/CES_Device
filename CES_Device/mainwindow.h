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

    QTimer *batteryLevelTimer;
    QTimer *powerOffTimer;

    QString state = "off";
    bool firstCommand;
    connectionTest thingsIDK;

private slots:
    void power_on();
    void displayBatteryLevel();
    void batteryDisplay_off();
    void power_off();

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
