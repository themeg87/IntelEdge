#include <iostream>
using namespace std;

#include "Seat.h"

Seat::Seat(){
	name = "";
}

// 예약
void Seat::book(string name){
	this->name = name;

}

// 예약 확인
bool Seat::isBooked(){
	if(name.size()==0)
		return false;
	else
		return true;
}

// 예약 취소
void Seat::cancel(string name){
	this->name = ""; // 이름 삭제
}

// 예약자 이름 출력
void Seat::view(){
	if(isBooked())
		cout << name << "\t";
	else
		cout << "---" << "\t";
}