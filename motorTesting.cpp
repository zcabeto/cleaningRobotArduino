#include "Grove_I2C_Motor_Driver.h"
#define I2C_Address 0x0f

void setup()
{
    Motor.begin(I2C_Address);
    Serial.begin(9600);
}

void loop()
{
    Motor.speed(MOTOR1, 50);
    delay(1000);
    Motor.speed(MOTOR1, -50);
    delay(1000);
    Motor.speed(MOTOR1, 20);
    delay(2000);
    Motor.speed(MOTOR1, -70);
    delay(500);
    Motor.stop(MOTOR1);
    delay(1000);
}