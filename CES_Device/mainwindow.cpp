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
    ui->oasispro_label->setPixmap(oasislogo.scaled(110, 190, Qt::KeepAspectRatio));
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
    connect(&connectionObject, SIGNAL(blink_modeLight()), this, SLOT(blink_modeLight()));
    connect(&connectionObject, SIGNAL(displayConnection(int)), this, SLOT(displayConnection(int)));
    connect(&connectionObject, SIGNAL(clearDisplay()), this, SLOT(clearDisplay()));
    connect(ui->select_button, SIGNAL(released()), this, SLOT(startTherapy()));
    connect(ui->up_button, SIGNAL(released()), this, SLOT(incIntensity()));
    connect(ui->down_button, SIGNAL(released()), this, SLOT(decIntensity()));
    connect(ui->setDuration_button, SIGNAL(released()), this, SLOT(setDuration()));
    connect(ui->setSession_button, SIGNAL(released()), this, SLOT(setSession()));
    connect(ui->replace_battery_button, SIGNAL(clicked(bool)), this, SLOT(replaceBattery()));
    //user-designated time combobox
    for(int i = 1; i<=180; i++){
        ui->userdes_comboBox->addItem(QString::number(i));
    }

    //signal slots for database
    DBManager db;
    QDate date;
    connect(ui->recordSessionButton, SIGNAL(clicked(bool)), this, SLOT(recordSession()));
    connect(ui->viewDatabaseButton, SIGNAL(clicked(bool)), this, SLOT(viewDatabase()));

    //Create Battery Instance
    deviceBattery = new battery();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::power_on()
{
    //Since the power button will be shared between power_on() and power_off(), we need to do a check
    if (state == "off") {
        //Switch the state to be on
        state = "on";
        //If no session is selected within 2 minutes, call the power_off() function
        powerOffTimer->start(200000);
        //Turn the power light on
        ui->power_light->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");

        //display the battery level
        displayBatteryLevel();

        //set default therapy settings
        ui->alpha_light->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        ui->delta_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->theta_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->hundredHz_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->twentymin_light->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        ui->fourtyfivemin_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->userdesignated_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    }
    //Now we can make the power_off() connection (to not interfere with calling power_on)
    connect(ui->power_button, SIGNAL(clicked(bool)), this, SLOT(endTherapy()));

}

void MainWindow::displayBatteryLevel()
{
    //Let the other functions controlling the GUI know that we are displaying the battery level
    displayingBattery = true;
    qDebug() << "Displaying battery level...";

    for (int i = 0; i <= deviceBattery->getBatteryLevel(); i++) {
        if (i >= 1 && i <= 199) {
            //Check if the battery level is critically low
            if (i == deviceBattery->getBatteryLevel()) {
                //Blink the battery level
                connect(batteryLow_blinkTimer, SIGNAL(timeout()), this, SLOT(lowBattery_blink()));
                batteryLow_blinkTimer->start(1000);
                continue;
            }
            //Synchronize with battery low
            if (deviceBattery->getBatteryLevel() >= 200 && deviceBattery->getBatteryLevel() <= 299) {
                continue;
            }
            //Battery level is not low
            ui->level_1->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        }
        else if (i >= 200 && i <= 299) {
            //Check if the battery level is low
            if (i == deviceBattery->getBatteryLevel()) {
                //Blink the battery level
                connect(batteryLow_blinkTimer, SIGNAL(timeout()), this, SLOT(lowBattery_blink()));
                batteryLow_blinkTimer->start(1000);
                continue;
            }
            //Battery level is not low
            ui->level_2->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        }
        //Change the rest of the battery level lights accordingly
        else if (i >= 300 && i <= 399) {
            ui->level_3->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        }
        else if (i >= 400 && i <= 499) {
            ui->level_4->setStyleSheet("QLabel { background-color: rgb(255, 178, 0); }");
        }
        else if (i >= 500 && i <= 599) {
            ui->level_5->setStyleSheet("QLabel { background-color: rgb(255, 178, 0); }");
        }
        else if (i >= 600 && i <= 699) {
            ui->level_6->setStyleSheet("QLabel { background-color: rgb(255, 178, 0); }");
        }
        else if (i >= 700 && i <= 799) {
            ui->level_7->setStyleSheet("QLabel { background-color: rgb(255, 173, 244); }");
        }
        else if (i == 800) {
            ui->level_8->setStyleSheet("QLabel { background-color: rgb(255, 173, 244); }");
        }
    }
    //Display the battery for 7 seconds, then call batteryDisplay_off()
    batteryLevelTimer->start(7000);
}

