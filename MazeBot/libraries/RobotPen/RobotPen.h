#ifndef ROBOPEN_H
#define ROBOPEN_H

#include <ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>

class RobotPen {

  int motorPin1 = D0;    // pin 1
  int motorPin2 = D3;    // pin 2
  int motorPin3 = D4;    // pin 3
  int motorPin4 = D5;    // pin 4
  int motorSpeed = 1200;  //variable to set stepper speed
  int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

public:
  void setup();
  void penDown();
  void penUp();
  void setOutput(int out);
};
#endif // ROBOPEN_H