#include "Logger.h"

Logger* Logger::instance = nullptr;

Logger::Logger(const std::string& filename, LogLevel level, bool console)
    : minLevel(level), consoleOutput(console) {
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Warning: Could not open log file: " << filename << std::endl;
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

Logger& Logger::getInstance(const std::string& filename, LogLevel level, bool console) {
    if (instance == nullptr) {
        instance = new Logger(filename, level, console);
    }
    return *instance;
}

void Logger::setLogLevel(LogLevel level) {
    minLevel = level;
}

void Logger::setConsoleOutput(bool enable) {
    consoleOutput = enable;
}

std::string Logger::levelToString(LogLevel level) const {
    switch (level) {
        case LogLevel::DEBUG:    return "DEBUG";
        case LogLevel::INFO:     return "INFO";
        case LogLevel::WARNING:  return "WARNING";
        case LogLevel::ERROR:    return "ERROR";
        case LogLevel::CRITICAL: return "CRITICAL";
        default: return "UNKNOWN";
    }
}

std::string Logger::getCurrentTimestamp() const {
    time_t now = time(nullptr);
    struct tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return std::string(buffer);
}

void Logger::log(LogLevel level, const std::string& message) {
    if (level < minLevel) return;

    std::ostringstream logEntry;
    logEntry << "[" << getCurrentTimestamp() << "] "
             << "[" << std::setw(8) << levelToString(level) << "] "
             << message;

    if (consoleOutput && level >= LogLevel::WARNING) {
        std::cerr << logEntry.str() << std::endl;
    }

    if (logFile.is_open()) {
        logFile << logEntry.str() << std::endl;
        logFile.flush();
    }
}

void Logger::debug(const std::string& message) {
    log(LogLevel::DEBUG, message);
}

void Logger::info(const std::string& message) {
    log(LogLevel::INFO, message);
}

void Logger::warning(const std::string& message) {
    log(LogLevel::WARNING, message);
}

void Logger::error(const std::string& message) {
    log(LogLevel::ERROR, message);
}

void Logger::critical(const std::string& message) {
    log(LogLevel::CRITICAL, message);
}
