#include <iostream>
using namespace std;

#include "Seat.h"
#include "Schedule.h"

Schedule::Schedule(){
	seat = new Seat[8]; // 8���� �¼�
	time = ""; // �ʱ�ȭ
}

Schedule::~Schedule(){
	if(seat)
		delete [] seat;
}

void Schedule::setTime(string time) { // ������ �ð� ����
	this->time = time;
}

void Schedule::view(){
	cout << time << ":\t";
	for(int i=0; i<8; i++)
		seat[i].view();
	cout << endl;
}

bool Schedule::book(int no, string name){
	if(no >= 1 && no <= 8) { // �¼� ���� Ȯ��
		return seat[no-1].book(name);
	}
	else
		return false;
}

bool Schedule::cancel(int no, string name){
	if(no >= 1 && no <= 8) { // �¼� ���� Ȯ��
		return seat[no-1].cancel(name);
	}
	else
		return false;
}