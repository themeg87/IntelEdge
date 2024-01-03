#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class FileViewer {
	ifstream fin;
	vector<string> v; // ���κ��� ���ڿ��� �����ϴ� ����
public:
	FileViewer(const char* f);
	~FileViewer();
	void run();
};

FileViewer::FileViewer(const char* f) {
	fin.open(f); // ���� ����
	if(!fin) {
		cout <<f << "���� ����";
		exit(0);
	}

	// ������ ���κ��� �о� ���Ϳ� ����
	string line;
	while(getline(fin, line)) { // �� ������ �о� ���ڿ� line�� ����
		v.push_back(line); // line�� ���ڿ��� ���Ϳ� ����
	}
	cout << f << " ���� �б� �Ϸ�" << endl;
}

void FileViewer::run() {
	cout << "���� ��ȣ�� �Է��ϼ���. 1���� ���� ���� �Է��ϸ� ����" << endl;
	while(true) {
		cout << ": ";
		int lineno;
		cin >> lineno; // ���� ��ȣ �Է�
		if(lineno > (int)v.size()) continue; // ���� ��ȣ�� ���� ũ�⺸�� ũ�� ���� ����
		else if(lineno < 1) { // ���� ��ȣ�� 0���� �۰ų� ������ 
			cout << "���� �մϴ�." << endl;
			break;
		}
		cout << v.at(lineno-1) << endl; // ���� ��ȣ�� �ش��ϴ� ���� ���
	}
}

FileViewer::~FileViewer() {
	fin.close();
}

int main() {
	FileViewer viewer("C:\\windows\\system.ini");
	viewer.run();
}