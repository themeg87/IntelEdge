#include <iostream>
#include "Dept.h"
using namespace std;

/* 문제 (3)의 답
	countPass(Dept& dept)의 매개변수를 참조 매개 변수를 사용함으로써
	countPass() 함수가 호출될 때, 매개변수로 주어진 dept 객체가 생성되지 않도록 하면 된다.
	이렇게 하면 복사생성자가 필요없기 때문에 복사생성의 과정 동안 복사되는 시간 소모도 없게 된다.
*/

int countPass(Dept& dept) { // dept 학과에 60점 이상으로 통과하는 학생의 수 리턴
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