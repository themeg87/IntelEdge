#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity;
	int *mem;
protected:
	BaseArray(int capacity=100) {
		this->capacity = capacity; mem = new int [capacity];
	}
	~BaseArray() { delete [] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {
	int tos; // ������ push �� ��ġ. ���ÿ� ����ִ� ������ ����
public:
	MyStack(int capacity);
	void push(int n);
	int pop();
	int length() { return tos; }
	int capacity() { return getCapacity(); }
};

MyStack::MyStack(int capacity) : BaseArray(capacity) {
	tos = 0; // tos�� ���� ���ÿ� ��� �ִ� ������ �ٷ������ �ȴ�.
}

void MyStack::push(int n) {
	if(tos == capacity())
		return; // stack full error
	put(tos, n);
	tos++;
}

int MyStack::pop() {
	if(tos == 0)
		return -1; // stack empty error
	tos--;
	return get(tos);
}

int main() {
	MyStack mStack(100);
	int n;
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for(int i=0; i<5; i++) {
		cin >> n;
		mStack.push(n); // ���ÿ� Ǫ��
	}
	cout << "���� �뷮:" << mStack.capacity() << ", ���� ũ��:" << mStack.length() << endl; 
	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
	while(mStack.length() != 0) {
		cout << mStack.pop() << ' '; // ���ÿ��� ��
	}
	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}