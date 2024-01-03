#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char text[10000]; // 10000 ���� ���ڿ� �迭
	int histo[26] = { 0 }; // ������ 26 ������ ������ ����. �ʱ갪�� ��� 0

	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�." << endl;
	cout << "�ؽ�Ʈ�� ���� ; �Դϴ�. 10000������ �����մϴ�. " << endl;
	cin.getline(text, 10000, ';');

	int len = strlen(text);
	for (int i = 0; i<len; i++) {
		if (isalpha(text[i])) {
			char c = tolower(text[i]);
			histo[c - 'a']++;
		}
	}

	int n = 0;
	for (int i = 0; i<26; i++) n += histo[i]; // ��ü ���ĺ� �� ���ϱ�
	cout << "�� ���ĺ� �� " << n << endl;
	cout << endl;

	for (int i = 0; i<26; i++) {
		cout << char('a' + i) << " (" << histo[i] << ")" << '\t' << ": ";
		for (int j = 0; j<histo[i]; j++)
			cout << '*';
		cout << endl;
	}
}