#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

class SelectableRandom {
	bool even;
public:
	SelectableRandom();
	SelectableRandom(bool e); // 매개변수로 짝수 홀수 선택. e가 true 이면 랜덤 짝수만 리턴하도록 작동
	int next();
	int nextInRange(int low, int high);
};

SelectableRandom::SelectableRandom() { // 디폴트 even
	even = true; // true 이면 짝수만
	srand((unsigned)time(0)); // 임의의 seed를 설정하여 할 때마다 다른 랜덤 수가 나오게 한다.
}

SelectableRandom::SelectableRandom(bool e) {
	even = e; // true 이면 짝수만
	srand((unsigned)time(0)); // 임의의 seed를 설정하여 할 때마다 다른 랜덤 수가 나오게 한다.
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
	SelectableRandom evenRandom; // 짝수 랜덤발생기
	cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10 개--" << endl;
	for(int i=0; i<10; i++) {
		int n = evenRandom.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 짝수 정수
		cout << n << ' ';
	}
	SelectableRandom oddRandom(false); // 홀수 랜덤발생기
	cout << endl << endl << "-- 2에서 " << "9 까지의 랜덤 홀수 정수 10 개 --" << endl;
	for(int i=0; i<10; i++) {
		int n = oddRandom.nextInRange(2, 9); // 2에서 9 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;
}