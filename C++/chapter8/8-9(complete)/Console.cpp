#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#include "Console.h"

int Console::getMainMenu(int nMenus){
	while(true) {
		cout << "����:1, ���:2, ����:3, ������:4>> " ;
		string in;
		cin >> in;
		if(in.size() > 1)
			continue; // 0�� �����ϴ� ���, ����� �Է� ����. �ٽ� �Է�
		int menu = getInt(in); // 0�� �����ϴ� ���, ����� �Է� ������
		if(menu >= 1 && menu <= nMenus) // �޴� ���� üũ
			return menu;
	}
}

int Console::getScheduleMenu(int nSchedules){
	while(true) {
		cout << "07��:1, 12��:2, 17��:3>> " ;
		string in;
		cin >> in;
		if(in.size() > 1)
			continue; // 0�� �����ϴ� ���, ����� �Է� ����. �ٽ� �Է�
		int menu = getInt(in); // 0�� �����ϴ� ���, ����� �Է� ������
		if(menu >= 1 && menu <= nSchedules) // �������� ���� üũ
			return menu;
	}
}

string Console::getName(){
	cout << "�̸� �Է�>> ";
	string name;
	cin >> name;
	return name;
}

int Console::getSeatNo(){
	while(true) {
		cout << "�¼� ��ȣ>> " ;
		string in;
		cin >> in;
		int n = getInt(in); // 0�� �����ϴ� ���, ����� �Է� ������
		if(n != 0)
			return n;
	}
}

void Console::print(string msg) {
	cout << msg;
}

int Console::getInt(string in) {
	return atoi(in.data()); // atoi()�� 0�� �����ϸ�, �Է¿� ������ �־���
}