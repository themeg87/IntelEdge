#include <iostream>
#include <string>
using namespace std;

#include "define.h"
#include "Engine.h"
#include "VendingMachine.h"

VendingMachine::VendingMachine(string name) {
	this->name = name;
	con = new Container[5]; // �� ����
	con[COFFEE].setName("Coffee");
	con[SUGAR].setName("Sugar");
	con[CREAM].setName("CREAM");
	con[WATER].setName("Water");
	con[CUP].setName("Cup");
	engine = new Engine(con); // ���� ����
}

VendingMachine::~VendingMachine() {
	delete engine; // ���� �Ҹ�
	delete [] con; // ������ ��� �� ��ü �Ҹ�
}

void VendingMachine::powerOn() { // ���ǱⰡ ���� ���� �ùķ��̼��ϴ� �Լ�
	cout << "------" << name << "�մϴ�.------" << endl;
	engine->run(); // ���� ���� ��Ŵ
}