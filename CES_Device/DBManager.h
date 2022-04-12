#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

class DBManager {

    public:
        //constructor
        DBManager();

        //other
        QString readLog();
        void writeLog(QString);

    private:
        //variables
        QString fileName;
};
#endif
