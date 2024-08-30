#include "Logger.h"

Logger::Logger(const String& name, LogLevel logLevel, Print& output)
    : name(name), logLevel(logLevel), output(output)
{
}

void Logger::debug(const String& msg)
{
    this->log(DEBUG, msg);
}

void Logger::info(const String& msg)
{
    this->log(INFO, msg);
}

void Logger::warn(const String& msg)
{
    this->log(WARNING, msg);
}

void Logger::error(const String& msg)
{
    this->log(ERROR, msg);
}

void Logger::log(LogLevel level, const String& msg)
{
    if (level < this->logLevel) return;  // Don't log if the level is below the current log level

    output.print("[");
    output.print(millis() / 1000);
    output.print("] ");
    output.printf("[%s] %s\t%s\n", stringifyLogLevel(level).c_str(), name.c_str(), msg.c_str());
}

void Logger::setLogLevel(LogLevel logLevel)
{
    this->logLevel = logLevel;
}

String Logger::stringifyLogLevel(LogLevel logLevel)
{
    switch (logLevel)
    {
    case DEBUG:
        return "DEBUG";
    case INFO:
        return "INFO";
    case WARNING:
        return "WARNING";
    case ERROR:
        return "ERROR";
    default:
        return "[UNKNOWN]";
    }
}