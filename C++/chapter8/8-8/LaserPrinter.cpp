#include <iostream>
#include "BasePrinter.h"
#include "LaserPrinter.h"
using namespace std;

LaserPrinter::LaserPrinter(string model, string manufacturer, int totalPapers,  int totalToner)
	: BasePrinter(model, manufacturer, totalPapers)
{
	this->availableToner = totalToner;
}

bool LaserPrinter::printLaser(int pages) {
	if(!print(pages)) // BasePrinter::print() ȣ��
		return false; // ���� ����
	if(availableToner < pages) {
		cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		return false;
	}
	availableToner--;
	cout << "����Ʈ�Ͽ����ϴ�. " << endl;
	return true;
}

void LaserPrinter::showState() {
	show(); // BasePrinter::show() ȣ��
	cout << "������� " << availableToner;
}