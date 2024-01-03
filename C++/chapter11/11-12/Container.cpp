#include <iostream>
using namespace std;

#include "Container.h"

Container::Container(const char* name, int initialSize) {
	this->name = name;
	size = initialSize;
}

bool Container::consume(int n) { // �뿡�� n �и�ŭ ��� �Ҹ�
	if(size < n) return false;
	size -= n;
	return true;
}

void Container::show() { // �뿡 ���� ���� ��� ���� '*'�� ���
	cout << name + "\t";
	for(int i=0; i<size; i++)
		cout << "*";
	cout << endl;
}