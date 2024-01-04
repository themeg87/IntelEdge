//배열을 받아 가장 큰 값을 리턴하는 제네릭 함수 biggest()를 작성
//main() 함수를 작성하여 biggest() 호출 몇가지 사례 test
#include <iostream>
using namespace std;

template <class T>
T biggest(T a[], int n) {
	if (n <= 0)
		return 0;

	T b = a[0];
	for (int i = 1; i < n; i++)
		if (b < a[i])
			b = a[i];
	return b;
}

int main() {
	int x[] = { 100, 200, 300 };
	cout << biggest(x, 3) << endl; 
	
	double y[] = { 10.1, 4.1, 20.1 };
	cout << biggest(y, 3) << endl;

	string z[] = { "a", "b", "c", "z", "x"};
	cout << biggest(z, 5) << endl;

	return 0;
}