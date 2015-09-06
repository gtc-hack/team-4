#include <Arduino_LCD.h>
#include <ArduinoRobot.h>

#include <SPI.h>

#include <Wire.h>
#include <Maze.h>

Maze maze;

void setup() {
  Robot.begin();
  Robot.beginSpeaker();
  Robot.beep();
  Robot.beginTFT();
  Robot.beginSD();
  Robot.beep();
}

void loop() {
  
  if(maze.next_move()) {
    for(int y = 0 ; y < 10 ; y++) {
        for(int x = 0 ; x < 10 ; x++) {
            int t = maze.grid_value(x,y);
            switch(t) {
              case 0: Robot.drawBMP("0.bmp",x * 7,y * 7); break;
              case 1: Robot.drawBMP("1.bmp",x * 7,y * 7); break;
              case 2: Robot.drawBMP("2.bmp",x * 7,y * 7); break;
              case 3: Robot.drawBMP("3.bmp",x * 7,y * 7); break;
              case 4: Robot.drawBMP("4.bmp",x * 7,y * 7); break;
              case 5: Robot.drawBMP("5.bmp",x * 7,y * 7); break;
              case 6: Robot.drawBMP("6.bmp",x * 7,y * 7); break;
              case 7: Robot.drawBMP("7.bmp",x * 7,y * 7); break;
              case 8: Robot.drawBMP("8.bmp",x * 7,y * 7); break;
              case 9: Robot.drawBMP("9.bmp",x * 7,y * 7); break;
              case 10: Robot.drawBMP("10.bmp",x * 7,y * 7); break;
              case 11: Robot.drawBMP("11.bmp",x * 7,y * 7); break;
              case 12: Robot.drawBMP("12.bmp",x * 7,y * 7); break;
              case 13: Robot.drawBMP("13.bmp",x * 7,y * 7); break;
              case 14: Robot.drawBMP("14.bmp",x * 7,y * 7); break;
              case 15: Robot.drawBMP("15.bmp",x * 7,y * 7); break;
            }
        } 
    }
  } else {
    Robot.beep();
    delay(1000);
  }
  
}
