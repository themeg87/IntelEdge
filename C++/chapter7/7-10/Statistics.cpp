#include <iostream>
#include <string>
using namespace std;

class Statistics {
	int capacity;
	int size;
	int *p;
public:
	Statistics(int n=10) {
		capacity = 10;
		size = 0;
		p = new int [capacity];
	}
	~Statistics() {
		if(p) delete [] p;
	}

	Statistics& operator << (int n);
	Statistics& operator >> (int& avg);
	bool operator ! ();
	Statistics& operator ~ ();
};

Statistics& Statistics::operator << (int n) {
	if(size == capacity) {
		int* q = new int [capacity*2];
		for(int i=0; i<size; i++) q[i] = p[i];
		capacity *=2;
		delete [] p;
		p = q;
	}
	p[size] = n;
	size++;
	return *this;
}

Statistics& Statistics::operator >> (int& avg) {
	int sum=0;
	for(int i=0; i<size; i++) 
		sum += p[i];

	avg = sum/size;
	return *this;
}

bool Statistics::operator ! () {
	if(size == 0) return true;
	else return false;
}

Statistics& Statistics::operator ~ () {
	for(int i=0; i<size; i++) 
		cout << p[i] << ' ';
	cout << endl;

	return *this;
}

int main() {
	Statistics stat;
	if(!stat) cout << "���� ��� ����Ÿ�� �����ϴ�." << endl;

	int x[5];
	cout << "5 ���� ������ �Է��϶�>>";
	for(int i=0; i<5; i++) cin >> x[i]; // x[i]�� ���� �Է�

	for(int i=0; i<5; i++) stat << x[i]; // x[i] ���� ��� ��ü�� �����Ѵ�.
	stat << 100 << 200; // 100, 200�� ��� ��ü�� �����Ѵ�.
	~stat; // ��� ����Ÿ�� ��� ����Ѵ�.

	int avg;
	stat >> avg;  // ��� ��ü�� ���� ����� �޴´�.
	cout << "avg=" << avg << endl; // ����� ����Ѵ�
}