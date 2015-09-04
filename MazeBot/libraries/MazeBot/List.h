//
//  List.h
//  
//
//  Created by Phil Rodgers on 04/09/2015.
//
//

#ifndef _List_h
#define _List_h

class List {


private:
char values[4];
int position;

public:
char at(int index) {
    return values[index];
}

void push_back(char value) {
    values[position++] = value;
}

int size() {
	return position;
}

List() : position(0) {}


};



#endif
