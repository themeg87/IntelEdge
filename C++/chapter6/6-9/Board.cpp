#include <iostream>
#include <string>
using namespace std; 

#include "Board.h"

// static ��� ������ �ݵ�� �Ʒ��� ���� ���� ������ �����Ͽ� ������ �������־�� ��
// Ŭ������ ������ � ����� static ���� �����ϴ� �� ��ġ�� ������
// static ��� �������� ���� ������ ��� ���ؼ��� �Ʒ��� ���� ���� ������ �����ؾ� ��
int Board::size = 0; //static ��� ������ ���� ������ �����Ͽ� ���� ���� �Ҵ�
string Board::text[100]; //static ��� ������ ���� ������ �����Ͽ� �迭 ���� �Ҵ�

void Board::add(string t) {
	if (size > 99)
		return; // �Խ����� �� ���� �� �̻� �߰� ����

	text[size] = t;
	size++;
}

void Board::print() {
	cout << "************* �Խ����Դϴ�. *************" << endl;
	for (int i = 0; i < size; i++) {
		cout << i << ": " << text[i] << endl;
	}
	cout << endl;
}

