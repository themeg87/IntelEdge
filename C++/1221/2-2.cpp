#include <iostream>

double area(int r);			//�Լ����� ����

int main() {				//�����Լ�
	std::cout << "������ " << area(5); // �Լ� area()�� ���� �� ���
}

double area(int r) {		//�Լ� ����
	return 3.14 * r * r;	//������ r�� ������ ����
}