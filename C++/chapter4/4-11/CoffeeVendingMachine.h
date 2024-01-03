#ifndef COFFEEVENDINGMACHINE_H
#define COFFEEVENDINGMACHINE_H

#include "Container.h"

class CoffeeVendingMachine { // Ŀ�� ���Ǳ⸦ ǥ���ϴ� Ŭ����
	Container tong[3]; // tong[0]�� Ŀ��, tong[1]�� ��, tong[2]�� �������� ��Ÿ��
	void fill(); // 3���� ���� ��� 10���� ä��
	void selectEspresso(); // ���������Ҹ� ������ ���, Ŀ�� 1, �� 1 �Ҹ�
	void selectAmericano(); // �Ƹ޸�ī�븦 ������ ���,  Ŀ�� 1, �� 2 �Ҹ�
	void selectSugarCoffee(); // ����Ŀ�Ǹ� ������ ���, Ŀ�� 1, �� 2 �Ҹ�, ���� 1 �Ҹ�
	void show(); // ���� Ŀ��, ��, ������ �ܷ� ���
	bool checkInputError(); // ���� ó���� ���� �߰��� ��� �Լ�
public:
	void run(); // Ŀ�� ���Ǳ� �۵�
};

#endif
