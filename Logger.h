#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>

/**
 * @brief Log level enumeration
 */
enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

/**
 * @brief Singleton Logger class for application-wide logging
 */
class Logger {
private:
    std::ofstream logFile;
    LogLevel minLevel;
    bool consoleOutput;
    static Logger* instance;

    Logger(const std::string& filename = "task_manager.log", 
           LogLevel level = LogLevel::INFO,
           bool console = true);
    
    std::string levelToString(LogLevel level) const;
    std::string getCurrentTimestamp() const;

public:
    // Delete copy constructor and assignment operator
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    /**
     * @brief Get Logger instance (Singleton pattern)
     */
    static Logger& getInstance(const std::string& filename = "task_manager.log",
                               LogLevel level = LogLevel::INFO,
                               bool console = true);

    /**
     * @brief Set minimum log level
     */
    void setLogLevel(LogLevel level);

    /**
     * @brief Enable/disable console output
     */
    void setConsoleOutput(bool enable);

    /**
     * @brief Log a message
     */
    void log(LogLevel level, const std::string& message);

    /**
     * @brief Convenience methods for different log levels
     */
    void debug(const std::string& message);
    void info(const std::string& message);
    void warning(const std::string& message);
    void error(const std::string& message);
    void critical(const std::string& message);

    ~Logger();
};

#endif // LOGGER_H
