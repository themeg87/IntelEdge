#include <iostream>
using namespace std;

class Comparable {
public:
	virtual bool operator > (Comparable& op2)=0;
	virtual bool operator < (Comparable& op2)=0;
	virtual bool operator == (Comparable& op2)=0;
};

class Circle : public Comparable {
	int radius;
public:
	Circle(int radius=1) { this->radius = radius; }
	int getRadius() { return radius;}

	virtual bool operator > (Comparable& op2) {
		Circle *p = (Circle*)&op2;
		if(radius > p->radius) return true;
		return false;
	}
	virtual bool operator < (Comparable& op2)	{
		Circle *p = (Circle*)&op2;
		if(radius < p->radius)  return true;
		return false;
	}
	virtual bool operator == (Comparable& op2) {
		Circle *p = (Circle*)&op2;
		if(radius == p->radius)  return true;
		return false;
	}
};

template <class T>
T bigger(T a, T b) { // �� ���� �Ű� ������ ���Ͽ� ū ���� ����
	if(a > b) return a; 
	else return b;
}

int main() {
	int a=20, b=50, c;
	c = bigger(a, b);
	cout << "20�� 50�� ū ���� " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle�� pizza �� ū ���� �������� " << y.getRadius() << endl;
}