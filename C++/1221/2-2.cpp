#include <iostream>

double area(int r);			//함수원형 선언

int main() {				//메인함수
	std::cout << "면적은 " << area(5); // 함수 area()의 리턴 값 출력
}

double area(int r) {		//함수 구현
	return 3.14 * r * r;	//반지름 r의 원면적 리턴
}