#include <iostream>
#include <string>
using namespace std;

#include "Console.h"

void Console::beep() {
	cout << "\a"; // �ý��� ��Ʈ ����(��) �߻�
}

void Console::write(string msg) {
	cout << msg << endl;
}

char Console::prompt(string msg) {
	char ans;
	cout << msg;
	cin >> ans;
	return ans;
}