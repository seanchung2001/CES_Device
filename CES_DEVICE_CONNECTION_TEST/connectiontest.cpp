#include "connectiontest.h"

ConnectionTest::ConnectionTest()
{

}

void ConnectionTest::test(){
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ConnectionTest::blink_modeLight);
    timer->start(1000);
}


//Int ConenctoinTest::checkConnetion(){
  //  if(/*no connection*/){
        //return /*int for no connection*/
    //}else if(/*mild connection*/) {
        //return/*int for which ear needs to be working*/
   // }else{
        //return /*int for good connection*/
   // }
//}

void ConnectionTest::blink_modeLight(){
std::cout<<"The Light Blinks"<<std::endl;
}
/*
void ConenctoinTest::displayConnection(){

}
void ConenctoinTest::softOn(){

}
void ConenctoinTest::softOff(){

}
void ConenctoinTest::clearDisplay(){

}
void ConenctoinTest::wetEarLobes(){

}


*/
