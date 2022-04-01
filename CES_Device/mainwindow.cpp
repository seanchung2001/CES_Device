#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //UI stuff for Importing pictures from the browser
    ui->setupUi(this);
    QPixmap alpha(":/labels/labels/alpha.png");
    ui->alpha_label->setPixmap(alpha.scaled(18, 18, Qt::KeepAspectRatio));
    QPixmap theta(":/labels/labels/theta.png");
    ui->theta_label->setPixmap(theta.scaled(20, 20, Qt::KeepAspectRatio));
    QPixmap delta(":/labels/labels/delta.png");
    ui->delta_label->setPixmap(delta.scaled(20, 20, Qt::KeepAspectRatio));
    QPixmap hundredHertz(":/labels/labels/100hz.svg");
    ui->hundredHertz_label->setPixmap(hundredHertz.scaled(30, 30, Qt::KeepAspectRatio));
    QPixmap twentymin(":/labels/labels/twentymin.png");
    ui->twentymin_label->setPixmap(twentymin.scaled(20, 20, Qt::KeepAspectRatio));
    QPixmap fourtyfive(":/labels/labels/fourtyfive.png");
    ui->fourtyfive_label->setPixmap(fourtyfive.scaled(20, 20, Qt::KeepAspectRatio));
    QPixmap user_designated(":/labels/labels/userdesignated.png");
    ui->userdesignated_label->setPixmap(user_designated.scaled(30, 30, Qt::KeepAspectRatio));
    QPixmap oasislogo(":/labels/labels/oasislogo.png");
    ui->oasispro_label->setPixmap(oasislogo.scaled(90, 170, Qt::KeepAspectRatio));
    QPixmap topleft(":/labels/labels/topleftlogo.png");
    ui->topleft_label->setPixmap(topleft.scaled(20, 20, Qt::KeepAspectRatio));
    QPixmap bottomleft(":/labels/labels/bottomleftlogo.png");
    ui->bottomleft_label->setPixmap(bottomleft.scaled(30, 30, Qt::KeepAspectRatio));

    //QTimer
    batteryLevelTimer = new QTimer();
    powerOffTimer = new QTimer();

    //SIGNAL-SLOT
    connect(ui->power_button, SIGNAL(clicked(bool)), this, SLOT(power_on()));
    connect(batteryLevelTimer, SIGNAL(timeout()), this, SLOT(batteryDisplay_off()));
    connect(powerOffTimer, SIGNAL(timeout()), this, SLOT(power_off()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::power_on()
{
    if (state == "off") {
        state = "on";
        powerOffTimer->start(200000);
        ui->power_light->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        displayBatteryLevel();
    }
    connect(ui->power_button, SIGNAL(clicked(bool)), this, SLOT(power_off()));
}

void MainWindow::displayBatteryLevel()
{
    int tmpBatterylevel = 8;
    for (int i = 1; i <= tmpBatterylevel; i++) {
        if (i == 2) {
            ui->level_2->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        }
        else if (i == 3) {
            ui->level_3->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        }
        else if (i == 4) {
            ui->level_4->setStyleSheet("QLabel { background-color: rgb(255, 178, 0); }");
        }
        else if (i == 5) {
            ui->level_5->setStyleSheet("QLabel { background-color: rgb(255, 178, 0); }");
        }
        else if (i == 6) {
            ui->level_6->setStyleSheet("QLabel { background-color: rgb(255, 178, 0); }");
        }
        else if (i == 7) {
            ui->level_7->setStyleSheet("QLabel { background-color: rgb(255, 173, 244); }");
        }
        else if (i == 8) {
            ui->level_8->setStyleSheet("QLabel { background-color: rgb(255, 173, 244); }");
        }
    }
    batteryLevelTimer->start(7000);
}

void MainWindow::batteryDisplay_off()
{
    for (int i = 1; i <= 8; i++) {
        if (i == 2) {
            ui->level_2->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        else if (i == 3) {
            ui->level_3->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        else if (i == 4) {
            ui->level_4->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        else if (i == 5) {
            ui->level_5->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        else if (i == 6) {
            ui->level_6->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        else if (i == 7) {
            ui->level_7->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        else if (i == 8) {
            ui->level_8->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
    }
}

void MainWindow::power_off()
{
    if (state == "on") {
        state = "off";
        ui->power_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    }
    batteryDisplay_off();
    disconnect(ui->power_button, SIGNAL(clicked(bool)), this, SLOT(power_off()));
}

