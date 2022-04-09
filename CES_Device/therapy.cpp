#include "therapy.h"
#include <unistd.h>
#include <QDebug>

#define MAX_INTENSITY 8
#define DEFAULT_INTENSITY 4


Therapy::Therapy(Session s, int d)
    :session(s), duration(d)
{
    intensity = DEFAULT_INTENSITY;
}

QString Therapy::getTherapy(){
    QString message;
    switch (session){
    case ALPHA:
       message = "Alpha";
       break;
    case THETA:
        message = "Theta";
        break;
    case DELTA:
        message = "Delta";
        break;
    case HZ:
        message = "100 Hz";
        break;
    }

    return message + " session at " + QString::number(this->intensity) + " intensity for " + QString::number(this->duration) + " minutes";
}

void Therapy::startSession(){
//    //check if connection test is passed
//    softOn();
//    qInfo("starting therapy");

//    for (int i = 0; i < duration; i++){
//        //sleep(1); //1 min in real time = 1 sec in simulation
//        qInfo("hello");
//    }
//    softOff();
}

void Therapy::endSession(){
//    //check if connection test is passed
//    softOn();
//    qInfo("starting therapy");

//    for (int i = 0; i < duration; i++){
//        //sleep(1); //1 min in real time = 1 sec in simulation
//        qInfo("hello");
//    }
//    softOff();
}

void Therapy::softOn(){
    qInfo("soft on");
    for (int i = 0; i < intensity; i++){
        sleep(1);
    }
}

void Therapy::softOff(){
    qInfo("soft off");
    for (int i = 0; i < intensity; i++){
        sleep(1);
    }
}

void Therapy::incIntensity(){
    if (intensity < MAX_INTENSITY) intensity++;
    qDebug() << "increase to intensity " << intensity;
}

void Therapy::decIntensity(){
    if (intensity > 1) intensity--;
    qDebug() << "decrease to intensity " << intensity;
}

int Therapy::getDuration()
{
    return duration;
}

Session Therapy::getSession()
{
    return session;
}

