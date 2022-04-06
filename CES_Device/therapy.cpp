#include "therapy.h"
#include <unistd.h>

#define MAX_INTENSITY 8
#define DEFAULT_INTENSITY 4
#define DELAY 5

Therapy::Therapy(Session s, int i, int d)
    :session(s), intensity(DEFAULT_INTENSITY), duration(d)
{

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

    return message + " at " + QString::number(this->intensity) + " intensity for " + QString::number(this->duration);
}

bool Therapy::startSession(){
    //check if connection test is passed
    delay();
    softOn();
    qInfo("starting therapy");
    for (int i = 0; i < duration; i++){
        sleep(1); //1 min in real time = 1 sec in simulation
    }
    softOff();
    return true;
}

void Therapy::delay(){
    qInfo("5 sec delay");
    for (int i = 0; i < DELAY; i++){
        sleep(1);
    }
}

void Therapy::softOn(){
    //gradual increase
    qInfo("soft on");
    for (int i = 0; i < intensity; i++){
        sleep(1);
    }
}

void Therapy::softOff(){
    //gradual decrease
    qInfo("soft off");
    for (int i = 0; i < intensity; i++){
        sleep(1);
    }
}

void Therapy::incIntensity(){
    if (intensity < MAX_INTENSITY) intensity++;
}

void Therapy::decIntensity(){
    if (intensity > 1) intensity--;
}
