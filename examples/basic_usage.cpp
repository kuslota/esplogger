#include <Arduino.h>
#include <logger.h>  // Include the Logger library

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