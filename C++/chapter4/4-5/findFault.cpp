#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	string text;
	srand((unsigned)time(0)); // ������ ������, �ٸ� �������� �߻���Ű�� ���� seed ����

	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl;
	while(true) {
		cout << ">>";
		getline(cin, text, '\n');
		if(text == "exit")
			break;
		if (text == "")
			continue;
		int size = text.length();
		int index = rand() % size; // 0���� RAND_MAX(32767) ������ ������ ���� �߻�
		int c = rand() % 26; // 0���� RAND_MAX(32767) ������ ������ ���� �߻�
		char changeChar = 'a'+c; // ���� ������ ����
		if(text[index] == 'a'+c) // ���� ���ڿ� ���� ������ ���ڰ� ���ٸ�
			changeChar = 'A'+c;
		text[index] = changeChar;
		cout << text << endl;
	}
}