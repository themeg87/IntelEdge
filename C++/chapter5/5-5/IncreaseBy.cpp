// 문제에 주어진 코드는 x의 반지름을 15로 만들지 못한다.
// 코드를 다음과 같이 수정하여야 한다.

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int r) {radius = r;};
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "반지름이 " << radius << "인 원" << endl; }
};

void increaseBy(Circle& a, Circle b) { // 참조 매개 변수 사용
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}

int main() {
	Circle x(10), y(5);
	increaseBy(x, y); // x의 반지름이 15인 원을 만들고자 한다.
	x.show();
}