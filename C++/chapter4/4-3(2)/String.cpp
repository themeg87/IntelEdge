#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;

	cout << "���ڿ� �Է�>> ";
	getline(cin, text); // �� ĭ�� �����ϴ� ���ڿ� �� ���� �Է�

	int count = 0;
	int index = 0;
	while (true) {
		index = text.find('a', index); // index���� 'a' ã��
		if (index == -1)
			break;
		count++;	
		index++; // ���� ã�� �ٷ� ���� ��ġ���� ã�� ����
	}
	cout << "���� a�� " << count << "�� �ֽ��ϴ�. " << endl;
}