#include <iostream>
using namespace std;

#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine(int c, int w, int s) {
	coffee = c;
	water = w;
	sugar = s;
}
void CoffeeMachine::drinkEspresso() { // Ŀ�� 1, �� 1 �Һ�
	if (coffee < 1 || water < 1)
		return;
	// Ŀ�� 1, �� 1 �Һ�	
	coffee--;
	water--;
}
void CoffeeMachine::drinkAmericano() { // Ŀ�� 1, �� 2 �Һ�
	if (coffee < 1 || water < 2)
		return;

	// Ŀ�� 1, �� 2 �Һ�
	coffee--;
	water-=2;
}
void CoffeeMachine::drinkSugarCoffee() {// Ŀ�� 1, �� 2, ���� 1 �Һ�
	if (coffee < 1 || water < 2 || sugar < 1)
		return;

	// Ŀ�� 1, �� 2, ���� 1 �Һ�
	coffee--;
	water -= 2;
	sugar--;

}
void CoffeeMachine::fill() { // Ŀ�� 10, �� 10, ���� 10���� ä���
	coffee = 10;
	water = 10;
	sugar = 10;
}

void CoffeeMachine::show() { // �ܷ� ���
	cout << "Ŀ�� �ӽ� ����, Ŀ��:" << coffee << "\t";
	cout << "��:" << water << "\t";
	cout << "����:" << sugar << "\t" << endl;
}