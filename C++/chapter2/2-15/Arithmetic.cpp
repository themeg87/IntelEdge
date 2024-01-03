#include <iostream>
#include <cstring>
using namespace std;

int separate(char part[], char org[], int index); // org 문자열의 index 위치에서 공백까지의 문자열을 part 배열에 저장하고 마지막 index 리턴
int calc(char op1[], char op2[], char opcode); // op1과 op2의 피연산자를 opcode의 연산자로 계산하고 결과 리턴

int main() {
	char exp[100];
	char op1[100], op2[100], opcode;
	while (true) {
		cout << "? ";
		cin.getline(exp, 100);
		int index = separate(op1, exp, 0); // index는 빈 칸을 가리킴
		index++;
		opcode = exp[index]; // 연산자 문자
		index += 2; // 오른쪽 피연산자를 가리킴
		separate(op2, exp, index);
		int result = calc(op1, op2, opcode);
		cout << exp << " = " << result << endl;
	}

	return 0;
}

int separate(char part[], char org[], int index) {
	int j = 0;
	while (true) {
		if (isspace(org[index]) || org[index] == '\0') { // 공백 문자이거나 널이면
			part[j] = '\0';
			break;
		}
		else { // 공백 문자가 아닌 경우
			part[j] = org[index];
			index++;
			j++;
		}
	}
	return index;
}

int calc(char op1[], char op2[], char opcode) {
	int left = atoi(op1); // 왼쪽 피연산자를 문자열에서 숫자로 변환
	int right = atoi(op2); //오른쪽 피연사자를 문자열에서 숫자로 변환

	switch (opcode) {
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		if (right == 0) {
			cout << "0으로 나누는 오류 발생!" << endl;
			return -1; // -1은 0으로 나누는 오류임을 표시
		}
		else return left / right;
	case '%':
		return left % right;
	default:
		cout << "잘못된 연산자!" << endl;
		return -1;
	}
}