#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini");
	if(!fin) {
		cout << "���� ����";
		return 0;
	}
	string line;
	int lineno=1;
	while(getline(fin, line)) { // �� ������ �о���δ�.
		cout << lineno++ << " : "; // ���� ��ȣ ���
		cout << line << endl; // ���� ���
	}
	fin.close();
} 