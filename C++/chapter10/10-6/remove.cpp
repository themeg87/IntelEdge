#include <iostream>
using namespace std;

template<class T> 
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	int k=0;
	T* p = new T[sizeSrc]; // src�� ���� ũ���� �迭 �Ҵ�
	for(int i=0; i<sizeSrc; i++) {
		int j;
		for(j=0; j<sizeMinus; j++) 
			if(src[i] == minus[j]) 
				break;
		if(j==sizeMinus) { // src[i] ���� minus �迭�� ����
			p[k] = src[i];
			k++;
		}
	}
	retSize = k; // ������ �迭�� ũ�� ����
	if(k==0) {
		delete [] p;
		return NULL;
	}
	T* q = p;
	if(sizeSrc != retSize) {
		q = new T[k]; // ���� �迭 �Ҵ�
		for(int i=0; i<k; i++)
			q[i] = p[i]; //�迭 ����
		delete [] p; // ó�� �Ҵ���� �迭 ��ȯ
	}
	return q;
}

int main() {
	// remove() �Լ��� int�� ��üȭ�ϴ� ���
	cout << "���� �迭 {1,2,3,4}���� ���� �迭 {-3,5,10,1,2,3}�� ���ϴ�" << endl;

	int x[]={1,2,3,4};
	int y[]={-3,5,10,1,2,3};
	int retSize;

	int* p = remove(x, 4, y, 6, retSize);
	if(retSize == 0) {
		cout << "��� ���ŵǾ� �����ϴ� �迭�� �����ϴ�." << endl;
		return 0;
	}
	else {
		for(int i=0; i<retSize; i++) 
			cout << p[i] << ' ';
		cout << endl;

		delete [] p; // �Ҵ���� �迭 ��ȯ
	}
	cout << endl;


	// remove() �Լ��� double�� ��üȭ�ϴ� ���
	cout << "�Ǽ� �迭 {1.0, 2.0, 3.2, 4.8, 5.0, 6.0, 7.0, 99.9}���� " << endl; 
	cout << "�Ǽ� �迭 {3.5, 4.8, 1.0, 2.0, 3.0}�� ���ϴ�" << endl;

	double x2[]={1.0, 2.0, 3.2, 4.8, 5.0, 6.0, 7.0, 99.9};
	double y2[]={3.5, 4.8, 1.0, 2.0, 3.0};

	double* q = remove(x2, 8, y2, 5, retSize);
	if(retSize == 0) {
		cout << "��� ���ŵǾ� �����ϴ� �迭�� �����ϴ�." << endl;
	}
	else {
		for(int i=0; i<retSize; i++) 
			cout << q[i] << ' ';
		cout << endl;

		delete [] q; // �Ҵ���� �迭 ��ȯ
	}
}