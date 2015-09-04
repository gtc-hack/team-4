// include the robot library
#include <ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>
//#include <Maze.h>
#include <RobotPen.h>
#include <Turning.h>

int sensorPin = M1;  // pin is used by the sensor
int compassValue;
int direc = 180;  //Direction the robot is heading
RobotPen RobotPen;
//Maze amaze;
    
void setup() {
  // put your setup code here, to run once:
  // initialize the Robot, SD card, and display
  Serial.begin(9600);
  Robot.begin();
  Robot.beginTFT();
  Robot.beginSD();
  Robot.beginSpeaker();
  Robot.displayLogos();
  RobotPen.setup();
  RobotPen.penUp();
  Robot.text("PEN - UP", 10, 10);
  Robot.beep(BEEP_DOUBLE);
}

void loop() {
  Robot.clearScreen();
  Robot.drawCompass(Robot.compassRead()); 
  Robot.motorsStop();
  Robot.beep(BEEP_DOUBLE);
  
//  Robot.debugPrint(amaze.next_move(),10,10);
  //Turn 90deg
//  Robot.motorsWrite(-128, 128);
//  delay(500);
//  Robot.motorsStop();
  turnLeft();
  RobotPen.penDown();
  delay(500);

  //Move Forward
//  Robot.motorsWrite(128, 128);
//  delay(1000);
//  Robot.motorsStop();
  goForward();
  RobotPen.penUp();
  delay(1000);
}

