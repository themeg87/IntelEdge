#include <iostream>
#include <string>
using namespace std;

class Phone { // ��ȭ ��ȣ�� ǥ���ϴ� Ŭ����
	string name; 
	string telnum;
	string address; 
public:	
	Phone(string name="", string telnum="", string address="") {
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}
	friend ostream& operator << (ostream& outs, Phone phone); // << �����ڸ� ������� ����
	friend istream& operator >> (istream& ins, Phone& phone); // >> �����ڸ� ������� ����
};

ostream& operator << (ostream& outs, Phone phone) { // ��Ʈ���� phone ��ü ���
	outs << "(" << phone.name << ",";
	outs <<	phone.telnum << ",";
	outs <<	phone.address << ")";
	return outs;
} 

istream& operator >> (istream& ins, Phone& phone) { // ��Ʈ�����κ��� �о� phone ��ü �ϼ�
	cout << "�̸�:";
	getline(ins, phone.name);
	cout << "��ȭ��ȣ:";
	getline(ins, phone.telnum);
	cout << "�ּ�:";
	getline(ins, phone.address);
	return ins;
}

int main() {
	Phone girl, boy;
	cin >> girl >> boy; //��ȭ ��ȣ�� Ű����κ��� �д´�.
	cout << girl << endl << boy << endl; // ��ȭ ��ȣ�� ����Ѵ�.
}