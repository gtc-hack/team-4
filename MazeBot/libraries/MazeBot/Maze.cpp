
#include "Maze.h"
#include "List.h"
#include "Point.h"

Maze::Maze() : start(width/2, height/2), current(width/2, height/2)  {
    // randomSeed(analogRead(0));
    const int size = width * height;
    for (int i = 0; i < size; i++) {
        grid[i] = 0;
    }
}


Maze::~Maze() {
    delete[] grid;
}

int Maze::next_move() {
    List list;
    getMoves(list);
    if (list.size() == 0) {
        if (path.isEmpty()) {
            return 0;
        }
        int move = oppositeMove(path.pop());
        makeMove(move, false);
        return -move;
    } else {
        int move = randomMove(list);
        path.push(move);
        makeMove(move, true);
        return move;
    }
}

int Maze::oppositeMove(int move) {
    switch (move) {
        case 8: return 2;
        case 4: return 1;
        case 2: return 8;
        case 1: return 4;
        default: return 0;
    }
}

int Maze::randomMove(List& list) {
    return list.at(random(list.size()));
}

void Maze::getMoves(List& list) {
    if (isOpen(current.first, current.second - 1)) {
        list.push_back(UP);
    }
    if (isOpen(current.first, current.second + 1)) {
        list.push_back(DOWN);
    }
    if (isOpen(current.first - 1, current.second)) {
        list.push_back(LEFT);
    }
    if (isOpen(current.first + 1, current.second)) {
        list.push_back(RIGHT);
    }
}

void Maze::makeMove(int move, bool draw) {
    Point old = current;
    switch (move) {
        case UP: {
            current = Point(current.first, current.second - 1); break;
        }
        case RIGHT: {
            current = Point(current.first + 1, current.second); break;
        }
        case DOWN: {
            current = Point(current.first, current.second + 1); break;
        }
        case LEFT: {
            current = Point(current.first - 1, current.second); break;
        }
    }
    if (draw) {
        connectPoints(old, current);
    }
}

bool Maze::connectPoints(Point p1, Point p2) {
    if (true) { // Sanity check.  Could probably do without this function.
        switch (p1.first - p2.first) {
            case -1: //Right
                grid[p1.second * Maze::width + p1.first] |= RIGHT;
                grid[p2.second * Maze::width + p2.first] |= LEFT;
                return true;
            case 1: //Left
                grid[p1.second * Maze::width + p1.first] |= LEFT;
                grid[p2.second * Maze::width + p2.first] |= RIGHT;
                return true;
            case 0:
                switch (p1.second - p2.second) {
                    case -1: //Down
                        grid[p1.second * Maze::width + p1.first] |= DOWN;
                        grid[p2.second * Maze::width + p2.first] |= UP;
                        return true;
                    case 1: //Up
                        grid[p1.second * Maze::width + p1.first] |= UP;
                        grid[p2.second * Maze::width + p2.first] |= DOWN;
                        return true;
                    default:
                        return false;
                }
            default:
                return false;
        }
    }
    else {
        return false;
    }
}

bool Maze::isOpen(int x, int y) {
	return x > 0 && x < 19 && y > 0 && y < 19 && grid[y * width + x] == 0;
}

int Maze::grid_value(int x, int y) {
	return grid[y * Maze::width + x];
}
