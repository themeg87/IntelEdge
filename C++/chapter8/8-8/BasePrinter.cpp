#include <iostream>
#include "BasePrinter.h"
using namespace std;


BasePrinter::BasePrinter(string model, string manufacturer, int totalPapers) {
	this->model = model;
	this->manufacturer = manufacturer;
	this->printedCount = 0;
	this->availableCount = totalPapers;
}

bool BasePrinter::print(int pages) {
	if(availableCount < pages) {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		return false;
	}
	printedCount+=pages;
	availableCount-=pages;
	return true;
}

void BasePrinter::show() {
	cout << model+" ," << manufacturer << " ,남은 종이 " << availableCount << "장" << " ,";
}