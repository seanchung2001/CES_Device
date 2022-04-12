#include "DBManager.h"

//ctor
DBManager::DBManager() {
    fileName = "database.txt";
}
//read database.txt and return
QString DBManager::readLog() {
    //set File and open
    QFile dataFile(fileName);
    //var to save the entire log
    QString fullDataLog;
    //var to save just current line
    QString dataLine;
    //open as readonly
    if (dataFile.open(QIODevice::ReadOnly)) {
        //set textstream
        QTextStream in(&dataFile);
        //start out log with intro
        fullDataLog += "Sessions Log:\n";
        //while not at end
        while(!in.atEnd()) {
            //read line by line and append to fullDataLog
            dataLine = in.readLine();
            fullDataLog += dataLine;
            fullDataLog += '\n';
        }
        dataFile.close();
    }
    return fullDataLog;
}
//write to database.txt
void DBManager::writeLog(QString log) {
    //set File
    QFile dataFile(fileName);
    //open for writing
    if (dataFile.open(QIODevice::Append)) {
        QTextStream stream(&dataFile);
        stream << log << endl;
    }
}
