#include <iostream>
#include <string>
using namespace std;

class DebugInfo { // 하나의 디버깅 정보 저장
public:
	string tag; // 개발자 스스로 디버깅 정보를 구분하기위한 태그
	string comment; // 개발자가 기록하는 디버깅 정보
};
class Trace {
	Trace() {} // private으로 하여 외부에서는 Trace 객체를 생성할 수 없게 함
	static int index; // info 배열에 기록할 다음 위치
	static DebugInfo info[1000]; // 최대 1000 개의 디버깅 정보를 담는다.
public:
	static void put(string tag, string comment);
	static void print(string tag=""); // tag에 해당하는 디버깅 정보 출력
};

void Trace::put(string tag, string comment) {
	if(index == 1000) {
		cout << "Trace 메모리 full" << endl;
		return;
	}
	DebugInfo a;
	a.tag = tag;
	a.comment = comment;
	info[index] = a;
	index++;
}

void Trace::print(string tag) {
	if(tag.length() == 0) { // 모든 태그의 Trace 출력
		cout << "----- 모든 Trace 정보를 출력합니다. -----" << endl;
		for(int i=0; i<index; i++) {
			DebugInfo a = info[i];
			cout << a.tag << ":" << a.comment << endl;
		}
	}
	else {
		cout << "----- " << tag << "태그의 Trace 정보를 출력합니다. -----" << endl;
		for(int i=0; i<index; i++) {
			DebugInfo a = info[i];
			if(a.tag == tag)
			cout << a.tag << ":" << a.comment << endl;
		}
	}
}

int Trace::index = 0; // 초기화 반드시 필요
DebugInfo Trace::info[1000]; // 초기화 반드시 필요

void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}
int main() {
	Trace::put("main()", "프로그램 시작합니다");
	f();
	Trace::put("main()", "종료"); // put()의 첫 번째 매개 변수는 태그이고 두 번째 매개변수는 디버깅 정보이다.
	Trace::print("f()"); // "f()" 태그를 가진 디버깅 정보를 모두 출력한다.
	Trace::print(); // 모든 디버깅 정보를 출력한다.
}