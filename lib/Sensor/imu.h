#ifndef IMU_H
#define IMU_H

#include <DFRobot_BMI160.h>

class IMUClass {
public:
    IMUClass();
    bool begin();
    void update();
    void getAccData(float &accX, float &accY, float &accZ);
    void getGyrData(float &gyrX, float &gyrY, float &gyrZ);
    float getAccX() const;
    float getAccY() const;
    float getAccZ() const;
    float getGyrX() const;
    float getGyrY() const;
    float getGyrZ() const;
    float getTemp() const;
    
    float deltatUpdate();
    float getDeltat() const;

    float getPitch();
    float getRoll();
    float getYaw();
    void getPitchRollYaw(float &pitch, float &roll, float &yaw);

    void calculateGyrBias(int numSamples=500, int sec=1);


private:
    // 成员变量保存传感器数据
    float accX, accY, accZ;
    float gyrX, gyrY, gyrZ;
    float temp;

    // 保存姿态角
    float pitch, roll, yaw;

    // 时间相关变量
    unsigned long lastUpdate; // 上次更新时间
    float deltat; // 时间间隔

    // 陀螺仪零偏
    float gyrXBias = 0.0;
    float gyrYBias = 0.0;
    float gyrZBias = 0.0;
};

#endif // IMU_H