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
  RoboPen.penDown();
  if(choice != 0) {
    switch(choice) {
      case 1:
        RoboPen.penUp();
        goForward();
        turnLeft();
        goReverse();
        RoboPen.penDown();
        goForward();
        break; //left
      case 2:
        RoboPen.penDown();
        goReverse();
        break; //down
      case 4: 
        RoboPen.penUp();
        goForward();
        turnRight();
        goReverse();
        RoboPen.penDown();
        goForward();
        break; //right
      case 8: 
        RoboPen.penDown();
        goForward();
        break; //up
      case -1:
        RoboPen.penUp();
        goForward();
        turnLeft();
        goReverse();
        // RoboPen.penDown();
        goForward();
        break; //left
      case -2:
        RoboPen.penUp();
        // RoboPen.penDown();
        goReverse();
        break; //down
      case -4: 
        RoboPen.penUp();
        goForward();
        turnRight();
        goReverse();
        // RoboPen.penDown();
        goForward();
        break; //right
      case -8: 
        RoboPen.penUp();
        goForward();
        break; //up
    }
  } else {
    Robot.beep(BEEP_DOUBLE);
    Robot.beep();
  }
  delay(1000);
}
