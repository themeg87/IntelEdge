#include <iostream>
using namespace std;

#include "Seat.h"
#include "Schedule.h"

Schedule::Schedule(){
	seat = new Seat[8];
	time = "";
}

Schedule::~Schedule(){
	delete [] seat;
}


void Schedule::setTime(string time) {
	this->time = time;
}

void Schedule::view(){
	cout << time << ":\t";
	for(int i=0; i<8; i++)
		seat[i].view();
	cout << endl;
}

void Schedule::book(int no, string name){
	seat[no-1].book(name);
}

void Schedule::cancel(int no, string name){
	return seat[no-1].cancel(name);
}