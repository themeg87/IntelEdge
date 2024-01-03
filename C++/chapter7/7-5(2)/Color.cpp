#include <iostream>
#include <string>
using namespace std;

class Color { // �ϳ��� ���� ��Ÿ���� Ŭ����
	int r, g, b;
public:
	Color() { r = g = b = 0; } // ������
	Color(int r, int g, int b) { // ������
		this->r = r; this->g = g; this->b = b; 
	}
	void show() { cout << r << ' ' << g << ' ' << b << endl; }
	friend Color operator +(Color op1, Color op2); // + ������
	friend bool operator ==(Color op1, Color op2); // == ������
};

Color operator+(Color op1, Color op2) {
	Color temp;
	temp.r = op1.r + op2.r; // ���� ��� 256���� ũ�� �ڵ����� ������ ���� ��
	temp.g = op1.g + op2.g;
	temp.b = op1.b + op2.b;
	if (temp.r >= 255) temp.r = 255;
	if (temp.g >= 255) temp.g = 255;
	if (temp.b >= 255) temp.b = 255;

	return temp;
}

bool operator==(Color op1, Color op2) {
	if (op1.r == op2.r && op1.g == op2.g && op1.b == op2.b)
		return true;
	else
		return false;
}

int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue; // +(red, blue) ȣ��
	c.show(); // �� �� ���

	Color fuchsia(255, 0, 255);
	if (c == fuchsia) // ==(c, fuchsia) ȣ��
		cout << "����� ����";
	else
		cout << "����� �ƴ�";
}