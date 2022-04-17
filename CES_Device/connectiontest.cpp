#include "connectiontest.h"

connectionTest::connectionTest()
{
   blink =  new QTimer();
   connect(blink, &QTimer::timeout, this, &connectionTest::sendblink_modeLight); //Connect the timer to a function
}

int connectionTest::checkConnection(bool w, bool x, bool y, bool z){
    //This Function will determine which type of connection we are, 0 = EXCELLENT, 1 2 and 3 = OK, 4 = NO CONNECTION
    if((w == true) && (x == true) && (y == true) && (z == true)){
        return 0;
    } else if((w == true) && (x == true) && (y == true)){
        return 1;
    } else if((w == true) && (x == true) && (z == true)){
        return 2;
    } else if((w == true) && (x == true)){
        return 3;
    }else{
        return 4;
    }
}

void connectionTest::sendblink_modeLight(){
    //This will start a timer so it will emit this signal every second
    blink->start(1000);
    emit blink_modeLight();
}
void connectionTest::senddisplayConnection(int x){
    //Another signal
    emit displayConnection(x);
}
void connectionTest::sendclearDisplay(){
    //Another signal
    emit clearDisplay();
}

void connectionTest::stopTimer(){
    //This is to tell the timer to stop, aka once we are done with the connection phase
    blink->stop();
}
