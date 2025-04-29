#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
using namespace std;

class Logger {
private:
    static Logger* instance;
    vector<string> log;

    Logger() {}
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    static Logger* getInstance();
    void addRecord(const string& record);
    void saveLog(int objectCount, const string& className);
};

#endif
