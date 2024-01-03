#include <iostream>
#include <string>
using namespace std; 

#include "Board.h"

// static 멤버 변수는 반드시 아래와 같이 전역 변수로 선언하여 공간을 생성해주어야 함
// 클래스의 선언은 어떤 멤버가 static 임을 선언하는 데 그치기 때문에
// static 멤버 변수들이 변수 공간을 얻기 위해서는 아래와 같이 전역 변수로 선언해야 함
int Board::size = 0; //static 멤버 변수를 전역 변수로 선언하여 변수 공간 할당
string Board::text[100]; //static 멤버 변수를 전역 변수로 선언하여 배열 공간 할당

void Board::add(string t) {
	if (size > 99)
		return; // 게시판이 꽉 차서 더 이상 추가 못함

	text[size] = t;
	size++;
}

void Board::print() {
	cout << "************* 게시판입니다. *************" << endl;
	for (int i = 0; i < size; i++) {
		cout << i << ": " << text[i] << endl;
	}
	cout << endl;
}

