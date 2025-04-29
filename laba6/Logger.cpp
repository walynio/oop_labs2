#include "Logger.h"
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>

Logger* Logger::instance = nullptr;

Logger* Logger::getInstance() {
    if (!instance) {
        instance = new Logger();
    }
    return instance;
}

void Logger::addRecord(const string& record) {
    time_t now = time(0);
    tm timeinfo;
    localtime_s(&timeinfo, &now);

    ostringstream ss;
    ss << put_time(&timeinfo, "time: %y.%m.%d %H:%M:%S\n");
    log.push_back(ss.str() + record);
}

void Logger::saveLog(int objectCount, const string& className) {
    ofstream out("log.txt");
    if (out.is_open()) {
        time_t now = time(0);
        tm timeinfo;
        localtime_s(&timeinfo, &now);

        out << "ClassName: " << className << "\n";
        out << "numberOfEntities: " << objectCount << "\n";
        out << put_time(&timeinfo, "time: %y.%m.%d %H:%M:%S\n\n");

        for (const auto& record : log) {
            out << record << "\n";
        }

        out.close();
    }
}
