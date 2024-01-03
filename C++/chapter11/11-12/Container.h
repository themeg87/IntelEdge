#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
using namespace std;

#include "define.h"

class Container { // ���� ǥ���ϴ� Ŭ����
	string name;
	int size; // ���� ũ��
public:
	Container(const char* name="", int initialSize=MAXSIZE);
	bool consume(int n=1); // ��� �Һ�
	void fill() { size = MAXSIZE; } // ��� ä���
	int getSize() { return size; } // ���� ���� ����� �� ����
	bool isEmpty() { 	return size==0?true:false; }
	bool isFull() { return size==MAXSIZE?true:false; }
	void put() { size++; } // ��� �� 1 ����
	void setName(string name) { this->name = name; }
	void show(); // ���� ��Ȳ ���
};

#endif