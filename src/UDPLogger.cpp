#include "UDPLogger.h"

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <wifi.h>
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

void UDPLogger::logString(LogLevel level, const String msg) {
  if (level >= logLevel) {
    String message = String(prefix[static_cast<int>(level)]) + String(" ");
    message += msg;
    if (logSerial) {
      Serial.println(message);
    }
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("wifi up");
      if (logUDP) {
        Serial.println("sending udp");
        Serial.print("Host: ");
        Serial.print(host);
        Serial.print(" Port: ");
        Serial.println(port);
        udp.beginPacket(host.c_str(), port);
        udp.write(message.c_str());
        udp.endPacket();
      }
    }
  }
}

void UDPLogger::logChars(LogLevel level, const char *msg) {
  logString(level, String(msg));
}

void UDPLogger::logValueChars(LogLevel level, const char *name, const char *value) {
  String message = String(name) + String(": ") + String(value);
  logString(level, message);
}

void UDPLogger::logValueUI(LogLevel level, const char *name, uint32_t value) {
  String message = String(name) + String(": ") + String(value);
  logString(level, message);
}
