#include <iostream>
using namespace std;

#include "Seat.h"

Seat::Seat(){
	name = "";
}

// ����
bool Seat::book(string name){
	if(isBooked()) // ����� �¼��̶�� ����
		return false;
	else {
		this->name = name;
		return true;
	}
}

// ���� Ȯ��
bool Seat::isBooked(){
	if(name.size()==0)
		return false;
	else
		return true;
}

// ���� ���
bool Seat::cancel(string name){
	if(this->name == name) { // ����ϴ� �̸��� �����ϸ�
		this->name = ""; // �̸� ����
		return true; // ��� ����
	}
	else
		return false; // ��� ����
}

// ������ �̸� ���
void Seat::view(){
	if(isBooked())
		cout << name << "\t";
	else
		cout << "--" << "\t";
}