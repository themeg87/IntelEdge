#include <iostream>
#include "BasePrinter.h"
#include "LaserPrinter.h"
using namespace std;

LaserPrinter::LaserPrinter(string model, string manufacturer, int totalPapers,  int totalToner)
	: BasePrinter(model, manufacturer, totalPapers)
{
	this->availableToner = totalToner;
}

bool LaserPrinter::print(int pages) {
	if(!BasePrinter::print(pages)) // BasePrinter::print() ȣ��
		return false; // ���� ����
	if(availableToner < pages) {
		cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		return false;
	}
	availableToner--;
	cout << "����Ʈ�Ͽ����ϴ�. " << endl;
	return true;
}

void LaserPrinter::show() {
	BasePrinter::show(); // BasePrinter::show() ȣ��
	cout << "������� " << availableToner;
}