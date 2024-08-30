# ESPLogger

A simple and lighweight logging library for Arduino-based projects. This library allows you to log messages at various levels (DEBUG, INFO, WARNING, ERROR) with a customizable output stream. By default, it logs to the Serial monitor, but you can use other `Print`-compatible output streams as well.

## Features

- Log messages at different levels: DEBUG, INFO, WARNING, ERROR.
- Customize the output stream (e.g., Serial, Ethernet, WiFi).
- Easy to use with clear, timestamped output.

## Installation

To use this library in your PlatformIO project:

1. Download or clone this repository into your PlatformIO project's `lib` directory.
2. Include the `logger.h` file in your project.

## Usage

Here is a basic example of how to use the LoggerLibrary:

```cpp
#include <Arduino.h>
#include <Logger.h>

// Create a logger instance with the name "NETWORKING" and log level set to DEBUG
Logger logger("NETWORKING", DEBUG);

void setup() {
    // Initialize the serial communication at a baud rate of 9600
    Serial.begin(115200);

    // Log messages of different levels using the logger instance
    logger.debug("This is a debug message.");
    logger.info("This is an info message.");
    logger.warn("This is a warning message.");
    logger.error("This is an error message.");

    // Change the log level to WARNING
    logger.setLogLevel(WARNING);

    // Now, only warning and error messages will be logged
    logger.debug("This debug message will not be shown.");
    logger.info("This info message will not be shown.");
    logger.warn("This is another warning message.");
    logger.error("This is another error message.");
}

void loop() {
    // In this example, we're not doing anything in the loop.
    // You could add other functionality here.
}
```