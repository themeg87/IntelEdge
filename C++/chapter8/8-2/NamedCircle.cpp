#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius=0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; };
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius, string name);
	void set(int radius, string name){
		setRadius(radius);
		this->name = name;
	}
	string getName() { return name; }
	void show();
};

NamedCircle::NamedCircle(int radius=0, string name="NONAME") : Circle(radius) {
	this->name = name;
}

void NamedCircle::show() {
	cout << "�������� " << getRadius() << "�� " << name << endl;
}

string biggest(NamedCircle p[], int n) {
	if(n<=0)
		return ""; // ����

	int big = 0;
	for(int i=1; i<n; i++) {
		if(p[i].getRadius() > p[big].getRadius())
			big = i;
	}

	return p[big].getName();
}

int main() {
	NamedCircle c[5];
	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	for(int i=0; i<5; i++) {
		int r;
		string name;
		cout << i+1 << ">> ";
		cin >> r;
		getline(cin, name);
		if(r <= 0) {
			cout << "�ٽ� �Է��ϼ���" << endl;
			i--;
			continue;
		}

		c[i].set(r, name);
	}
	cout << "���� ������ ū ���ڴ� " << biggest(c, 5) << "�Դϴ�" << endl;
}