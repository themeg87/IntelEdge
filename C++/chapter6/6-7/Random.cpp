#include <iostream>
#include <ctime>
using namespace std;

class Random {
public:
	 // 항상 다른 랜덤수를 발생시키기 위한 seed를 설정하는 함수
	static void seed() { srand((unsigned)time(0)); } // 씨드 설정
	static int nextInt(int min=0, int max=32767); //min과 max 사이의 랜덤 정수 리턴
	static char nextAlphabet();
	static double nextDouble(); // 0보다 크거나 같고 1보다 적은 실수 리턴 
};

int Random::nextInt(int min, int max) {
	int range = max - min;
	if(range < 0) return -1; // 오류
	int n = rand(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수 발생
	n = (n % (range+1)) + min;
	return n;
}

char Random::nextAlphabet() {
	int n = Random::nextInt()%52; // 알파벳이 26글자, 대소문자 총 52개
	if(n>25) // 대문자 리턴
		return 'A' + (n-26);
	else // 소문자 리턴
		return 'a' + n;
}

double Random::nextDouble() {
	double d = (double)Random::nextInt();
	d = d / (double)RAND_MAX;
	return d;
}

int main() {
	Random::seed();
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
	for(int i=0; i<10; i++) cout << Random::nextInt(1,100) << ' ';
	cout << endl;

	cout << "알파벳을 랜덤하게 10개를 출력합니다" << endl;
	for(int i=0; i<10; i++) cout << Random::nextAlphabet() << ' ';
	cout << endl;

	cout << "랜덤한 실수를 10개를 출력합니다" << endl;
	for(int i=0; i<5; i++) cout << Random::nextDouble() << ' ';
	cout << endl;
	for(int i=0; i<5; i++) cout << Random::nextDouble() << ' ';
	cout << endl;
}
