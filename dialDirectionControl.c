#include "Grove_I2C_Motor_Driver.h"
#define I2C_Address 0x0f

// this program can accept the dial to move with more fluidity in direction
// the backward command still exists in case the robot has crashed and cannot
//      turn until it has gone straight backwards first


int direc;              // denotes forward or backward
float dial;             // read if directional dial inputs request to turn
int leftSpeed;
int rightSpeed;         // variables to store speed of wheels depending upon dial direction

void setup()
{
    Motor.begin(I2C_Address);
    Serial.begin(9600); 
    // set up motors 1 (front right), 2 (front left), 3 (back right), 4 (back left)

    pinMode(A1,INPUT);  // directional dial
    pinMode(A2,INPUT);  // forward movement button
    pinMode(A3,INPUT);  // backward movement button
}

void loop()
{
    digitialWrite(8, HIGH);         // turns on 8 when code runs
    dial = analogRead(A1);
    direc = map(dial, 0, 1023, -50, 50);
        // -50 = <-   0 = ^     50 = ->

    if (digitalRead(A2)==HIGH)      // movement authorised
    {
        rightSpeed = (int)(0-direc);
        leftSpeed = (int)(direc);
        Motor.speed(MOTOR1, rightSpeed);
        Motor.speed(MOTOR2, leftSpeed);
        Motor.speed(MOTOR3, rightSpeed);
        Motor.speed(MOTOR4, leftSpeed);
    }
    else if (digitalRead(A3)==HIGH)  // straight backward movement
    {
        Motor.speed(MOTOR1, -20);
        Motor.speed(MOTOR2, -20);
        Motor.speed(MOTOR3, -20);
        Motor.speed(MOTOR4, -20);
    }
    else                            // no movement
    {
        Motor.speed(MOTOR1, 0);
        Motor.speed(MOTOR2, 0);
        Motor.speed(MOTOR3, 0);
        Motor.speed(MOTOR4, 0);
    }
}