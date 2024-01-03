#include <iostream> 
using namespace std; 

#include "Ram.h"

Ram::Ram() {
	size = 100*1024;
	for(int i=0; i<size; i++)
		mem[i] = 0;
}

Ram::~Ram() {
	cout << "�޸� ���ŵ�" << endl;
}

char Ram::read(int address) {
	if(address < 0 || address >= size) {
		cout << "�ּҰ� ������ ����� ���� �߻�" << endl;
		return -1; // �������� �˸��� ��
	}
	return mem[address];
}

void Ram::write(int address, char value) {
	if(address < 0 || address >= size)
		cout << "�ּҰ� ������ ����� ���� �߻�" << endl;
	mem[address] = value;
}