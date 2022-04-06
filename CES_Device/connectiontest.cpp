#include "connectiontest.h"

connectionTest::connectionTest()
{
   blink =  new QTimer();
   connect(blink, &QTimer::timeout, this, &connectionTest::sendblink_modeLight);
}

int connectionTest::checkConnection(bool w, bool x, bool y, bool z){
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

//void connectionTest::sendcheckConnection(){
  //  emit checkConnection();
//}
void connectionTest::sendblink_modeLight(){
    blink->start(1000);
    emit blink_modeLight();
}
void connectionTest::senddisplayConnection(int x){
    emit displayConnection(x);
}
void connectionTest::sendsoftOn(){
    emit softOn();
}
void connectionTest::sendsoftOff(){
    emit softOff();
}
void connectionTest::sendclearDisplay(){
    emit clearDisplay();
}
void connectionTest::sendwetEarLobes(){
    emit wetEarLobes();
}
