#include <iostream>
#include <string>

#include "DBManager.h"

int main() {
    cout << "Starting Test" <<endl;
    DBManager db;
    cout << "Reading Test" <<endl;
    string str = db.readLog();
    cout << str << endl;
    cout << "Writing Test" <<endl;
    string input = "Third line, testing testing. One two three, one two three.";
    db.writeLog(input);
    cout << "Reading Test" <<endl;
    str = db.readLog();
    cout << str << endl;
}