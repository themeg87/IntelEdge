#ifndef AIRLINEBOOK_H
#define AIRLINEBOOK_H

#include <string>
using namespace std;

class Schedule;

class AirlineBook{
	string name;
	int nSchedules; // ������ ����
	Schedule *sche; // ������ �迭

	void book();
	void cancel();
	void view();
	void view(int s);
public:
	AirlineBook(string name, int nSchedules, string scheduleTime []);
	~AirlineBook();
	void run();
};

#endif