void MainWindow::batteryDisplay_off()
{
    qDebug() << "battery display off...";
    //disconnect(batteryLevelTimer, SIGNAL(timeout()), this, SLOT(batteryDisplay_off()));
    batteryLevelTimer->stop();
    for (int i = 1; i <= 800; i++) {
        if (i >= 1 && i <= 199) {
            //If battery is critically low
            if (i == deviceBattery->getBatteryLevel()) {
                //Turn off the blinking battery level
                batteryLow_blinkTimer->stop();
                disconnect(batteryLow_blinkTimer, SIGNAL(timeout()), this, SLOT(lowBattery_blink()));
            }
            ui->level_1->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
            //Let the functions controlling the GUI know we are not displaying battery level anymore
            displayingBattery = false;
        }
        else if (i >= 200 && i <= 299) {
            //If battery is low
            if (i == deviceBattery->getBatteryLevel()) {
                //Turn off the blinking battery level
                batteryLow_blinkTimer->stop();
                disconnect(batteryLow_blinkTimer, SIGNAL(timeout()), this, SLOT(lowBattery_blink()));
            }
            ui->level_2->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
            //Let the functions controlling the GUI know we are not displaying battery level anymore
            displayingBattery = false;
        }
        //Turn back the rest of the battery levels to just blank
        else if (i >= 300 && i <= 399) {
            ui->level_3->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        else if (i >= 400 && i <= 499) {
            ui->level_4->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        else if (i >= 500 && i <= 599) {
            ui->level_5->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        else if (i >= 600 && i <= 699) {
            ui->level_6->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        else if (i >= 700 && i <= 799) {
            ui->level_7->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        else if (i == 800) {
            ui->level_8->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
    }
}

void MainWindow::lowBattery_blink()
{
    //If the battery level is not on, turn it on
    if (lowBattery_blinkStatus == "off") {
        //Critically low
        if (deviceBattery->getBatteryLevel() >= 1 && deviceBattery->getBatteryLevel() <= 199) {
            ui->level_1->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        }
        //Low
        else if (deviceBattery->getBatteryLevel() >= 200 && deviceBattery->getBatteryLevel() <= 299) {
            ui->level_1->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
            ui->level_2->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        }
        //Turn the blink status to "on" so that it will turn it off next time around.
        lowBattery_blinkStatus = "on";
    }
    //If the battery level is on, turn it off. This will cause the blinking effect.
    else {
        //Critically low
        if (deviceBattery->getBatteryLevel() >= 1 && deviceBattery->getBatteryLevel() <= 199) {
            ui->level_1->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        //Low
        else if (deviceBattery->getBatteryLevel() >= 200 && deviceBattery->getBatteryLevel() <= 299) {
            ui->level_1->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
            ui->level_2->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        }
        //Turn the blink status to "off" so that it will turn it on the next time around.
        lowBattery_blinkStatus = "off";
    }
}

void MainWindow::power_off()
{
    //Turn the power light off
    if (state == "on") {
        state = "off";
        ui->power_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    }

    //set ongoing therapy to false
    ongoingTherapy = false;

    //Turn off soft on/soft off timers
    disconnect(softOnOffTimer, SIGNAL(timeout()), this, SLOT(displaySoftOn()));
    disconnect(softOnOffTimer, SIGNAL(timeout()), this, SLOT(displaySoftOff()));
    softOnOffTimer->stop();

    //If a session is currently ongoing, stop the session
    connect(sessionTimer, SIGNAL(timeout()), this, SLOT(endTherapy()));
    sessionTimer->stop();

    //Turn the battery display off
    batteryDisplay_off();

    //Turn off all the mode and session lights
    qDebug() << "powering off...";
    ui->alpha_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    ui->delta_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    ui->theta_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    ui->hundredHz_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    ui->twentymin_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    ui->fourtyfivemin_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
    ui->userdesignated_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");

    //disconnect this function with the power button so that it automatically calls power_on the next time the power button is clicked.
    //disconnect(ui->power_button, SIGNAL(clicked(bool)), this, SLOT(power_off()));
}

void MainWindow::replaceBattery()
{
    //Change the battery level back to 800 (maximum battery level)
    deviceBattery->replaceBattery();
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
    ui->level_1->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
    ui->level_2->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
    ui->level_3->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
    ui->level_4->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
    ui->level_5->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
    ui->level_6->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
    ui->level_7->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
    ui->level_8->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
    ui->label->setStyleSheet("QLabel { background-color: rgb(236, 236, 236); }");
}
void MainWindow::checkConnection(){
    qDebug() << "Check connection...";
    if (state == "on" && displayingBattery == false){
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
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateString = dateTime.toString("ddd MMMM d yyyy hh:mm");
    //build actual string
    QString log;
    log += dateString + " ";
    log += therapy->getTherapy();
    //write to database
    db.writeLog(log);
}

//read db
void MainWindow::viewDatabase()
{
    //just need to read the entire log
    QString entireLog;
    entireLog = db.readLog();
    ui->textEdit->append(entireLog);
}

void MainWindow::displaySoftOn()
{
    //Check if the power is off
    qDebug() << "display Soft on...";
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
        //begin session timer
        connect(sessionTimer, SIGNAL(timeout()), this, SLOT(endTherapy()));
        sessionTimer->start(getDuration()*1000); //minutes  = secs as msecs
        qInfo("start timer");
    }
}

void MainWindow::displaySoftOff()
{
    qDebug() << "display soft off...";
    if (softOnOffLevel == 1) {
        ui->level_1->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        disconnect(softOnOffTimer, SIGNAL(timeout()), this, SLOT(displaySoftOff()));
        softOnOffTimer->stop();
        //turn off device
        power_off();
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

int MainWindow::getDuration(){      //in minutes instead of enum
    switch (duration){
    case TWENTY:
        return 20;
    case FORTYFIVE:
        return 45;
    case CUSTOM:
        return ui->userdes_comboBox->currentText().toInt();
    default:
        return 0;
    }
}

void MainWindow::setDuration(){
    if(state == "off") return;
    //go to next session
    duration = (duration+1)%3;
    //update light
    switch (duration){
    case TWENTY:
        ui->twentymin_light->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        ui->fourtyfivemin_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->userdesignated_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        break;
    case FORTYFIVE:
        ui->twentymin_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->fourtyfivemin_light->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        ui->userdesignated_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        break;
    case CUSTOM:
        ui->twentymin_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->fourtyfivemin_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->userdesignated_light->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        break;
    }
}

void MainWindow::setSession(){
    if(state == "off") return;
    //go to next session
    session = (session+1)%4;
    //update light
    switch (session){
    case ALPHA:
        ui->alpha_light->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        ui->theta_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->delta_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->hundredHz_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        break;
    case THETA:
        ui->alpha_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->theta_light->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        ui->delta_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->hundredHz_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        break;
    case DELTA:
        ui->alpha_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->theta_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->delta_light->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        ui->hundredHz_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        break;
    case HZ:
        ui->alpha_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->theta_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->delta_light->setStyleSheet("QLabel { background-color: rgb(255, 255, 255); }");
        ui->hundredHz_light->setStyleSheet("QLabel { background-color: rgb(144, 238, 144); }");
        break;
    }
}

void MainWindow::startTherapy(){
    if(state == "off" || ongoingTherapy == true || displayingBattery == true) return;

    //connection test
    if(connectionObject.checkConnection(ui->checkBox->isChecked(), ui->checkBox_2->isChecked(), ui->checkBox_3->isChecked(), ui->checkBox_4->isChecked()) == 4){
        connectionObject.senddisplayConnection(4);
        connectionObject.sendblink_modeLight();
        delay();
        connectionObject.stopTimer();
        connectionObject.sendclearDisplay();
        return;
    }
    checkConnection();
    connectionObject.sendblink_modeLight();
    delay();
    connectionObject.stopTimer();
    connectionObject.sendclearDisplay();

    //create therapy
    ongoingTherapy = true;
    therapy = new Therapy((Session)session, getDuration());
    qDebug() << therapy->getTherapy();

    //Drain the battery accordingly
    deviceBattery->drainBattery(therapy->getSession(), getDuration());

    //Soft on
    connect(softOnOffTimer, SIGNAL(timeout()), this, SLOT(displaySoftOn()));
    softOnOffTimer->start(SOFT_TIME);

    //enable record button
    //only allow user to record therapy once a therapy has started
    //if not, attempting to record a session when 'therapy' variable is uninitialized will shut system down
    ui->recordSessionButton->setEnabled(true);
}

void MainWindow::endTherapy(){
    //needed so that if power button pressed during softon, softonprocess will end immediately
    disconnect(softOnOffTimer, SIGNAL(timeout()), this, SLOT(displaySoftOn()));
    softOnOffTimer->stop();

    //end session timer
    disconnect(sessionTimer, SIGNAL(timeout()), this, SLOT(endTherapy()));
    sessionTimer->stop();
    qInfo("end timer");

    //Soft Off
    connect(softOnOffTimer, SIGNAL(timeout()), this, SLOT(displaySoftOff()));
    softOnOffTimer->start(SOFT_TIME);

    //reset settings
    ongoingTherapy = false;
    session = 0;
    duration = 0;

    //disconnect this function with the power button so that it automatically calls power_on the next time the power button is clicked.
    disconnect(ui->power_button, SIGNAL(clicked(bool)), this, SLOT(endTherapy()));

    //diable record button
    //only allow user to record therapy once a therapy has started
    //if not, attempting to record a session when 'therapy' variable is uninitialized will shut system down
    ui->recordSessionButton->setEnabled(false);
}

void MainWindow::incIntensity(){
   if(therapy) therapy->incIntensity();
}

void MainWindow::decIntensity(){
    if(therapy) therapy->decIntensity();
}

void MainWindow::delay(){
    QTime dieTime= QTime::currentTime().addSecs(3);
    while(QTime::currentTime() < dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}
