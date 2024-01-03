#include <iostream>
#include <string>
using namespace std;

class Point { 
	int x, y;
public:
	Point(int x, int y) {
		this->x = x; this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point {
	string color;
public:
	ColorPoint() : Point(0,0) {
		this->color = "BLACK";
	}

	ColorPoint(int x, int y) : Point(x, y) {
		this->color = "BLACK";
	}

	ColorPoint(int x, int y, string color) : Point(x, y) {
		this->color = color;
	}

	void setPoint(int x, int y) {
		move(x, y);
	}

	void setColor(string color) {
		this->color = color;
	}

	void show() {
		cout << color << "색으로 " << '(' << getX() << ',' << getY() << ')' << "에 위치한 점입니다." << endl;
	}
};

int main() {
	ColorPoint zeroPoint; // BLACK에 (0, 0) 위치의 점
	zeroPoint.show(); // zeroPoint를 출력한다. 

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show(); // cp를 출력한다.
}