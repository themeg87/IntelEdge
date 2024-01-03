#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// �ҽ� ���ϰ� ���� ������ �̸�
	const char* srcFile = "c:\\temp\\desert.jpg";
	const char* destFile = "c:\\temp\\copydesert.jpg";

	try {
		// �ҽ� ���� ����
		ifstream fsrc(srcFile, ios::in | ios::binary);
		if(!fsrc) // ���� ���� �˻�
			throw srcFile;

		// ���� ���� ����
		ofstream fdest(destFile, ios::out | ios::binary);
		if(!fdest) // ���� ���� �˻�
			throw destFile;

		// �ҽ� ���Ͽ��� ���� ���Ϸ� �����ϱ�
		int c;
		while((c=fsrc.get()) != EOF) { // �ҽ� ������ ������ �� ����Ʈ�� �д´�.
			fdest.put(c); // ���� ����Ʈ�� ���Ͽ� ����Ѵ�.
		}
		cout << srcFile << "�� " << destFile << "�� ���� �Ϸ�" << endl;
		fsrc.close();
		fdest.close();
	}
	catch(const char* file) {
		cout << "���ܹ߻�: " <<  file << " ���� ����" << endl;
	}
}