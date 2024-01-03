#include <iostream>
#include "Dept.h"
using namespace std;

/* 문제 (1)의 정답 : 복사 생성자가 어디서 호출되는가?
	countPass(Dept dept)이 호출될 때, 매개변수인 dept 객체가 생성된다.
	dept가 생성되는 과정은 다음과 같다.
	(1) 먼저 Dept 클래스의 크기만한 객체 공간이 생기고 객체의 이름은 dept가 된다.
	(2) dept 객체에 복사 생성자가 만들어져 있으면 복사 생성자가 호출되고, 
		복사 생성자가 없다면 생성자의 실행없이 원본 com이 그대로 dept에 복사된다.
*/

/* 문제 (2)의 정답 : 복사 생성자가 없으면 왜 실행 오류가 발생하는가?
	앞의 대답에서와 같이, 복사 생성자가 없으면
	countPass(Dept dept)가 호출되어 매개변수인 dept 객체가 생성될 때
	원본 com이 그대로 복사된다. 
	그러므로 com 객체의 멤버 scores가 dept 객체의 멤버 scores에 그대로 복사되어
	두 dept의 scores는 com에서 동적할당받은 scores를 함께 가리키게 된다.
	countPass(Dept dept) 함수가 실행되고 종료되면 dept 객체는 사라진다. 
	이때 dept 객체의 소멸자가 실행되는데, 이 소멸자는 현재 dept의 멤버 변수인
	scores가 가리키는 동적 배열을 모두 반환한다. 사실 dept의 scores 포인터를
	main의 com 객체내에서 동적 할당 받은 배열이다.
	여기까지는 아무 오류도 발생하지 않지만, main() 함수가 종료할 때 지역변수인
	com 객체가 소멸되고 이때 소멸자가 호출된다.
	소멸자는 com 객체내에 scores 포인터가 가리키고 있는 동적 할당된 배열을 반환하는데
	이때 문제가 발생한다. 이 배열은 이미 dept 객체가 소멸될 때 반환해버렸다.
	이미 반환해버린 배열 메모리를 다시 반환하게 되어 실행 오류가 발생한다.
*/

int countPass(Dept dept) { // dept 학과에 60점 이상으로 통과하는 학생의 수 리턴
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10); // 총 10명이 있는 학과 com
	com.read(); // 총 10명의 학생들의 성적을 키보드로부터 읽어 scores 배열에 저장
	int n = countPass(com); // com 학과에 60점 이상으로 통과한 학생의 수를 리턴
	cout << "60점 이상은 " << n << "명";
}