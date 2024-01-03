#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

// ¦���� �����ϰ� �߻���Ű�� Ŭ����
class EvenRandom {
public:
	EvenRandom(); // seed ����
	int next(); // ���� ¦�� ����
	int nextInRange(int low, int high); // low�� high ������ ���� ¦�� ����
};

EvenRandom::EvenRandom() {
	srand((unsigned)time(0)); // ������ seed�� �����Ͽ� �� ������ �ٸ� ���� ���� ������ �Ѵ�.
}

int EvenRandom::next() {
	while(true) {
		int n = rand();
		if(n%2 == 0) return n;
	}
} 

int EvenRandom::nextInRange(int low, int high) {
    int range=(high-low)+1;
	while(true) {
		int n= low + (rand() % range); 
		if(n%2 == 0) return n;
	}
}

int main() {
	EvenRandom r;
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for(int i=0; i<10; i++) {
		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "10 ������ ���� ���� 10 �� --" << endl;
	for(int i=0; i<10; i++) {
		int n = r.nextInRange(2, 10); // 2���� 10 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}