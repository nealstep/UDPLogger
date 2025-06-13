#ifndef UDPLOGGER_H
#define UDPLOGGER_H

#include <Arduino.h>

#define DEFAULT_BAUD 115200
#define DEFAULT_PORT 4141

class UDPLogger {
public:
  enum LogLevel {DEBUG, INFO, WARNING, ERROR, VALUE, COUNT};
  void initUDP(const char *udp_server, const uint16_t udp_port=DEFAULT_PORT);
  void initSerial(int32_t serial_baud=DEFAULT_BAUD);
  void setLevel(LogLevel level);
  void log(LogLevel level, const String msg);
  void log(LogLevel level, const char *msg) {
    log(level, String(msg));
  }

  void logValue(LogLevel level, const char *name, String value);
  void logValue(LogLevel level, const char *name, const char *value) {
    logValue(INFO, name, String(value));    
  }
  void logValue(LogLevel level, const char *name, uint32_t value) {
    logValue(INFO, name, String(value));    
  }
  
  void error(const char *msg) {
    log(ERROR, msg);
  }
  void warning(const char *msg) {
    log(WARNING, msg);
  }
  void info(const char *msg) {
    log(INFO, msg);
  }
  void info(const char *key, String val) {
    logValue(INFO, key, val);
  }
  void info(const char *key, const char *val) {
    logValue(INFO, key, val);
  }
  void info(const char *key, uint32_t val) {
    logValue(INFO, key, val);
  }
  void debug(const char *msg) {
    logChars(DEBUG, msg);
  }

private:
  bool logSerial = false;
  bool logUDP = false;
  String host;
  uint16_t port;
  LogLevel logLevel;
  const char prefix[static_cast<int>(LogLevel::COUNT)] = {'%', '#', '*', '!', '$'};
};

#endif // UDPLOGGER
