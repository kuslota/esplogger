#pragma once
#include <Arduino.h>

/**
 * @brief Enum representing the different log levels.
 */
enum LogLevel
{
    DEBUG,   ///< Debug level for detailed information.
    INFO,    ///< Info level for general information.
    WARNING, ///< Warning level for potential issues.
    ERROR,   ///< Error level for serious issues.
    OFF      ///< Off level to disable logging.
};

/**
 * @brief A Logger class to handle logging messages at different log levels.
 */
class Logger
{
public:
    /**
     * @brief Construct a new Logger object.
     * 
     * @param name The name or tag of the logger, typically representing the module.
     * @param logLevel The initial log level.
     * @param output The output stream to which the logs will be sent. Default is Serial.
     */
    Logger(const String& name, LogLevel logLevel, Print& output = Serial);

    /**
     * @brief Log a debug message.
     * 
     * @param msg The message to log.
     */
    void debug(const String& msg);

    /**
     * @brief Log an informational message.
     * 
     * @param msg The message to log.
     */
    void info(const String& msg);

    /**
     * @brief Log a warning message.
     * 
     * @param msg The message to log.
     */
    void warn(const String& msg);

    /**
     * @brief Log an error message.
     * 
     * @param msg The message to log.
     */
    void error(const String& msg);

    /**
     * @brief Log a message with a specific log level.
     * 
     * @param level The log level of the message.
     * @param msg The message to log.
     */
    void log(LogLevel level, const String& msg);

    /**
     * @brief Set the log level for the logger.
     * 
     * @param logLevel The new log level to set.
     */
    void setLogLevel(LogLevel logLevel);

private:
    String name;        ///< The name or tag of the logger.
    LogLevel logLevel;  ///< The current log level of the logger.
    Print& output;      ///< Reference to the output stream for logging.

    /**
     * @brief Convert a LogLevel to its corresponding string representation.
     * 
     * @param logLevel The log level to convert.
     * @return String The string representation of the log level.
     */
    String stringifyLogLevel(LogLevel logLevel);
};