#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;

	cout << "���ڿ� �Է�>> ";
	getline(cin, text); // �� ĭ�� �����ϴ� ���ڿ� �� ���� �Է�

	int count = 0;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == 'a') // if (text.at(i) == 'a') �� �ص� ��
			count++;
	}

	cout << "���� a�� " << count << "�� �ֽ��ϴ�. " << endl;
}