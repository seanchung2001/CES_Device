#ifndef THERAPY_H
#define THERAPY_H

#include <QString>
#include "session.h"

#define SOFT_TIME 1000 //ms

class Therapy
{
public:
    Therapy(Session, int);
    QString getTherapy();
    void incIntensity();
    void decIntensity();
    int getDuration();
    Session getSession();
    int getIntensity();

private:
    Session session;
    int intensity;
    int duration;
};

#endif // THERAPY_H
