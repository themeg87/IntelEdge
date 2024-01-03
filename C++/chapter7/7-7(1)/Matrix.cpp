#include <iostream>
using namespace std;

class Matrix {
	int ar[4];
public:
	Matrix() { for(int i=0; i<4; i++) ar[i] = 0; }
	Matrix(int a1, int a2, int b1, int b2) {
		ar[0] = a1;
		ar[1] = a2;
		ar[2] = b1;
		ar[3] = b2;
	}
	void show() {
		cout << "Matrix = { ";
		for(int i=0; i<4; i++) cout << ar[i] << ' ';
		cout << "}" << endl;
	}
	Matrix& operator >> (int []);
	Matrix& operator << (int []);
};

Matrix& Matrix::operator >> (int m[]) {
	for(int i=0; i<4; i++) 
		m[i] = ar[i];

	return *this;
}

Matrix& Matrix::operator << (int m[]) {
	for(int i=0; i<4; i++) 
		 ar[i] = m[i];

	return *this;
}

int main() {
	Matrix a(4,3,2,1), b;
	int x[4], y[4] = {1,2,3,4};  // 2차원 행렬의 4 개의 원소 값
	a >> x; // a의 각 원소를 배열 x에 복사. x[]는 {4,3,2,1}
	b << y; // 배열 y의 원소 값을 b의 각 원소에 설정

	for(int i=0; i<4; i++) cout << x[i] << ' '; // x[] 출력
	cout << endl;
	b.show();
}