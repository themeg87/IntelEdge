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
	friend Matrix& operator >> (Matrix&, int []);
	friend Matrix& operator << (Matrix&, int []);
};

Matrix& operator >> (Matrix& matrix, int m[]) {
	for(int i=0; i<4; i++) 
		m[i] = matrix.ar[i];

	return matrix;
}

Matrix& operator << (Matrix& matrix, int m[]) {
	for(int i=0; i<4; i++) 
		 matrix.ar[i] = m[i];

	return matrix;
}

int main() {
	Matrix a(4,3,2,1), b;
	int x[4], y[4] = {1,2,3,4};  // 2���� ����� 4 ���� ���� ��
	a >> x; // a�� �� ���Ҹ� �迭 x�� ����. x[]�� {4,3,2,1}
	b << y; // �迭 y�� ���� ���� b�� �� ���ҿ� ����

	for(int i=0; i<4; i++) cout << x[i] << ' '; // x[] ���
	cout << endl;
	b.show();
}