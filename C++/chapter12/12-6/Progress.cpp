#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini", ios::in | ios::binary);
	if(!fin) {
		cout <<"c:\\windows\\system.ini ���� ����";
		return 0;
	}
	ofstream fout("c:\\temp\\system.txt",  ios::out | ios::binary);
	if(!fout) {
		cout << "c:\\temp\\system.txt ���� ����";
		return 0;
	}

	// ���� ũ�� �˾Ƴ���
	fin.seekg(0, ios::end);
	int fileSize = fin.tellg();
	fin.seekg(0, ios::beg);
	
	// ���� ���� ����
	int copyUnit = fileSize/10;
	char *buf = new char [copyUnit]; // �޸� �Ҵ�

	cout << "���� ����..." << endl;
	for(int i=0; i<10; i++) {
		fin.read(buf, copyUnit);
		int real = fin.gcount(); // ���� ���� ����Ʈ ��
		fout.write(buf, real); // ���� ���� ����Ʈ ��ŭ�� ���
		cout << '.';
		cout << real << "B ";
		cout <<(i+1)*10 << '%' << endl;
		if(real < copyUnit) // ���� ����Ʈ�� �õ��� ����Ʈ���� ������ ����
			break;
	}
	cout << fileSize << "B ���� �Ϸ�" << endl;

	delete [] buf;
	fin.close();
	fout.close();
}