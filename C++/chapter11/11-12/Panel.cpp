#include <iostream>
using namespace std;

#include "define.h"
#include "Panel.h"

int Panel::getButton() {
	int menu;
	cout <<"���� Ŀ��:"<< NORMAL_COFFEE << ", ";
	cout <<"���� Ŀ��:"<< SUGAR_COFFEE << ", ";
	cout <<"�� Ŀ��:"<< BLACK_COFFEE << ", ";
	cout <<"ä���:"<< FILL << ", ";
	cout << "����:" << EXIT << ">> ";

	cin >> menu;
	return menu;
}