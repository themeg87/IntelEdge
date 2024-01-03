#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

class SelectableRandom {
	bool even;
public:
	SelectableRandom();
	SelectableRandom(bool e); // �Ű������� ¦�� Ȧ�� ����. e�� true �̸� ���� ¦���� �����ϵ��� �۵�
	int next();
	int nextInRange(int low, int high);
};

SelectableRandom::SelectableRandom() { // ����Ʈ even
	even = true; // true �̸� ¦����
	srand((unsigned)time(0)); // ������ seed�� �����Ͽ� �� ������ �ٸ� ���� ���� ������ �Ѵ�.
}

SelectableRandom::SelectableRandom(bool e) {
	even = e; // true �̸� ¦����
	srand((unsigned)time(0)); // ������ seed�� �����Ͽ� �� ������ �ٸ� ���� ���� ������ �Ѵ�.
}

int SelectableRandom::next() {
	while(true) {
		int n = rand();
		if(even) {
			if(n%2 == 0) return n;
		}
		else {
			if(n%2 == 1) return n;
		}
	}

} 
int SelectableRandom::nextInRange(int low, int high) {
    int range=(high-low)+1;
	while(true) {
		int n= low+ (rand() % range); 
		if(even) {
			if(n%2 == 0) return n;
		}
		else {
			if(n%2 == 1) return n;
		}
	}
}

int main() {
	SelectableRandom evenRandom; // ¦�� �����߻���
	cout << "-- 0���� " << RAND_MAX << "������ ¦�� ���� ���� 10 ��--" << endl;
	for(int i=0; i<10; i++) {
		int n = evenRandom.next(); // 0���� RAND_MAX(32767) ������ ������ ¦�� ����
		cout << n << ' ';
	}
	SelectableRandom oddRandom(false); // Ȧ�� �����߻���
	cout << endl << endl << "-- 2���� " << "9 ������ ���� Ȧ�� ���� 10 �� --" << endl;
	for(int i=0; i<10; i++) {
		int n = oddRandom.nextInRange(2, 9); // 2���� 9 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}