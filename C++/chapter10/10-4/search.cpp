#include <iostream>
using namespace std;

template<class T> 
bool search(T element, T ar[], int n) {
	for(int i=0; i<n; i++) {
		if(ar[i] == element)
			return true;
	}
	return false;
}

int main() {
	int x[] = {1, 10, 100, 5, 4};
	if(search(100, x, 5))  // 100이 배열 x에 포함되어 있는가?
		cout << "100이 배열 x에 포함되어 있다";
	else
		cout << "100이 배열 x에 포함되어 있지 않다";
	cout << endl;

	char c[] = {'h', 'e', 'l', 'l', 'o'};
	if(search('e', c, 5))  // 'e'가 배열 c에 포함되어 있는가?
		cout << "e가 배열 c에 포함되어 있다";
	else
		cout << "e가 배열 c에 포함되어 있지 않다";
	cout << endl;
}