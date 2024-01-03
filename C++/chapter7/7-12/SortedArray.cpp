#include <iostream>
#include <string>
using namespace std;

class SortedArray {
	int size; // ���� �迭�� ũ��
	int *p; // ���� �迭�� ���� ������
	void sort(); // ���� �迭�� ������������ ����
public:
	SortedArray(); // p�� NULL�� size�� 0���� �ʱ�ȭ
	SortedArray(SortedArray& src); // ���� ������
	SortedArray(int p[], int size); // ������. ���� �迭�� ũ�⸦ ���޹���
	~SortedArray(); // �Ҹ���
	SortedArray operator + (SortedArray& op2);
	SortedArray& operator = (const SortedArray& op2); // ���� �迭�� op2 �迭�� ����
	void show(); // �迭�� ���� ���
};

SortedArray::SortedArray() {
	p = NULL; // NULL ��� nullptr�� �ϴ� ���� �ٶ�����
	size = 0;
}
SortedArray::~SortedArray() {
	if (p != NULL) // NULL ��� nullptr�� �ϴ� ���� �ٶ�����
		delete[] p;
}

SortedArray::SortedArray(int p[], int size) {
	this->size = size;
	this->p = new int[size];
	for (int i = 0; i < size; i++) {
		this->p[i] = p[i];
	}

	sort(); // �������� ����
}

SortedArray::SortedArray(SortedArray& src) {
	this->size = src.size;
	if (src.size == 0) {
		this->p = NULL; // NULL ��� nullptr�� �ϴ� ���� �ٶ�����
	}
	else {
		this->p = new int[this->size];
		for (int i = 0; i < this->size; i++) {
			this->p[i] = src.p[i];
		}
	}
}

void SortedArray::sort() { // �������� ���� ����
	if (p == NULL || size == 0) // NULL ��� nullptr�� �ϴ� ���� �ٶ�����
		return;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i; j < size - 1; j++) {
			if (p[j] > p[j + 1]) {
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void SortedArray::show() { // ��� ���� ���
	cout << "�迭 ��� : ";
	for (int i = 0; i < size; i++) {
		cout << p[i] << ' ';
	}
	cout << endl;

}

SortedArray& SortedArray::operator = (const SortedArray& op2) {
	if (p != NULL) { // NULL ��� nullptr�� �ϴ� ���� �ٶ�����
		delete[] p;
	}

	size = op2.size;
	if (size == 0) { // op2�� ����ִ� ���
		p = NULL; // NULL ��� nullptr�� �ϴ� ���� �ٶ�����
		return *this;
	}

	// op2�� ������� �ʴ� ���
	p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = op2.p[i];
	return *this;
}

SortedArray SortedArray::operator + (SortedArray& op2) {
	SortedArray temp;

	// �� ��ü�� �迭�� ���� temp�� �ִ´�.
	if (this->size == 0) { // �� ��ü�� ��� �ִ� ���
						   // op2�� temp�� �����Ͽ� ����
		temp.size = op2.size;
		if (temp.size == 0) { // op2�� ����ִ� ���
			temp.p = NULL; // NULL ��� nullptr�� �ϴ� ���� �ٶ�����
		}
		else { // op2�� ������� �ʴ� ���
			temp.p = new int[temp.size];
			for (int i = 0; i < temp.size; i++)
				temp.p[i] = op2.p[i];
		}
	}
	else if (op2.size == 0) { // �� ��ü�� ������� �ʰ� op2�� ����ִ°��
							  // �� ��ü�� temp�� �����Ͽ� ����
		temp.size = this->size;
		temp.p = new int[temp.size];
		for (int i = 0; i < temp.size; i++)
			temp.p[i] = this->p[i];
	}
	else { // �Ѵ� ������� �ʴ� ���
		temp.size = this->size + op2.size;
		temp.p = new int[temp.size];
		int i;
		for (i = 0; i < this->size; i++) // �� ��ü�� �迭 ����
			temp.p[i] = this->p[i];
		for (int j = 0; j < op2.size; j++) // �� ��ü�� �迭 ����
			temp.p[i + j] = op2.p[j];
	}
	temp.sort();
	return temp;
}

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;
	
	c = a + b; // +, = ������ �ۼ� �ʿ�
			   // + �����ڰ� SortedArray ��ü�� �����ϹǷ� ���� ������ �ʿ�

	a.show();
	b.show();
	c.show();
}