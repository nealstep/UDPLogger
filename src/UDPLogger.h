#ifndef UDPLOGGER_H
#define UDPLOGGER_H

#include <Arduino.h>

#define DEFAULT_BAUD 115200
#define DEFAULT_PORT 4141

class UDPLogger {
   public:
    enum LogLevel { DEBUG, INFO, WARNING, ERROR, VALUE, COUNT };
    void initUDP(const char *udp_server,
                 const uint16_t udp_port = DEFAULT_PORT);
    void initSerial(int32_t serial_baud = DEFAULT_BAUD);
    void setLevel(LogLevel level);

    void log(LogLevel level, const String msg);
    void log(LogLevel level, const char *msg) { log(level, String(msg)); }

    void logValue(LogLevel level, const char *name, String value);
    void logValue(LogLevel level, const char *name, const char *value) {
        logValue(level, name, String(value));
    }
    void logValue(LogLevel level, const char *name, uint64_t value,
                  uint8_t base = 10) {
        logValue(level, name, String(value, base));
    }
    void logValue(LogLevel level, const char *name, uint32_t value,
                  uint8_t base = 10) {
        logValue(level, name, String(value, base));
    }
    void logValue(LogLevel level, const char *name, uint16_t value,
                  uint8_t base = 10) {
        logValue(level, name, String(value, base));
    }
    void logValue(LogLevel level, const char *name, uint8_t value,
                  uint8_t base = 10) {
        logValue(level, name, String(value, base));
    }
    void logValue(LogLevel level, const char *name, int64_t value,
                  uint8_t base = 10) {
        logValue(level, name, String(value, base));
    }
    void logValue(LogLevel level, const char *name, int32_t value,
                  uint8_t base = 10) {
        logValue(level, name, String(value, base));
    }
    void logValue(LogLevel level, const char *name, int16_t value,
                  uint8_t base = 10) {
        logValue(level, name, String(value, base));
    }
    void logValue(LogLevel level, const char *name, int8_t value,
                  uint8_t base = 10) {
        logValue(level, name, String(value, base));
    }
    void logValue(LogLevel level, const char *name, float value,
                  uint8_t decimalPlaces = 2) {
        logValue(level, name, String(value, decimalPlaces));
    }
    void logValue(LogLevel level, const char *name, double value,
                  uint8_t decimalPlaces = 2) {
        logValue(level, name, String(value, decimalPlaces));
    }

    // convenience routines
    void value(const char *key, String val) { logValue(VALUE, key, val); }
    void value(const char *key, const char *val) { logValue(VALUE, key, val); }
    void value(const char *key, uint64_t val, uint8_t base = 10) {
        logValue(VALUE, key, val, base);
    }
    void value(const char *key, uint32_t val, uint8_t base = 10) {
        logValue(VALUE, key, val, base);
    }
    void value(const char *key, uint16_t val, uint8_t base = 10) {
        logValue(VALUE, key, val, base);
    }
    void value(const char *key, uint8_t val, uint8_t base = 10) {
        logValue(VALUE, key, val, base);
    }
    void value(const char *key, int64_t val, uint8_t base = 10) {
        logValue(VALUE, key, val, base);
    }
    void value(const char *key, int32_t val, uint8_t base = 10) {
        logValue(VALUE, key, val, base);
    }
    void value(const char *key, int16_t val, uint8_t base = 10) {
        logValue(VALUE, key, val, base);
    }
    void value(const char *key, int8_t val, uint8_t base = 10) {
        logValue(VALUE, key, val, base);
    }
    void value(const char *key, double val, uint8_t base = 10) {
        logValue(VALUE, key, val, base);
    }
    void value(const char *key, float val, uint8_t base = 10) {
        logValue(VALUE, key, val, base);
    }
    void error(const char *msg) { log(ERROR, msg); }
    void warning(const char *msg) { log(WARNING, msg); }
    void info(const char *msg) { log(INFO, msg); }
    void info(const char *key, String val) { logValue(INFO, key, val); }
    void info(const char *key, const char *val) { logValue(INFO, key, val); }
    void info(const char *key, uint64_t val, uint8_t base = 10) {
        logValue(INFO, key, val, base);
    }
    void info(const char *key, uint32_t val, uint8_t base = 10) {
        logValue(INFO, key, val, base);
    }
    void info(const char *key, uint16_t val, uint8_t base = 10) {
        logValue(INFO, key, val, base);
    }
    void info(const char *key, uint8_t val, uint8_t base = 10) {
        logValue(INFO, key, val, base);
    }
    void info(const char *key, int64_t val, uint8_t base = 10) {
        logValue(INFO, key, val, base);
    }
    void info(const char *key, int32_t val, uint8_t base = 10) {
        logValue(INFO, key, val, base);
    }
    void info(const char *key, int16_t val, uint8_t base = 10) {
        logValue(INFO, key, val, base);
    }
    void info(const char *key, int8_t val, uint8_t base = 10) {
        logValue(INFO, key, val, base);
    }
    void info(const char *key, double val, uint8_t base = 10) {
        logValue(INFO, key, val, base);
    }
    void info(const char *key, float val, uint8_t base = 10) {
        logValue(INFO, key, val, base);
    }
    void debug(const char *msg) { log(DEBUG, msg); }
    void debug(const char *key, String val) { logValue(DEBUG, key, val); }
    void debug(const char *key, const char *val) { logValue(DEBUG, key, val); }
    void debug(const char *key, uint64_t val, uint8_t base = 10) {
        logValue(DEBUG, key, val, base);
    }
    void debug(const char *key, uint32_t val, uint8_t base = 10) {
        logValue(DEBUG, key, val, base);
    }
    void debug(const char *key, uint16_t val, uint8_t base = 10) {
        logValue(DEBUG, key, val, base);
    }
    void debug(const char *key, uint8_t val, uint8_t base = 10) {
        logValue(DEBUG, key, val, base);
    }
    void debug(const char *key, int64_t val, uint8_t base = 10) {
        logValue(DEBUG, key, val, base);
    }
    void debug(const char *key, int32_t val, uint8_t base = 10) {
        logValue(DEBUG, key, val, base);
    }
    void debug(const char *key, int16_t val, uint8_t base = 10) {
        logValue(DEBUG, key, val, base);
    }
    void debug(const char *key, int8_t val, uint8_t base = 10) {
        logValue(DEBUG, key, val, base);
    }
    void debug(const char *key, double val, uint8_t base = 10) {
        logValue(DEBUG, key, val, base);
    }
    void debug(const char *key, float val, uint8_t base = 10) {
        logValue(DEBUG, key, val, base);
    }

   private:
    bool logSerial = false;
    bool logUDP = false;
    String host;
    uint16_t port;
    LogLevel logLevel;
    const char prefix[static_cast<int>(LogLevel::COUNT)] = {'%', '#', '*', '!',
                                                            '$'};
};

#endif  // UDPLOGGER
