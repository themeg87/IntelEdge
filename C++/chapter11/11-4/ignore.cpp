#include <iostream>
using namespace std;

int main() {
	int ch;
	while((ch=cin.get()) != EOF) {
		if(ch == ';') {
			cin.ignore(100, '\n'); // �ѱ� ������ �ִ� 99���� ���ڷ� �Էµȴٰ� �����Ѵ�.
			cout << '\n';
		}
		else
			cout << (char)ch;
	}
}