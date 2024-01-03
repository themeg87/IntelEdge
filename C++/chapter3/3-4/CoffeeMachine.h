#ifndef COFFEEMACHINE_H
#define COFFEEMACHINE_H

class CoffeeMachine {
	int coffee, water, sugar; // ��ü Ŀ��, ����, ���� ��
public:
	CoffeeMachine(int c, int w, int s);
	void drinkEspresso(); // Ŀ�� 1, �� 1 �Һ�	
	void drinkAmericano(); // Ŀ�� 1, �� 2 �Һ�
	void drinkSugarCoffee(); // Ŀ�� 1, �� 2, ���� 1 �Һ�
	void fill(); // Ŀ�� 10, �� 10, ���� 10���� ä���
	void show(); // �ܷ� ���
};

#endif