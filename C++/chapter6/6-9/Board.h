#ifndef BOARD_H
#define BOARD_H

#include <string>
using namespace std;

class Board {
	static int size;
	static string text[100];
	Board() {} // private으로 선언하여 외부에서 Board 객체를 생성할 수 없도록 함
public:
	static void add(string text);
	static void print();
};

#endif
