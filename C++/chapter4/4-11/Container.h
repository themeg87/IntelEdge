#ifndef CONTAINER_H
#define CONTAINER_H

class Container { // �� �ϳ��� ��Ÿ���� Ŭ����
	int size; // ���� ���� ��, �ִ� ���� ���ɷ��� 10
public:
	Container() { size = 10; }
	void fill(int n); // n ��ŭ ä���
	bool consume(int n); // n ��ŭ �Ҹ��ϱ�
	int getSize(); // ���� ũ�� ����
};

#endif
