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
	if(!print(pages)) // BasePrinter::print() ȣ��
		return false; // ���� ����
	if(availableInk < pages) {
		cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		return false;
	}
	availableInk-=pages;
	cout << "����Ʈ�Ͽ����ϴ�. " << endl;
	return true;
}

void InkJetPrinter::showState() {
	show(); // BasePrinter::show() ȣ��
	cout << "���� ��ũ " << availableInk;
}