#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
using namespace std;

class Seat;

class Schedule{
	string time; // ������ Ÿ��
	Seat* seat;
public:
	Schedule();
	~Schedule();
	void book(int no, string name);
	void cancel(int no, string name);
	void view();
	void setTime(string time);
};

#endif