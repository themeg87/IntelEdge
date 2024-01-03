#include <iostream>
#include <string>
#include <map>
using namespace std;

#include "Password.h"

PasswordManager::PasswordManager(string program) {
	this->program = program;
}

void PasswordManager::add() {
	string name;
	string password;
	cout << "�̸� ��ȣ>> ";
	cin >> name >> password;
	passwordMap[name] = password;
}

void PasswordManager::search() {
	string name;
	string inputPassword, storedPassword;
	cout << "�̸�? ";
	cin >> name;
	while (true) {
		cout << "��ȣ? ";
		cin >> inputPassword;
		storedPassword = passwordMap[name];
		if (inputPassword == storedPassword) {
			cout << "���!!" << endl;
			break;
		}
		else {
			cout << "����~~" << endl;
		}

	}
}

bool PasswordManager::checkInputError() {
	if (cin.fail()) { // ������� ���ڿ��� �ԷµǾ� ������ �߻��ϴ� ���. �η� C�� ���� C-1����
		cin.clear();
		cin.ignore(100, '\n');
		cout << "�Է� ����" << endl;
		return true; // ���� ����
	}
	else
		return false; // ���� ����
}

void PasswordManager::run() {
	int menu;

	cout << "***** ��ȣ���� ���α׷� " << program << "�� �����մϴ� *****" << endl;
	while (true) {
		cout << "����:1, �˻�:2, ����:3>> ";
		cin >> menu;

		// �ܼ��ϰ� �ۼ��Ϸ��� ��� ���� 2 ������ ȣ������ �ʾƵ� ��
		if (checkInputError()) // �޴�(menu)�� ����ڰ� ���ڸ� �Է����� �ʴ� ���, ���� �߻�
			continue;
		switch (menu) {
			case 1: add(); break;
			case 2: search(); break;
			case 3: cout << "���α׷��� �����մϴ�..."; return;
		}
	}
}