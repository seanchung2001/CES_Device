#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DBManager {
		
	public:
		//constructor
		DBManager();

		//other
		string readLog();
        void writeLog(string);
	
	private:
		//variables
        string fileName;
};
#endif
