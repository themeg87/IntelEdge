#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;

	cout << "문자열 입력>> ";
	getline(cin, text); // 빈 칸을 포함하는 문자열 한 라인 입력

	int count = 0;
	int index = 0;
	while (true) {
		index = text.find('a', index); // index부터 'a' 찾기
		if (index == -1)
			break;
		count++;	
		index++; // 현재 찾은 바로 다음 위치부터 찾기 위해
	}
	cout << "문자 a는 " << count << "개 있습니다. " << endl;
}