#ifndef THERAPY_H
#define THERAPY_H

#include <QString.h>
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
    void softOn();
    void softOff();
};

#endif // THERAPY_H
