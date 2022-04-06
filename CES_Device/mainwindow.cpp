#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <unistd.h>

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
    batteryLow_blinkTimer = new QTimer();
    sessionTimer = new QTimer();
    softOnOffTimer = new QTimer();

    //SIGNAL-SLOT
    connect(ui->power_button, SIGNAL(clicked(bool)), this, SLOT(power_on()));
    connect(batteryLevelTimer, SIGNAL(timeout()), this, SLOT(batteryDisplay_off()));
    connect(powerOffTimer, SIGNAL(timeout()), this, SLOT(power_off()));
    connect(ui->connectionButton, SIGNAL(clicked(bool)), this, SLOT(checkConnection()));
    connect(&connectionObject, SIGNAL(blink_modeLight()), this, SLOT(blink_modeLight()));
    connect(&connectionObject, SIGNAL(displayConnection(int)), this, SLOT(displayConnection(int)));
    connect(&connectionObject, SIGNAL(clearDisplay()), this, SLOT(clearDisplay()));
    connect(ui->select_button, SIGNAL(released()), this, SLOT(startSession()));
    connect(ui->up_button, SIGNAL(released()), this, SLOT(incIntensity()));
    connect(ui->down_button, SIGNAL(released()), this, SLOT(decIntensity()));
    connect(sessionTimer, SIGNAL(timeout()), this, SLOT(endSession()));

    //signal slots for database
    DBManager db;
    QDate date;
    connect(ui->recordSessionButton, SIGNAL(clicked(bool)), this, SLOT(recordSession()));
    connect(ui->viewDatabaseButton, SIGNAL(clicked(bool)), this, SLOT(viewDatabase()));

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
    int tmpBatterylevel = 2;
    for (int i = 1; i <= tmpBatterylevel; i++) {
        if (i == 1) {
            if (i == tmpBatterylevel) {
                connect(batteryLow_blinkTimer, SIGNAL(timeout()), this, SLOT(lowBattery_blink()));
                batteryLow_blinkTimer->start(1000);
                continue;
            }
            if (tmpBatterylevel != 2) {
                ui->level_1->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
            }
        }
        else if (i == 2) {
            if (i == tmpBatterylevel) {
                connect(batteryLow_blinkTimer, SIGNAL(timeout()), this, SLOT(lowBattery_blink()));
                batteryLow_blinkTimer->start(1000);
                continue;
            }
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
    int tmpBatteryLevel = 1;
    for (int i = 1; i <= 8; i++) {
        if (i == 1) {
            if (i == tmpBatteryLevel) {
                batteryLow_blinkTimer->stop();
                disconnect(batteryLow_blinkTimer, SIGNAL(timeout()), this, SLOT(lowBattery_blink()));
            }
            ui->level_1->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        else if (i == 2) {
            if (i == tmpBatteryLevel) {
                batteryLow_blinkTimer->stop();
                disconnect(batteryLow_blinkTimer, SIGNAL(timeout()), this, SLOT(lowBattery_blink()));
            }
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

void MainWindow::lowBattery_blink()
{
    int tmpBatteryLevel = 1;
    if (lowBattery_blinkStatus == "off") {
        if (tmpBatteryLevel == 1) {
            ui->level_1->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        }
        else if (tmpBatteryLevel == 2) {
            ui->level_1->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
            ui->level_2->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        }
        lowBattery_blinkStatus = "on";
    }
    else {
        if (tmpBatteryLevel == 1) {
            ui->level_1->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        else if (tmpBatteryLevel == 2) {
            ui->level_1->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
            ui->level_2->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        lowBattery_blinkStatus = "off";
    }
}

void MainWindow::power_off()
{
    if (state == "on") {
        state = "off";
        ui->power_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    }
    //Turn the battery display off
    batteryDisplay_off();

    //Turn off all the mode and session lights
    ui->alpha_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    ui->delta_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    ui->theta_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    ui->hundredHz_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    ui->twentymin_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    ui->fourtyfivemin_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    ui->userdesignated_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");

    disconnect(ui->power_button, SIGNAL(clicked(bool)), this, SLOT(power_off()));
}

void MainWindow::blink_modeLight(){
     if (alternatingNum == 0){
         ui->label->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
         alternatingNum = 1;
     }else{
         ui->label->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
         alternatingNum = 0;
     }
}
void MainWindow::displayConnection(int x){
    if (x == 0){
        ui->textEdit->append("EXCELLENT CONNECTION");
        ui->level_1->setStyleSheet("QLabel { background-color: rgb(0, 255, 0); }");
        ui->level_2->setStyleSheet("QLabel { background-color: rgb(0, 255, 0); }");
        ui->level_3->setStyleSheet("QLabel { background-color: rgb(0, 255, 0); }");
    } else if (x == 1){
        ui->textEdit->append("OK CONNECTION - CONSIDER APPLYING MOISTURE TO THE RIGHT EARLOBE");
        ui->level_4->setStyleSheet("QLabel { background-color: rgb(255, 255, 0); }");
        ui->level_5->setStyleSheet("QLabel { background-color: rgb(255, 255, 0); }");
        ui->level_6->setStyleSheet("QLabel { background-color: rgb(255, 255, 0); }");
    }else if (x == 2){
        ui->textEdit->append("OK CONNECTION - CONSIDER APPLYING MOISTURE TO THE LEFT EARLOBE");
        ui->level_4->setStyleSheet("QLabel { background-color: rgb(255, 255, 0); }");
        ui->level_5->setStyleSheet("QLabel { background-color: rgb(255, 255, 0); }");
        ui->level_6->setStyleSheet("QLabel { background-color: rgb(255, 255, 0); }");
    }else if (x == 3){
        ui->textEdit->append("OK CONNECTION - CONSIDER APPLYING MOISTURE TO BOTH EARLOBES");
        ui->level_4->setStyleSheet("QLabel { background-color: rgb(255, 255, 0); }");
        ui->level_5->setStyleSheet("QLabel { background-color: rgb(255, 255, 0); }");
        ui->level_6->setStyleSheet("QLabel { background-color: rgb(255, 255, 0); }");
    }else{
        ui->textEdit->append("NO CONNECTION");
        ui->level_7->setStyleSheet("QLabel { background-color: rgb(255, 0, 0); }");
        ui->level_8->setStyleSheet("QLabel { background-color: rgb(255, 0, 0); }");
    }
}

void MainWindow::clearDisplay(){
    ui->textEdit->clear();
}
void MainWindow::checkConnection(){
    if (state == "on"){
        ui->level_1->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
        ui->level_2->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
        ui->level_3->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
        ui->level_4->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
        ui->level_5->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
        ui->level_6->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
        ui->level_7->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
        ui->level_8->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");

        connectionObject.sendclearDisplay();
        connectionObject.sendblink_modeLight();
        connectionObject.senddisplayConnection(connectionObject.checkConnection(ui->checkBox->isChecked(), ui->checkBox_2->isChecked(), ui->checkBox_3->isChecked(), ui->checkBox_4->isChecked()));
    }

}


//write to db
void MainWindow::recordSession()
{
    //get date
    date = QDate::currentDate();
    QString dateString = date.toString("ddd MMMM d yyyy");
    //need to get session data as well (not completed yet)
    //build actual string
    QString log;
    log += dateString;
    log += " temporary session data";
    //write to database
    db.writeLog(log.toStdString());
}

//read db
void MainWindow::viewDatabase()
{
    //just need to read the entire log
    string entireLog;
    entireLog = db.readLog();
    ui->textEdit->append(QString::fromStdString(entireLog));
}

void MainWindow::displaySoftOn()
{
    if (softOnOffLevel == 1) {
        ui->level_1->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        softOnOffLevel++;
    }
    else if (softOnOffLevel == 2) {
        ui->level_2->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        softOnOffLevel++;
    }
    else if (softOnOffLevel == 3) {
        ui->level_3->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        softOnOffLevel++;
    }
    else if (softOnOffLevel == 4) {
        ui->level_4->setStyleSheet("QLabel { background-color: rgb(255, 178, 0); }");
        softOnOffLevel++;
    }
    else if (softOnOffLevel == 5) {
        ui->level_5->setStyleSheet("QLabel { background-color: rgb(255, 178, 0); }");
        softOnOffLevel++;
    }
    else if (softOnOffLevel == 6) {
        ui->level_6->setStyleSheet("QLabel { background-color: rgb(255, 178, 0); }");
        softOnOffLevel++;
    }
    else if (softOnOffLevel == 7) {
        ui->level_7->setStyleSheet("QLabel { background-color: rgb(255, 173, 244); }");
        softOnOffLevel++;
    }
    else if (softOnOffLevel == 8) {
        ui->level_8->setStyleSheet("QLabel { background-color: rgb(255, 173, 244); }");
        disconnect(softOnOffTimer, SIGNAL(timeout()), this, SLOT(displaySoftOn()));
        softOnOffTimer->stop();
    }
}

void MainWindow::displaySoftOff()
{
    if (softOnOffLevel == 1) {
        ui->level_1->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        disconnect(softOnOffTimer, SIGNAL(timeout()), this, SLOT(displaySoftOff()));
        softOnOffTimer->stop();
    }
    else if (softOnOffLevel == 2) {
        ui->level_2->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        softOnOffLevel--;
    }
    else if (softOnOffLevel == 3) {
        ui->level_3->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        softOnOffLevel--;
    }
    else if (softOnOffLevel == 4) {
        ui->level_4->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        softOnOffLevel--;
    }
    else if (softOnOffLevel == 5) {
        ui->level_5->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        softOnOffLevel--;
    }
    else if (softOnOffLevel == 6) {
        ui->level_6->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        softOnOffLevel--;
    }
    else if (softOnOffLevel == 7) {
        ui->level_7->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        softOnOffLevel--;
    }
    else if (softOnOffLevel == 8) {
        ui->level_8->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        softOnOffLevel--;
    }
}

void MainWindow::startSession(){
    //get group/time
    //get session number
    //create therapy
    //start session
    therapy = new Therapy(ALPHA, 3);

    //Soft on
    therapy->softOn();
    connect(softOnOffTimer, SIGNAL(timeout()), this, SLOT(displaySoftOn()));
    softOnOffTimer->start(1000);

    qInfo("start timer");
    //This will be filled in with the actual session time
    sessionTimer->start(11000);
}

void MainWindow::endSession(){
    //Soft Off
    therapy->softOff();
    connect(softOnOffTimer, SIGNAL(timeout()), this, SLOT(displaySoftOff()));
    softOnOffTimer->start(1000);
    sessionTimer->stop();
}

void MainWindow::incIntensity(){
    therapy->incIntensity();
}

void MainWindow::decIntensity(){
    therapy->decIntensity();
}
