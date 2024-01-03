#include <iostream>
using namespace std;

/*
	������ �־��� Ŭ���� �ڵ�

class MyVector{
	int *mem;
	int size;
public:
	MyVector();
	MyVector(int n, int val);
	~MyVector() { delete [] mem; }
};

MyVector::MyVector() { 
	mem = new int [100]; 
	size = 100;
	for(int i=0; i<size; i++) mem[i] = 0;
}

MyVector::MyVector(int n, int val)  { 
	mem = new int [n]; 
	size = n;
	for(int i=0; i<size; i++) mem[i] = val;
}

*/

class MyVector{
	int *mem;
	int size;
public:
	MyVector(int n=100, int val=0);
	~MyVector() { delete [] mem; }

	void show() { 
		for(int i=0; i<size; i++) cout << mem[i] << ' ';
		cout << endl;
	}
};

MyVector::MyVector(int n, int val)  { 
	mem = new int [n]; 
	size = n;
	for(int i=0; i<size; i++) mem[i] = val;
}



int main() {
	MyVector a; // a(100, 0);�� ����
	MyVector b(10, 3);

	a.show(); // 100���� 0�� ���
	b.show(); // 10���� 3�� ���
}