#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	friend Circle operator +(int radius, Circle c);
	void show() {
		cout << "radius = " << radius << " �� ��" << endl;
	}
};

Circle operator +(int radius, Circle c) { 
	Circle tmp;
	tmp.radius = radius + c.radius;
	return tmp;
}

int main() {
	Circle a(5), b(4);
	b = 1 + a; // b�� �������� a�� �������� 1�� ���� ������ ����
	a.show();
	b.show();
}