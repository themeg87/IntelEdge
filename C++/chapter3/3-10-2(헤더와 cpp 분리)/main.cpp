#include <iostream>
using namespace std;

#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"

int main() {
	Add a;
	Sub s;
	Mul m;
	Div d;

	while(true) {
		// ȭ�鿡 ������Ʈ�� ����ϰ� Ű����� �� ������ �����ڸ� �Է¹޴´�.
		cout << "�� ������ �����ڸ� �Է��ϼ���>>";
		int x, y;
		char c;
		cin >> x >> y >> c;
		switch(c) {
			case '+': 	a.setValue(x, y); 	cout << a.calculate(); break;
			case '-': 	s.setValue(x, y); 	cout << s.calculate(); break;
			case '*': 	m.setValue(x, y);  cout << m.calculate(); break;
			case '/': 	d.setValue(x, y); cout << d.calculate(); break;
		}
		cout << endl;
	}
}