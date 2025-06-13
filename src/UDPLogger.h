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
    void logString(LogLevel level, const String msg);
    void logChars(LogLevel level, const char *msg);
    void logValueUI(LogLevel level, const char *name, uint32_t value);

  private:
    bool logSerial = false;
    bool logUDP = false;
    String host;
    uint16_t port;
    LogLevel logLevel;
    const char prefix[static_cast<int>(LogLevel::COUNT)] = {'%', '#', '*', '!', '$'};
};

#endif // UDPLOGGER
