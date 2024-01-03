#include <iostream>
using namespace std;

int main() {
	int ch;
	while((ch=cin.get()) != EOF) {
		if(ch == ';') {
			cin.ignore(100, '\n'); // 한글 문장이 최대 99개의 문자로 입력된다고 가정한다.
			cout << '\n';
		}
		else
			cout << (char)ch;
	}
}