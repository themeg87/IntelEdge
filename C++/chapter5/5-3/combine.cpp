#include <iostream>
#include <string>
using namespace std;

void combine(string a, string b, string &c) {
	c = a + " " + b;
}
int main() {
	string text1("I love you"), text2("very much");
	string text3; // ��� �ִ� ���ڿ�
	combine(text1, text2, text3); // text1�� " ", �׸��� text2�� ���ٿ� text3 ����� 
	cout << text3; // "I love you very much" ���
}