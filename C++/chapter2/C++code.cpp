#include <iostream>
using namespace std;
int sum(int a, int b); // 함수 원형 선언

int main() {
	int n=0;
	cout << "끝 수를 입력하세요>";
	cin >> n;
	if(n <= 0) {
		cout << "양수를 입력하세요!" << endl;
		return 0;
	}
	cout << "1에서 " << n << "까지의 합은 " << sum(1, n) << "입니다." << endl;
	return 0;
}

int sum(int a, int b) {
	int res=0;
	for(int k=a; k<=b; k++) {
		res += k;
	}
	return res;
}