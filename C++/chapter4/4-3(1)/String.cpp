#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;

	cout << "문자열 입력>> ";
	getline(cin, text); // 빈 칸을 포함하는 문자열 한 라인 입력

	int count = 0;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == 'a') // if (text.at(i) == 'a') 로 해도 됨
			count++;
	}

	cout << "문자 a는 " << count << "개 있습니다. " << endl;
}