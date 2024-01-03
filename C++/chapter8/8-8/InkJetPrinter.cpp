#include <iostream>
#include "BasePrinter.h"
#include "InkJetPrinter.h"
using namespace std;

InkJetPrinter::InkJetPrinter(string model, string manufacturer, int totalPapers,  int totalInk)
	: BasePrinter(model, manufacturer, totalPapers)
{
	this->availableInk = totalInk;
}

bool InkJetPrinter::printInkJet(int pages) {
	if(!print(pages)) // BasePrinter::print() 호출
		return false; // 용지 부족
	if(availableInk < pages) {
		cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
		return false;
	}
	availableInk-=pages;
	cout << "프린트하였습니다. " << endl;
	return true;
}

void InkJetPrinter::showState() {
	show(); // BasePrinter::show() 호출
	cout << "남은 잉크 " << availableInk;
}