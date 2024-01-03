#include <iostream>
#include <string>
using namespace std;

#include "Dept.h"

Dept::Dept(Dept& src) { // ���� ������
	size = src.size; // �Ҽ��� ũ�� ����
	scores = new int[size]; // �ҽ��� ������ ũ���� �迭 ����

	// src ��ü�� ���� ���� ���� �� ��ü ����
	for (int i = 0; i < size; i++)
		scores[i] = src.scores[i];
}

Dept::~Dept() {
	if(scores != NULL)
		delete [] scores;
}

void Dept::read() {
	cout << size << "�� ���� �Է�>> ";
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
}

bool Dept::isOver60(int index) {
	if (scores[index] > 60) return true;
	else return false;
}
