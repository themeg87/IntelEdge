#include <iostream>
#include <cstring>
using namespace std;

bool checkInputError() {
	if (cin.fail()) { // ������� ���ڿ��� �ԷµǾ� ������ �߻��ϴ� ��� ��ó. �η� C�� ���� C-1����
		cin.clear();
		cin.ignore(100, '\n');
		cout << "�Է� ����" << endl;
		return true; // ���� ����
	}
	else
		return false; // ���� ����
}

int main() {
	int totalSale = 0; // ������� �Ǹ� �� �ݾ�
	int order; // ���� �ֹ��� �ݾ�
	char coffee[100]; // �ֹ��� Ŀ�� ����
	int num; // �� ��
	cout << "���������� 2000��, �Ƹ޸�ī�� 2300��, īǪġ�� 2500���Դϴ�." << endl;
	while (true) {
		cout << "�ֹ�>> ";
		cin >> coffee >> num;
		if (checkInputError()) continue; // num�� ���� �� �ٸ� �Է��Ͽ����� �˻�

		// �Է��� ���������� �̷�����ٸ�
		if (num <= 0) { // �� ���� ����� �ƴϰ� �Է��� ���
			cout << "�� ���� ����� �Է����ּ���" << endl;
			continue;
		}
		if (strcmp(coffee, "����������") == 0) {
			order = 2000 * num;
		}
		else if (strcmp(coffee, "�Ƹ޸�ī��") == 0) {
			order = 2300 * num;
		}
		else if (strcmp(coffee, "īǪġ��") == 0) {
			order = 2500 * num;
		}
		else {
			order = 0;
		}

		// ����ڿ��� �ֹ��� ���� ���
		if (order > 0) { // �������� �ֹ��� ���
			cout << order << "���Դϴ�. ���ְ� �弼��" << endl;
		}
		else // ���� Ŀ�� �ֹ��� ���
			cout << "���� Ŀ���Դϴ�. �ٽ� �Է����ּ���" << endl;

		// 20000���̻� �������� �Ǵ�
		totalSale += order;
		if (totalSale > 20000) {
			cout << "���� " << totalSale << "���� �Ǹ��Ͽ� ī�並 �ݽ��ϴ�. ���� ����~~~" << endl;
			break;
		}
	} // endl of while

}