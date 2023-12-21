#include <iostream>
using namespace std;

int main() {
	cout << "너비를 입력하세요\n";
	int width;
	cin >> width;
	
	cout << "높이를 입력하세요\n";
	int height;
	cin >> height;
	
	cout << "사각형의 면적은?\n";
	int area = width * height;
	cout << area;
	return 0;
}

//#include <iostream>
//using namespace std;
//
//int main() {
//	cout << "너비와 높이를 입력하세요\n";
//	int width;
//	int height;
//	cin >> width >> height;
//
//	cout << "사각형의 면적은?\n";
//	int area = width * height;
//	cout << area;
//	return 0;
//}