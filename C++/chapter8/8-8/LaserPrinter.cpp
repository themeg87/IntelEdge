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
	if(!print(pages)) // BasePrinter::print() 호출
		return false; // 용지 부족
	if(availableToner < pages) {
		cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
		return false;
	}
	availableToner--;
	cout << "프린트하였습니다. " << endl;
	return true;
}

void LaserPrinter::showState() {
	show(); // BasePrinter::show() 호출
	cout << "남은토너 " << availableToner;
}