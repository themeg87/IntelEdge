#include <iostream>
#include <string>
using namespace std;

#include "CoffeeVendingMachine.h"

void CoffeeVendingMachine::fill() { // 3���� ���� ��� ä��
	for (int i = 0; i < 3; i++)
		tong[i].fill(10);
	show();
}
void CoffeeVendingMachine::selectEspresso() { // ���������Ҹ� ������ ���, Ŀ�� 1, �� 1 �Ҹ�
	if (tong[0].getSize() > 0 && tong[1].getSize() > 0) {
		tong[0].consume(1); // Ŀ�� ����
		tong[1].consume(1); // �� ����
		cout << "���������� �弼��" << endl;
	}
	else {
		cout << "��ᰡ �����մϴ�" << endl;
	}
}
void CoffeeVendingMachine::selectAmericano() { // �Ƹ޸�ī�븦 ������ ���,  Ŀ�� 1, �� 2 �Ҹ�
	if (tong[0].getSize() > 0 && tong[1].getSize() > 1) {
		tong[0].consume(1); // Ŀ�� ����
		tong[1].consume(2); // �� ����
		cout << "�Ƹ޸�ī�� �弼��" << endl;
	}
	else {
		cout << "��ᰡ �����մϴ�" << endl;
	}
}
void CoffeeVendingMachine::selectSugarCoffee() { // ����Ŀ�Ǹ� ������ ���, Ŀ�� 1, �� 2 �Ҹ�, ���� 1 �Ҹ�
	if (tong[0].getSize() > 0 && tong[1].getSize() > 1 && tong[2].getSize() > 0) {
		tong[0].consume(1); // Ŀ�� ����
		tong[1].consume(2); // �� ����
		tong[2].consume(1); // ���� ����
		cout << "����Ŀ�� �弼��" << endl;
	}
	else {
		cout << "��ᰡ �����մϴ�" << endl;
	}
}
void CoffeeVendingMachine::show() {
	cout << "Ŀ�� " << tong[0].getSize() << ", ";
	cout << "�� " << tong[1].getSize() << ", ";
	cout << "���� " << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::run() {
	cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;
	
	while (true) {
		cout << "�޴��� �����ּ���(1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���)>> ";
		int menu;
		cin >> menu;
		if (checkInputError()) // �޴��� ���� ��� ���ڸ� �Է��� ��츦 �߰��ϰ� ó�� 
			continue;
		switch (menu) {
			case 1: selectEspresso(); break;
			case 2: selectAmericano(); break;
			case 3: selectSugarCoffee(); break;
			case 4: show(); break;
			case 5: fill(); break;
			default: cout << "�߸� �����̽��ϴ�." << endl;
		}
	}
}

bool CoffeeVendingMachine::checkInputError() {
	if (cin.fail()) { // ������� ���ڿ��� �ԷµǾ� ������ �߻��ϴ� ��� ��ó. �η� C�� ���� C-1����
		cin.clear();
		cin.ignore(100, '\n');
		cout << "�Է� ����" << endl;
		return true; // ���� ����
	}
	else
		return false; // ���� ����
}