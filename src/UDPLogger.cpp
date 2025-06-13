#include "UDPLogger.h"

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#else
#error "Not supported"
#endif // ESP8266
#include <WiFiUdp.h>

WiFiUDP udp;

void UDPLogger::initUDP(const char *udp_server, const uint16_t udp_port) {
  host = String(udp_server);
  port = udp_port;
  logUDP = true;
}

void UDPLogger::initSerial(int32_t serial_baud) {
  Serial.begin(serial_baud);
  logSerial = true;
}

void UDPLogger::setLevel(LogLevel level) {
  logLevel = level;
}

void UDPLogger::log(LogLevel level, const String msg) {
  if (level >= logLevel) {
    String message = String(prefix[static_cast<int>(level)]) + String(" ");
    message += msg;
    if (logSerial) {
      Serial.println(message);
    }
    if (WiFi.status() == WL_CONNECTED) {
      if (logUDP) {
        udp.beginPacket(host.c_str(), port);
        udp.write(message.c_str());
        udp.write((const uint8_t *)message.c_str(), message.length());
        udp.endPacket();
      }
    }
  }
}

void UDPLogger::logValue(LogLevel level, const char *name, const String value) {
  String message = String(name) + String(": ") + value;
  log(level, message);
}
