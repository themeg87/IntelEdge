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
	cout << "������ �� " << count << "�� �Դϴ�." << endl;
}