#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPixmap>
#include <QTimer>

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

private slots:
    void power_on();
    void displayBatteryLevel();
    void batteryDisplay_off();
    void power_off();
};
#endif // MAINWINDOW_H
