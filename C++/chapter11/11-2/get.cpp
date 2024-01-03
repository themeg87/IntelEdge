#include <iostream>
using namespace std;

int main() {
	int count = 0;

	char ch;
	while(true) {
		cin.get(ch);
		if(cin.eof()) 
			break;
		else if(ch == ' ') 
			count++;
		else if(ch == '\n') 
			break;
	}
	cout << "공백이 총 " << count << "개 입니다." << endl;
}