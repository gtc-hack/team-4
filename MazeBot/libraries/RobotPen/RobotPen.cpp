
#include "RobotPen.h"

void RobotPen::setup() {
  //declare the motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

// //////////////////////////////////////////////////////////////////////////////
// Arm Control Functions
void RobotPen::penDown() {
  for(int j = 0; j< 128; j++) {
    for(int i = 0; i < 8; i++) {
      setOutput(i);
      delayMicroseconds(motorSpeed);
    }
  }
}

void RobotPen::penUp() {
  for(int j = 0; j< 128; j++) {
    for(int i = 7; i >= 0; i--) {
      setOutput(i);
      delayMicroseconds(motorSpeed);
    }
  }
}

void RobotPen::setOutput(int out) {
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
}