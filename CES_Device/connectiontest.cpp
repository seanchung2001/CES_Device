#include "connectiontest.h"

connectionTest::connectionTest()
{

}




void connectionTest::sendcheckConnection(){
    emit checkConnection();
}

void connectionTest::sendblink_modeLight(){
    emit blink_modeLight();
}
void connectionTest::senddisplayConnection(){
    emit displayConnection();
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
