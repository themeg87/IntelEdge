#include "Container.h"

void Container::fill(int n) { // n ��ŭ ä���
	size = n;
}
bool Container::consume(int n) { // n ��ŭ �Ҹ��ϱ�
	if (size < n)
		return false;
	else {
		size -= n;
		return true;
	}
}
int Container::getSize() { // ���� ũ�� ����
	return size;
}