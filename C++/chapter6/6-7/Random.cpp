#include <iostream>
#include <ctime>
using namespace std;

class Random {
public:
	 // �׻� �ٸ� �������� �߻���Ű�� ���� seed�� �����ϴ� �Լ�
	static void seed() { srand((unsigned)time(0)); } // ���� ����
	static int nextInt(int min=0, int max=32767); //min�� max ������ ���� ���� ����
	static char nextAlphabet();
	static double nextDouble(); // 0���� ũ�ų� ���� 1���� ���� �Ǽ� ���� 
};

int Random::nextInt(int min, int max) {
	int range = max - min;
	if(range < 0) return -1; // ����
	int n = rand(); // 0���� RAND_MAX(32767) ������ ������ ���� �߻�
	n = (n % (range+1)) + min;
	return n;
}

char Random::nextAlphabet() {
	int n = Random::nextInt()%52; // ���ĺ��� 26����, ��ҹ��� �� 52��
	if(n>25) // �빮�� ����
		return 'A' + (n-26);
	else // �ҹ��� ����
		return 'a' + n;
}

double Random::nextDouble() {
	double d = (double)Random::nextInt();
	d = d / (double)RAND_MAX;
	return d;
}

int main() {
	Random::seed();
	cout << "1���� 100���� ������ ���� 10���� ����մϴ�" << endl;
	for(int i=0; i<10; i++) cout << Random::nextInt(1,100) << ' ';
	cout << endl;

	cout << "���ĺ��� �����ϰ� 10���� ����մϴ�" << endl;
	for(int i=0; i<10; i++) cout << Random::nextAlphabet() << ' ';
	cout << endl;

	cout << "������ �Ǽ��� 10���� ����մϴ�" << endl;
	for(int i=0; i<5; i++) cout << Random::nextDouble() << ' ';
	cout << endl;
	for(int i=0; i<5; i++) cout << Random::nextDouble() << ' ';
	cout << endl;
}
