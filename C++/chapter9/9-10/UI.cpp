#include <iostream>
using namespace std;

#include "UI.h"

int UI::getMainMenu() {
	cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";

	int menu;
	cin >> menu;

	return menu;
}

int UI::getShapeType() {
	cout << "��:1, ��:2, �簢��:3 >> ";

	int shapeType;
	cin >> shapeType;

	return shapeType;
}

int UI::getShapeIndex() {
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";

	int shapeIndex;
	cin >> shapeIndex;

	return shapeIndex;
}

void UI::println(string msg) {
	cout << msg << endl;
}

void UI::print(string msg) {
	cout << msg;
}

void UI::print(int msg) {
	cout << msg;
}