#include <iostream>
#include <string>
using namespace std;

class Color { // 하나의 색을 나타내는 클래스
	int r, g, b;
public:
	Color() { r = g = b = 0; } // 생성자
	Color(int r, int g, int b) { // 생성자
		this->r = r; this->g = g; this->b = b; 
	}
	void show() { cout << r << ' ' << g << ' ' << b << endl; }
	Color operator +(Color op2); // + 연산자
	bool operator ==(Color op2); // == 연산자
};

Color Color::operator+(Color op2) {
	Color temp;
	temp.r = r + op2.r; // 더한 결과 256보다 크면 자동으로 나머지 남게 됨
	temp.g = g + op2.g;
	temp.b = b + op2.b;
	if (temp.r >= 255) temp.r = 255;
	if (temp.g >= 255) temp.g = 255;
	if (temp.b >= 255) temp.b = 255;

	return temp;
}

bool Color::operator==(Color op2) {
	if (r == op2.r && g == op2.g && b == op2.b)
		return true;
	else
		return false;
}

int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue; // red.+(blue) 호출
	c.show(); // 색 값 출력

	Color fuchsia(255, 0, 255);
	if (c == fuchsia) // c.==(fuchsia) 호출
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";
}