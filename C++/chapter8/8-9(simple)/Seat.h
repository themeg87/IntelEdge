#ifndef SEAT_H
#define SEAT_H

#include <string>
using namespace std;

class Seat{
	string name;

public:
	Seat();
	void book(string name);
	bool isBooked();
	void cancel(string name);
	void view();
};

#endif