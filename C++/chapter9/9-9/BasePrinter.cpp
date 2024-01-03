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
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		return false;
	}
	printedCount+=pages;
	availableCount-=pages;
	return true;
}

void BasePrinter::show() {
	cout << model+" ," << manufacturer << " ,���� ���� " << availableCount << "��" << " ,";
}