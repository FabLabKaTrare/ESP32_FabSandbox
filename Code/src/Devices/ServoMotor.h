#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "DeviceBaseClass.h"
#include "config.h"

#if defined(ESP32)
#include "ESP32Servo.h"
#endif

class ServoMotor : public DeviceBaseClass
{
public:
    ServoMotor();
    /// 
    void begin(uint8_t pin, const char *deviceKey);
    void checkConnection();
    bool isConnected();
    int read();
    void readAndNotify();

    /// Base Class functions
    void setValue(const JsonDocument &doc) override;
    void getValue() override;
    void setGPIO(uint8_t pin) override;

private:
    Servo servo;
};

#endif
