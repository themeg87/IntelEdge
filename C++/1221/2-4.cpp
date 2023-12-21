#include <string>
#include <iostream>
using namespace std;

int main() {
	string s;
	cout << "로미오>>";
	cin >> s;

	string t;
	cout << "줄리엣>>";
	cin >> t;

	if (s == "가위" && t == "바위")
		cout << "줄리엣 이겼습니다." << endl;
}