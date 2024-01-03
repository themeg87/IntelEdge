#include <iostream>
#include <string>
using namespace std;

class Person {
	string name; 
	string tel; 
public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};
Person::Person() {
	this->name = "";
	this->tel = "";
}
void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

class PersonManager {
	Person *p;
	int size;
public:
	PersonManager(int n) {
		p = new Person[n];
		size = n;
		string name, tel;
		cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl;
		for(int i=0; i<3; i++) {
			cout << "��� " << i+1 << ">> ";
			cin >> name >> tel;
			p[i].set(name, tel);
		}
	}
	void show() {
		cout << "��� ����� �̸��� ";
		for(int i=0; i<3; i++) {
			cout << p[i].getName() << ' ';
		}
		cout << endl;
	}
	void search() {
		string name;
		cout << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>>";
		cin >> name;
		for(int i=0; i<3; i++) {
			if(name == p[i].getName()) {
				cout << "��ȭ ��ȣ�� " << p[i].getTel() << endl;
				return;
			}
		}
		cout << "���� ����Դϴ�" << endl;
	}
	~PersonManager() {
		delete [] p;
	}
};

int main() {
	PersonManager manager(3);
	manager.show();
	manager.search();
}