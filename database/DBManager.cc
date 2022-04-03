#include "DBManager.h"

//ctor
DBManager::DBManager() {
    fileName = "database.txt";
}
//read database.txt and return
string DBManager::readLog() {
    //open file
    ifstream DataBase(fileName);
    //each line in file
    string dataLine;
    //entire file
    string fullDataLog;
    //read line by line
    while (getline (DataBase, dataLine)) {
        fullDataLog += dataLine;
        fullDataLog += '\n';
    }
    //close
    DataBase.close();
    return fullDataLog;
}
//write to database.txt
void DBManager::writeLog(string log) {
    //open file
    ofstream DataBase(fileName, ios::app);
    //write
    DataBase << log << endl;
    //close
    DataBase.close();
}