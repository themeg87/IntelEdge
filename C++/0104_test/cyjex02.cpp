// temp/php.ini ������ ����° ���ο� �ִ� ���ڿ� �� = ���� �� 1521 <-> 3306 ����

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("c:\\temp\\php.ini");
	string line;

	int lineno = 1;
	while (getline(fin, line)) {
		if (lineno == 3) { // �� ��° �� ã��
			size_t findequal = line.find('='); // = ��ȣ ���� findequal
			if (findequal != string::npos) {
				string value = line.substr(findequal + 1); // = ��ȣ ���� �ڸ� �� ���� value
				if (value == "1521") {
					line.replace(findequal + 1, 4, "3306"); // 1521�̸� 3306���� ����
				}
				else if (value == "3306") {
					line.replace(findequal + 1, 4, "1521"); // 3306�̸� 1521�� ����
				}
			}
		}
		cout << lineno << " : " << line << endl;
		lineno++;
	}
	fin.close();
	return 0;
}
