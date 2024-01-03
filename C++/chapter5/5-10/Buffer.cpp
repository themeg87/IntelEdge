#include <iostream>
#include <string>
using namespace std;

#include "Buffer.h"

Buffer& append(Buffer& buf, string text) {
	buf.add(text);
	return buf;
}

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys"); // buf�� ���ڿ��� "Guys" ������
	temp.print(); // "HelloGuys" ���
	buf.print(); // "HelloGuys" ���
}