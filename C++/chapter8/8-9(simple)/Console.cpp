#include <iostream>
using namespace std;
#include <string>
#include <cstring>

#include "Console.h"

int Console::getMainMenu(){
	cout << "예약:1, 취소:2, 보기:3, 끝내기:4>> " ;
	int menu;
	cin >> menu;
	return menu;
}

int Console::getScheduleMenu(){
	cout << "07시:1, 12시:2, 17시:3>> " ;
	int menu;
	cin >> menu;
	return menu;
}

string Console::getName(){
	cout << "이름 입력>> ";
	string name;
	cin >> name;
	return name;
}

int Console::getSeatNo(){
	cout << "좌석 번호>> " ;
	int no;
	cin >> no;
	return no;
}

void Console::print(string msg) {
	cout << msg;
}