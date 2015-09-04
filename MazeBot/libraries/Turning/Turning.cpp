#include "Turning.h"
#include <SPI.h>

#include <Wire.h>
#include <math.h>

#include <ArduinoRobot.h> // include the robot library

int speed = 135;
int stopTime = 200;
int operationTime = 450;

void turnWithDelay(int deltaTime, int direction) {
  Robot.motorsWrite(-direction * 180, direction * 180);
  delay(deltaTime);
  Robot.motorsStop();
  delay(250);
}

int makeAngle(int angle) {
  while(angle < -180) {
    angle += 360;
  }
  while(angle > 180) {
    angle -=360;
  }
  return angle;
}


int debugY;
void startDebug() {
  Robot.clearScreen();
  debugY = 0;  
}

void debugLine(const char* desc, int val) {
  Robot.debugPrint(val, 0, debugY);
  Robot.text(desc, 60, debugY);
  debugY+=10;
}

int readRobotAngle() {
  return Robot.compassRead() - 180;
}

void turn(int angle) {
  int originAngle = readRobotAngle();
  int expectedAngle = makeAngle(originAngle + angle);

  int turnTime = abs(angle) * 6;
  while(turnTime > 10) {
    int diff = makeAngle(readRobotAngle() - expectedAngle);
    
    turnWithDelay(turnTime, diff > 0 ? -1 : 1);
    turnTime = (turnTime*3) / 4;
  }
}

void go(int straight, int direction, int turnSpeed, int turnTime, int stopTime) {
  Robot.motorsWrite(straight * turnSpeed * direction, turnSpeed * direction);
  delay(turnTime);
  Robot.motorsStop();
  delay(stopTime);
}

void turnLeft() {
  // go(-1, 1, speed, operationTime, stopTime);
  turn(-90);
}

void turnRight() {
  //go(-1, -1, speed, operationTime, stopTime);
  turn(90);
}

void goForward() {
  go(1, 1, speed, operationTime, stopTime);
}

void goReverse() {
  go(1, -1, speed, operationTime, stopTime);
}


