#include <iostream>
using namespace std;

int main() {
	// �迭 ���� �Ҵ�
	int *p = new int[5];

	// 5�� ���� �Է� �޾� �迭�� ����
	cout << "���� 5�� �Է�>> ";
	for (int i = 0; i < 5; i++) 
		cin >> p[i];

	// ��� ���
	int sum = 0;
	for (int i = 0; i < 5; i++)
		sum += p[i];

	cout << "��� " << sum/5.0 << endl;

	delete[] p; // ���� �Ҵ���� �迭 ��ȯ
}