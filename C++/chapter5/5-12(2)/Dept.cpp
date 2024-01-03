#include <iostream>
#include <string>
using namespace std;

#include "Dept.h"

// 문제 (2) 아래의 복사 생성자를 제거하면 실행 오류가 발생한다.
/* Dept::Dept(Dept& src) { // 복사 생성자. 
	size = src.size; // 소소의 크기 복사
	scores = new int[size]; // 소스와 동일한 크기의 배열 생성

	// src 객체를 현재 생성 중인 이 객체 복사
	for (int i = 0; i < size; i++)
		scores[i] = src.scores[i];
}*/

Dept::~Dept() {
	if(scores != NULL)
		delete [] scores;
}

void Dept::read() {
	cout << size << "개 점수 입력>> ";
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
}

bool Dept::isOver60(int index) {
	if (scores[index] > 60) return true;
	else return false;
}
