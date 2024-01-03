#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

// 짝수만 랜덤하게 발생시키는 클래스
class EvenRandom {
public:
	EvenRandom(); // seed 설정
	int next(); // 랜덤 짝수 리턴
	int nextInRange(int low, int high); // low와 high 사이의 랜덤 짝수 리턴
};

EvenRandom::EvenRandom() {
	srand((unsigned)time(0)); // 임의의 seed를 설정하여 할 때마다 다른 랜덤 수가 나오게 한다.
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
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for(int i=0; i<10; i++) {
		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "10 까지의 랜덤 정수 10 개 --" << endl;
	for(int i=0; i<10; i++) {
		int n = r.nextInRange(2, 10); // 2에서 10 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;
}