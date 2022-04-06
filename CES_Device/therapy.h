#ifndef THERAPY_H
#define THERAPY_H

#include <QString>
#include "session.h"

class Therapy
{
public:
    Therapy(Session, int, int);
    QString getTherapy();
    bool startSession();

private:
    Session session;
    int intensity;
    int duration;
    void delay();
    void softOn();
    void softOff();
    void incIntensity();
    void decIntensity();
};

#endif // THERAPY_H
