#ifndef MAZE_H
#define MAZE_H

#include "StackArray.h"
#include "Point.h"
#include "List.h"

#define UP 8
#define RIGHT 4
#define DOWN 2
#define LEFT 1

class Maze
{
    
public:
    static const int width = 10;
    static const int height = 10;
    Maze();
    virtual ~Maze();
    int next_move();
	int grid_value(int x, int y);
    
private:

	char grid[100];
    Point start = Point(width/2, height/2);
    Point current = Point(width/2, height/2);
    StackArray<char> path;
    
    void getMoves(List& list);
    int oppositeMove(int move);
    int randomMove(List& list);
    void makeMove(int move, bool draw);
    bool connectPoints(Point p1, Point p2);
    double distance(Point p1, Point p2);
	bool isOpen(int x, int y);
    
};

#endif // MAZE_H

