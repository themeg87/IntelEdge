#include <iostream>
#include <string>
using namespace std;

class DebugInfo { // �ϳ��� ����� ���� ����
public:
	string tag; // ������ ������ ����� ������ �����ϱ����� �±�
	string comment; // �����ڰ� ����ϴ� ����� ����
};
class Trace {
	Trace() {} // private���� �Ͽ� �ܺο����� Trace ��ü�� ������ �� ���� ��
	static int index; // info �迭�� ����� ���� ��ġ
	static DebugInfo info[1000]; // �ִ� 1000 ���� ����� ������ ��´�.
public:
	static void put(string tag, string comment);
	static void print(string tag=""); // tag�� �ش��ϴ� ����� ���� ���
};

void Trace::put(string tag, string comment) {
	if(index == 1000) {
		cout << "Trace �޸� full" << endl;
		return;
	}
	DebugInfo a;
	a.tag = tag;
	a.comment = comment;
	info[index] = a;
	index++;
}

void Trace::print(string tag) {
	if(tag.length() == 0) { // ��� �±��� Trace ���
		cout << "----- ��� Trace ������ ����մϴ�. -----" << endl;
		for(int i=0; i<index; i++) {
			DebugInfo a = info[i];
			cout << a.tag << ":" << a.comment << endl;
		}
	}
	else {
		cout << "----- " << tag << "�±��� Trace ������ ����մϴ�. -----" << endl;
		for(int i=0; i<index; i++) {
			DebugInfo a = info[i];
			if(a.tag == tag)
			cout << a.tag << ":" << a.comment << endl;
		}
	}
}

int Trace::index = 0; // �ʱ�ȭ �ݵ�� �ʿ�
DebugInfo Trace::info[1000]; // �ʱ�ȭ �ݵ�� �ʿ�

void f() {
	int a, b, c;
	cout << "�� ���� ������ �Է��ϼ���>>";
	cin >> a >> b;
	Trace::put("f()", "������ �Է� �޾���");
	c = a + b;
	Trace::put("f()", "�� ���");
	cout << "���� " << c << endl;
}
int main() {
	Trace::put("main()", "���α׷� �����մϴ�");
	f();
	Trace::put("main()", "����"); // put()�� ù ��° �Ű� ������ �±��̰� �� ��° �Ű������� ����� �����̴�.
	Trace::print("f()"); // "f()" �±׸� ���� ����� ������ ��� ����Ѵ�.
	Trace::print(); // ��� ����� ������ ����Ѵ�.
}