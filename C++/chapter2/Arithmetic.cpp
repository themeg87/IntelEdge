#include <iostream>
#include <cstring>
using namespace std;

int separate(char part[], char org[], int index); // org ���ڿ��� index ��ġ���� ��������� ���ڿ��� part �迭�� �����ϰ� ������ index ����
int calc(char op1[], char op2[], char opcode); // op1�� op2�� �ǿ����ڸ� opcode�� �����ڷ� ����ϰ� ��� ����

int main() {
	char exp[100];
	char op1[100], op2[100], opcode;
	while (true) {
		cout << "? ";
		cin.getline(exp, 100);
		int index = separate(op1, exp, 0); // index�� �� ĭ�� ����Ŵ
		index++;
		opcode = exp[index]; // ������ ����
		index += 2; // ������ �ǿ����ڸ� ����Ŵ
		separate(op2, exp, index);
		int result = calc(op1, op2, opcode);
		cout << exp << " = " << result << endl;
	}

	return 0;
}

int separate(char part[], char org[], int index) {
	int j = 0;
	while (true) {
		if (isspace(org[index]) || org[index] == '\0') { // ���� �����̰ų� ���̸�
			part[j] = '\0';
			break;
		}
		else { // ���� ���ڰ� �ƴ� ���
			part[j] = org[index];
			index++;
			j++;
		}
	}
	return index;
}

int calc(char op1[], char op2[], char opcode) {
	int left = atoi(op1); // ���� �ǿ����ڸ� ���ڿ����� ���ڷ� ��ȯ
	int right = atoi(op2); //������ �ǿ����ڸ� ���ڿ����� ���ڷ� ��ȯ

	switch (opcode) {
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		if (right == 0) {
			cout << "0���� ������ ���� �߻�!" << endl;
			return -1; // -1�� 0���� ������ �������� ǥ��
		}
		else return left / right;
	case '%':
		return left % right;
	default:
		cout << "�߸��� ������!" << endl;
		return -1;
	}
}