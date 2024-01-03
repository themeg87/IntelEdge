#include <iostream>
using namespace std;

class Circle {
private:
	int radius; 
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
}; 

void swap(Circle &a, Circle &b) {
	Circle tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	Circle a(1), b(2);
	cout << "a�� ���� = " << a.getArea() << ", b�� ���� = " << b.getArea() << endl;
	swap(a, b);
	cout << "a�� ���� = " << a.getArea() << ", b�� ���� = " << b.getArea() << endl;
}