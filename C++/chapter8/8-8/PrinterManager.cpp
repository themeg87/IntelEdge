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
	ip->showState();
	cout << endl;

	cout << "������ : ";
	lp->showState();
	cout << endl;

	int printer, pages;
	char conti;
	while(true) {
		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> printer >> pages;
		switch(printer) {
		case 1 : // ��ũ��
			ip->printInkJet(pages);
			break;
		case 2 : // ������
			lp->printLaser(pages);
			break;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}
		ip->showState();
		cout << endl;
		lp->showState();
		cout << endl;
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> conti;
		if(conti == 'y')
			continue;
		else
			break;
	}
}