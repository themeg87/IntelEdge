#include <iostream>
using namespace std;
#include <string>
#include <cstring>

#include "Console.h"

int Console::getMainMenu(){
	cout << "����:1, ���:2, ����:3, ������:4>> " ;
	int menu;
	cin >> menu;
	return menu;
}

int Console::getScheduleMenu(){
	cout << "07��:1, 12��:2, 17��:3>> " ;
	int menu;
	cin >> menu;
	return menu;
}

string Console::getName(){
	cout << "�̸� �Է�>> ";
	string name;
	cin >> name;
	return name;
}

int Console::getSeatNo(){
	cout << "�¼� ��ȣ>> " ;
	int no;
	cin >> no;
	return no;
}

void Console::print(string msg) {
	cout << msg;
}