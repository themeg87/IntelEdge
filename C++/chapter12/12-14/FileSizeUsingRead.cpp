#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";

	ifstream fin;
	fin.open(file, ios::in | ios::binary); // ���̳ʸ� �б� ���� ���� ����
	if(fin.fail()) { // ���� ���� �˻�
		cout << "���� ���� ����";
		return 0;
	}

	int count = 0;
	char buf[1024];
	while(!fin.eof()) {
		fin.read(buf, 1024);
		int n = fin.gcount();
		count += n;
	}
	cout << file << " ������ ũ��� " << count << "����Ʈ" << endl;
}