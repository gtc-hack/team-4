// include the robot library
#include <ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>
#include <Maze.h>
#include <RobotPen.h>
#include <Turning.h>

#define DRAW_UP 0
#define DRAW_RIGHT 270
#define DRAW_DOWN 180
#define DRAW_LEFT 90

int sensorPin = M1;  // pin is used by the sensor
int compassValue;
int direc = 180;  //Direction the robot is heading
RobotPen RoboPen;
Maze amaze;
    
void setup() {
  // put your setup code here, to run once:
  // initialize the Robot, SD card, and display
  Serial.begin(9600);
  Robot.begin();
  Robot.beginTFT();
  Robot.beginSpeaker();
  RoboPen.setup();
  RoboPen.penUp();
  Robot.beep(BEEP_DOUBLE);
}

void loop() {
  int compassValue = Robot.compassRead();
  Robot.clearScreen();
  Robot.drawCompass(compassValue); 
  Robot.motorsStop();
  Robot.beep(BEEP_DOUBLE);
  int choice = amaze.next_move();
  int turns = compassValue / 90;
  Robot.debugPrint(turns,10,10);
  if(choice != 0) {
    switch(choice) {
      case 1:
        goForward();
        goForward();
        goForward();
        turnLeft();
        goReverse();
        goReverse();
        goReverse();
        RoboPen.penDown();
        delay(500);
        goForward();
        goForward();
        goForward();
        RoboPen.penUp();
        delay(500);
        break; //left
      case 2:
        RoboPen.penDown();
        delay(500);
        goReverse();
        goReverse();
        goReverse();
        RoboPen.penUp();
        delay(500);
        break; //down
      case 4:
        goForward();
        goForward();
        goForward();
        turnRight();
        goReverse();
        goReverse();
        goReverse();
        RoboPen.penDown();
        delay(500);
        goForward();
        goForward();
        goForward();
        RoboPen.penUp();
        delay(500);
        break; //right
      case 8: 
        RoboPen.penDown();
        delay(500);
        goForward();
        goForward();
        goForward();
        RoboPen.penUp();
        delay(500);
        break; //up
      case -1:
        goForward();
        goForward();
        goForward();
        turnLeft();
        break; //left
      case -2:
        goReverse();
        goReverse();
        goReverse();
        break; //down
      case -4:
        goForward();
        goForward();
        goForward();
        turnRight();
        break; //right
      case -8:
        goForward();
        goForward();
        goForward();
        break; //up
    }
  } else {
    Robot.beep(BEEP_DOUBLE);
    Robot.beep();
  }
}
