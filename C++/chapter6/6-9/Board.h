#ifndef BOARD_H
#define BOARD_H

#include <string>
using namespace std;

class Board {
	static int size;
	static string text[100];
	Board() {} // private���� �����Ͽ� �ܺο��� Board ��ü�� ������ �� ������ ��
public:
	static void add(string text);
	static void print();
};

#endif
