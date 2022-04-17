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


int Therapy::getIntensity(){
    return intensity;
}
