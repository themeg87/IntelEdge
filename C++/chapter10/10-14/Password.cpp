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
	cout << "이름 암호>> ";
	cin >> name >> password;
	passwordMap[name] = password;
}

void PasswordManager::search() {
	string name;
	string inputPassword, storedPassword;
	cout << "이름? ";
	cin >> name;
	while (true) {
		cout << "암호? ";
		cin >> inputPassword;
		storedPassword = passwordMap[name];
		if (inputPassword == storedPassword) {
			cout << "통과!!" << endl;
			break;
		}
		else {
			cout << "실패~~" << endl;
		}

	}
}

bool PasswordManager::checkInputError() {
	if (cin.fail()) { // 정수대신 문자열이 입력되어 오류가 발생하는 경우. 부록 C의 예제 C-1참고
		cin.clear();
		cin.ignore(100, '\n');
		cout << "입력 오류" << endl;
		return true; // 오류 있음
	}
	else
		return false; // 오류 없음
}

void PasswordManager::run() {
	int menu;

	cout << "***** 암호관리 프로그램 " << program << "를 시작합니다 *****" << endl;
	while (true) {
		cout << "삽입:1, 검사:2, 종료:3>> ";
		cin >> menu;

		// 단순하게 작성하려는 경우 다음 2 라인은 호출하지 않아도 됨
		if (checkInputError()) // 메뉴(menu)를 사용자가 숫자를 입력하지 않는 경우, 오류 발생
			continue;
		switch (menu) {
			case 1: add(); break;
			case 2: search(); break;
			case 3: cout << "프로그램을 종료합니다..."; return;
		}
	}
}