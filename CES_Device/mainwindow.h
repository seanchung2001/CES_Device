#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPixmap>
#include <QTimer>
#include "connectiontest.h"
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

    QTimer *batteryLevelTimer;
    QTimer *powerOffTimer;

    QString state = "off";
    bool firstCommand;
    connectionTest connectionObject;
    int alternatingNum = 0;
    //dbmanager
    QDate date;
    DBManager db;


private slots:
    void power_on();
    void displayBatteryLevel();
    void batteryDisplay_off();
    void power_off();

    void blink_modeLight(); // used
    void displayConnection(int); // used
    void softOn(); // need to talk with Erica
    void softOff(); // need to talk with Erica
    void clearDisplay(); // used but do we need this?
    void wetEarLobes(); // do we need this?
    void checkConnection(); // used
    //dbmanager
    void recordSession();
    void viewDatabase();


};
#endif // MAINWINDOW_H
