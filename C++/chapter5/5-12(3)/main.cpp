#include <iostream>
#include "Dept.h"
using namespace std;

/* ���� (3)�� ��
	countPass(Dept& dept)�� �Ű������� ���� �Ű� ������ ��������ν�
	countPass() �Լ��� ȣ��� ��, �Ű������� �־��� dept ��ü�� �������� �ʵ��� �ϸ� �ȴ�.
	�̷��� �ϸ� ��������ڰ� �ʿ���� ������ ��������� ���� ���� ����Ǵ� �ð� �Ҹ� ���� �ȴ�.
*/

int countPass(Dept& dept) { // dept �а��� 60�� �̻����� ����ϴ� �л��� �� ����
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10); // �� 10���� �ִ� �а� com
	com.read(); // �� 10���� �л����� ������ Ű����κ��� �о� scores �迭�� ����
	int n = countPass(com); // com �а��� 60�� �̻����� ����� �л��� ���� ����
	cout << "60�� �̻��� " << n << "��";
}