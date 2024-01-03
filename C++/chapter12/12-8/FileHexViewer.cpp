#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class HexViewer {
	ifstream fin;
	void printHexLine(char* buf, int n);
	void printCharLine(char* buf, int n);
public:
	HexViewer(const char* f);
	~HexViewer();
	void show();
};

HexViewer::HexViewer(const char* f) {
	fin.open(f, ios::in | ios::binary);
	if(!fin) {
		cout <<f << " ���� ����";
		exit(0); // ���α׷� ����
	}
	cout << f << " ���" <<endl << endl;
}

HexViewer::~HexViewer() {
	fin.close();
}

void HexViewer::show() {
	char buf[16];
	while(true) {
		fin.read(buf, 16); // �� ���� 16 ����Ʈ�� ����
		int real = fin.gcount(); // ���� ���� ����Ʈ �˾Ƴ���
		printHexLine(buf, real); // 16������ �� �� ���
		printCharLine(buf, real); // ���ڷ� �� �� ���
		if(real < 16)
			break; // ������ ���̹Ƿ� ������.
		cout << endl; // ���� �ٷ� �Ѿ��
	} // end of while

	cout << endl;
}

void HexViewer::printHexLine(char* buf, int n) { // ���� �ٿ� n �� ����Ʈ�� ��ȿ
	// print one line as hex codes
	for(int i=0; i<16; i++) {
		cout << setw(2) << setfill('0') << hex << (int)buf[i];
		if(i == n-1) { // i�� index�̰� n�� ���� �ٿ� ��ȿ�� ����Ʈ ��
			// ������ ���ڶ�� �κ��� �� ĭ���� ä���.
			cout << ' ';
			for(int j=i+1; j<16; j++) {
				cout << setw(2) << setfill(' ') << hex << ' ';
				cout << ' ';
			}
			break;
		}
		if(i == 7) cout << setw(4) << setfill(' ') << ' ';
		else cout << ' ';
	}
}

void HexViewer::printCharLine(char* buf, int n) {
	// hex ���� ��� �� ��� ����
	cout << setw(4) << setfill(' ') << ' ';

	// print one line as characters
	for(int i=0; i<16; i++) {
		if(isprint(buf[i]))
			cout << buf[i];
		else
			cout << '.';
		if(i == n-1) {  // i�� index�̰� n�� ���� �ٿ� ��ȿ�� ����Ʈ ��
			// �� �̻� ����� �����Ͱ� �����Ƿ� ������ ���� ���´�.
			break;
		}
		if(i == 7) cout << setw(4) << setfill(' ') << ' ';
		else cout << ' ';
	}
}

int main() {
	HexViewer viewer("c:\\windows\\system.ini");
	viewer.show();
}