#include <iostream>
using namespace std;
#include <string>

#include "AirlineBook.h"
#include "Schedule.h"
#include "Console.h"


// 생성자
AirlineBook::AirlineBook(string name, int nSchedules, string scheduleTime[]){
	this->name = name; // 예약 시스템 이름
	this->nSchedules = nSchedules; // 스케쥴 개수
	sche = new Schedule[nSchedules]; // 3 개의 스케쥴 객체 생성

	// 각 스케쥴에 해당 시간 설정
	for(int i=0; i<nSchedules; i++)
		sche[i].setTime(scheduleTime[i]);
}

// 소멸자
AirlineBook::~AirlineBook(){
	if(sche) 
		delete [] sche;
}

// 예약 시스템을 시작하는 함수
void AirlineBook::run(){
	cout << "***** " << name << "에 오신것을 환영합니다" << " *****" << endl;
	cout << endl;

	while(true){
		int menu = Console::getMainMenu(); // 메인 메뉴 입력
		switch(menu){
			case 1:
				book(); // 예약
				break; 
			case 2:
				cancel(); // 예약
				break; 
			case 3:
				view(); // 예약 보기
				break; 
			case 4:
				cout << "예약 시스템을 종료합니다.\n"<<endl;
				return;
			default:
				cout << "잘못입력하였습니다.\n"<<endl;
		}
		cout << endl;
	}
}

// 스케쥴을 예약한다.
void AirlineBook::book(){
	int s;
	string bookName;
	int seatNo;

	s = Console::getScheduleMenu(); // 사용자가 선택한 스케쥴을 입력 받는다.
	view(s); // 스케쥴 s의 예약 상황을 출력한다.
	seatNo = Console::getSeatNo(); // 좌석 번호를 입력받는다.
	bookName = Console::getName(); // 예약자의 이름을 입력받는다.
	sche[s-1].book(seatNo, bookName); // 해당 스케쥴 예약
}

// 스케쥴을 취소한다.
void AirlineBook::cancel(){
	int s;
	string bookName;
	int seatNo;

	s = Console::getScheduleMenu(); // 사용자가 선택한 스케쥴을 입력 받는다.
	view(s); // 스케쥴 s의 예약 상황을 출력한다.
	seatNo = Console::getSeatNo(); // 좌석 번호를 입력받는다.
	bookName = Console::getName(); // 예약자의 이름을 입력받는다.
	sche[s-1].cancel(seatNo, bookName); // 해당 스케쥴 취소
}

// 현재 모든 스케쥴의 예약 상황을 출력한다.
void AirlineBook::view(){
	for(int i=0;i<3;i++){
		sche[i].view();
	}
}

// 스케쥴 s의 좌석 예약 상황을 출력한다. s는 1,2,3
void AirlineBook::view(int s){
	sche[s-1].view(); //배열의 인덱스는 0부터 시작
}