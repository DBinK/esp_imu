#include <Arduino.h>
#include "imu.h"
#include "utility.h"

IMUClass imu;  // 使用自定义引脚 IMUClass imu(10, 11, 12, 13);
TimeDiff loop_dt;

float gx, gy, gz, ax, ay, az;
float pitch=0, roll=0, yaw=0;
float deltat=0;

void setup() {
    Serial.begin(115200);
    while (!Serial) {}

    Serial.println("Start...");
    
    if (!imu.begin()) {
        Serial.println("IMU initialization unsuccessful");
        while (1) {}
    }
    
    Serial.println("IMU begin...");

    // imu.calculateGyrBias(100);  // 计算陀螺仪Z轴零偏
}


void loop() {

    imu.update();

    // imu.getAccData(ax, ay, az);
    // imu.getGyrData(gx, gy, gz);

    // 显示原始数据
    // Serial.printf("ax: %f\t ay: %f\t az: %f\t gx: %f\t gy: %f\t gz: %f\n", 
    //              ax, ay, az, gx, gy, gz);

    imu.getPitchRollYaw(pitch, roll, yaw);  // 获取姿态角
    // deltat = imu.getDeltat() * 1000;        // ms
    deltat = loop_dt.time_diff() / 1000;      // ms
    
    // 对于倒置的IMU，将pitch和roll加减180度
    // pitch = (pitch > 0) ? (pitch - 180) : (pitch + 180);
    // roll  =  (roll > 0) ?  (roll - 180) :  (roll + 180);

    Serial.printf("Pitch: %.2f\t Roll: %.2f\t Yaw: %.2f\t deltat: %.6f ms \n", pitch, roll, yaw, deltat);

    delay(1);
}