#include <iostream>
using namespace std;

class Stack {
	int size;
	int* mem; // ���� �޸� �Ҵ�. ���� ����
	int tos; // top of stack. -1�̸� ������ �����
public:
	Stack(int size = 10) {
		this->size = size;
		mem = new int [size]; // int [10] ���� �Ҵ�.
		tos = -1; // ������ �������
	}
	~Stack() { delete [] mem; } // �迭 ��ȯ
	Stack& operator << (int n);
	Stack& operator >> (int& n);
	bool operator ! ();
};

Stack& Stack::operator << (int n) { // Ǫ��
	if(tos == size-1) {
		return *this;
	}
	tos++; // ���� ž�� ����
	mem[tos] = n;
	return *this;
} 

Stack& Stack::operator >> (int& n) { // ��
	if(tos == -1) {
		return *this;
	} 
	n = mem[tos]; // top�� �ִ� ���� �� ����
	tos--; // ���� top ����
	return *this;
} 

bool Stack::operator ! () { // ��� ������ true ����
	if(tos == -1)
		return true;
	else
		return false;
}

int main() {
	Stack stack;
	stack << 3 << 5 << 10; // 3, 5, 10�� ������� Ǫ��
	while(true) {
		if(!stack) break; // ���� empty
		int x;
		stack >> x; // ������ ž�� �ִ� ���� ��
		cout << x << ' ';
	}
	cout << endl;
}

/* ������ ���� �׽�Ʈ�ص� ��
int main() {
	Stack stack;
	stack << 3 << 5 << 10; // 3, 5, 10�� ������� Ǫ��

	int a,b,c;
	stack >> a >> b >> c; // a=10, b=5, c=3�� ��

	cout << a << ' ' << b << ' ' << c; // 10 5 3 ���
}
*/