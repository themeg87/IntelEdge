#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() {
		cout << "radius = " << radius << " �� ��" << endl;
	}

	friend Circle& operator ++(Circle& c);
	friend Circle operator ++(Circle& c, int x);
};

Circle& operator ++(Circle& c) { // ���� ++. ++a�� ����
	c.radius++;
	return c;
}

Circle operator ++(Circle& c, int x) { // ���� ++. a++�� ����
	Circle tmp = c;
	c.radius++;
	return tmp;
}

int main() {
	Circle a(5), b(4);
	++a; // �������� 1 ���� ��Ų��.
	b = a++; // �������� 1 ���� ��Ų��.
	a.show();
	b.show();
}