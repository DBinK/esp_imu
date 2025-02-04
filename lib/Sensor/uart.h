#ifndef UART_H
#define UART_H

#include <Arduino.h>

class UART {
public:
    void begin(HWCDC &serial, long baudRate = 115200);
    String readLine();
    bool UpdatePidParams(float &kp, float &ki, float &kd, float &kp2, float &ki2, float &kd2);
    String receivedData;
    String key;
    String valueStr;
    float value;

private:
    HWCDC* _serial;
};

#endif