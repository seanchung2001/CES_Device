#include "therapy.h"
#include <unistd.h>


Therapy::Therapy(Session s, int i, int d)
    :session(s), intensity(i), duration(d)
{

}

QString Therapy::getTherapy(){
    return this->session + " at " + this->intensity + " intensity for " + this->duration;
}

bool Therapy::startSession(){
    softOn();
    for (int i = 0; i < duration; i++){
        sleep(1); //1 min in real time = 1 sec in simulation
    }
    softOff();
}

void Therapy::softOn(){
    //gradual increase
    for (int i = 0; i < intensity; i++){
        sleep(1);
    }
}

void Therapy::softOff(){
    //gradual decrease
    for (int i = 0; i < intensity; i++){
        sleep(1);
    }
}
