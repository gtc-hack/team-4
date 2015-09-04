#include "Turning.h"
#include <SPI.h>

#include <Wire.h>
#include <math.h>

#include <ArduinoRobot.h> // include the robot library

int speed = 135;
int stopTime = 200;
int operationTime = 450;

void go(int straight, int direction, int turnSpeed, int turnTime, int stopTime) {
  Robot.motorsWrite(straight * turnSpeed * direction, turnSpeed * direction);
  delay(turnTime);
  Robot.motorsStop();
  delay(stopTime);
}

void turnLeft() {
  go(-1, 1, speed, operationTime, stopTime);
}

void turnRight() {
  go(-1, -1, speed, operationTime, stopTime);
}

void goForward() {
  go(1, 1, speed, operationTime, stopTime);
}

void goReverse() {
  go(1, -1, speed, operationTime, stopTime);
}


