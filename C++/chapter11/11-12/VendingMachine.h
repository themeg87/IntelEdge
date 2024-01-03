#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <string>
using namespace std;

class Engine;
class Container;

class VendingMachine { // Ŀ�� ���Ǳ� ��ü�� �����ϴ� Ŭ����
	Container *con; // Ŀ��, �� ���� ����� �迭�� �����ϱ� ���� ������
	string name; // ���Ǳ� �̸�
	Engine *engine; // ������� Ŀ�� ���� ���ÿ��� ���� ���Ǳ⸦ �ùķ��̼��ϴ� ������ ���� ������
public:
	VendingMachine(string name);
	~VendingMachine();
	void powerOn(); // Ŀ�� ���Ǳ� ����. �� �Լ��� ������ Ŀ�� ���Ǳ� ����
};
#endif