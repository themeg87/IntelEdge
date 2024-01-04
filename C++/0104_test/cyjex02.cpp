// temp/php.ini 파일의 세번째 라인에 있는 문자열 중 = 문자 뒤 1521 <-> 3306 변경

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("c:\\temp\\php.ini");
	string line;

	int lineno = 1;
	while (getline(fin, line)) {
		if (lineno == 3) { // 세 번째 줄 찾기
			size_t findequal = line.find('='); // = 기호 변수 findequal
			if (findequal != string::npos) {
				string value = line.substr(findequal + 1); // = 기호 다음 자리 수 변수 value
				if (value == "1521") {
					line.replace(findequal + 1, 4, "3306"); // 1521이면 3306으로 변경
				}
				else if (value == "3306") {
					line.replace(findequal + 1, 4, "1521"); // 3306이면 1521로 변경
				}
			}
		}
		cout << lineno << " : " << line << endl;
		lineno++;
	}
	fin.close();
	return 0;
}
