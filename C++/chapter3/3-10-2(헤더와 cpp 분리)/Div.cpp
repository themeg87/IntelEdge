#include <iostream>
using namespace std;

#include "Div.h"

void Div::setValue(int x, int y) {
	a = x; b = y;
}
int Div::calculate() {
	if(b == 0) {
		cout << "0���� ���� �� ����" << endl;
		return -1;
	}
	return a / b;
}