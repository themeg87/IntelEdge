#include <iostream>
using namespace std;

class MyIntStack {
	int *p; // ���� �޸𸮷� ����� ������
	int size; // ������ �ִ� ũ��
	int tos; // ������ ž�� ����Ű�� �ε���
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s);
	~MyIntStack();

	bool push(int n); // ���� n�� ���ÿ� Ǫ���Ѵ�.
			// ������ �� �� ������ false��, �ƴϸ� true ����
	bool pop(int &n); // ������ ž�� �ִ� ���� n�� ���Ѵ�. 
			// ���� ������ ��� ������ false��, �ƴϸ� true ����
};

MyIntStack::MyIntStack() { 
	size = 10; 
	tos = 0;
	p = new int [size]; // ���� �޸� �Ҵ�
}

MyIntStack::MyIntStack(int size) {
	this->size = size;
	tos = 0;
	p = new int [size]; // ���� �޸� �Ҵ�
}

MyIntStack::~MyIntStack() {
	if(p) 
		delete [] p; //���� �޸� ��ȯ
}

MyIntStack::MyIntStack(MyIntStack& src) {
	size = src.size;
	tos = src.tos;
	p = new int [size];
	for(int i=0; i<size; i++)
		p[i] = src.p[i]; // ���� ��ü�� �޸� ����
}

bool MyIntStack::push(int n) {
	if(tos == size) 
		return false; // stack full
	p[tos] = n;
	tos++;
	return true;
}

bool MyIntStack::pop(int& n) {
	if(tos == 0)
		return false; // stack empty
	tos--;
	n = p[tos];
	return true;
}

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);

	MyIntStack b = a; // ���� ����
	b.push(30);

	int n;
	a.pop(n);	// ���� a ��
	cout << "���� a���� ���� �� " << n << endl;
	b.pop(n); // ���� b ��
	cout <<  "���� b���� ���� �� " << n << endl;
}