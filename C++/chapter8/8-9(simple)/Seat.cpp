#include <iostream>
using namespace std;

#include "Seat.h"

Seat::Seat(){
	name = "";
}

// ����
void Seat::book(string name){
	this->name = name;

}

// ���� Ȯ��
bool Seat::isBooked(){
	if(name.size()==0)
		return false;
	else
		return true;
}

// ���� ���
void Seat::cancel(string name){
	this->name = ""; // �̸� ����
}

// ������ �̸� ���
void Seat::view(){
	if(isBooked())
		cout << name << "\t";
	else
		cout << "---" << "\t";
}