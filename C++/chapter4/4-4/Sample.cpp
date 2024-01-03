#include <iostream>
using namespace std;

class Sample {
	int *p; 
	int size;
public:
	Sample(int n) { // ������
		size = n; p = new int [n]; // n�� ���� �迭�� ���� ����
	}
	void read(); // ���� �Ҵ���� ���� �迭 p�� ����ڷκ��� ������ �Է� ����
	void write(); // ���� �迭�� ȭ�鿡 ���
	int big(); // ���� �迭���� ���� ū �� ����
	~Sample(); // �Ҹ���
};

void Sample::read() { 
	for(int i=0; i<size; i++) 
		cin >> p[i];
}
void Sample::write() { 
	for(int i=0; i<size; i++) 
		cout << p[i] << ' ';
	cout << endl;
}
int Sample::big() { 
	int b = p[0];
	for(int i=1; i<size; i++) 
		if(b < p[i]) b = p[i];
	return b;
}
Sample::~Sample() {
	delete [] p;
}

int main() {
	Sample s(10); // 10�� ���� �迭�� ���� Sample ��ü ����
	s.read(); // Ű���忡�� ���� �迭 �б�
	s.write(); // ���� �迭 ���
	cout << "���� ū ���� " << s.big() << endl; // ���� ū �� ���
}