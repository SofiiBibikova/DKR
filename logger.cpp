#include "logger.h"

Logger::Logger(const std::string& filename) {
    logfile.open(filename);
}

Logger::~Logger() {
    logfile.close();
}

void Logger::log(const std::string& message) {
    if (logfile.is_open()) {
        logfile << message << std::endl;
    }
}