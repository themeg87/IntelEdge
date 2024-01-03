#include <iostream>
#include "PrinterManager.h"
using namespace std;

PrinterManager::PrinterManager() {
	ip = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	lp = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);
}

PrinterManager::~PrinterManager() {
	delete ip;
	delete lp;
}

void PrinterManager::operate() {
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	cout << "��ũ�� : ";
	ip->show();
	cout << endl;

	cout << "������ : ";
	lp->show();
	cout << endl;

	int printer, pages;
	char conti;
	while(true) {
		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> printer >> pages;
		switch(printer) {
		case 1 : // ��ũ��
			ip->print(pages);
			break;
		case 2 : // ������
			lp->print(pages);
			break;
		}
		ip->show();
		cout << endl;
		lp->show();
		cout << endl;
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> conti;
		if(conti == 'y')
			continue;
		else
			break;
	}
}