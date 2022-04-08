#ifndef THERAPY_H
#define THERAPY_H

#include <QString>
#include "session.h"

class Therapy
{
public:
    Therapy(Session, int);
    QString getTherapy();
    void startSession();
    void endSession();
    void softOn();
    void softOff();
    void incIntensity();
    void decIntensity();

private:
    Session session;
    int intensity;
    int duration;
};

#endif // THERAPY_H
