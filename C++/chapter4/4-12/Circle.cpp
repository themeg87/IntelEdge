#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius; // ���� ������ ��
	string name; // ���� �̸�
public:
	void setCircle(string name, int radius); // �̸��� ������ ����
	double getArea(); 
	string getName();
};

void Circle::setCircle(string name, int radius) {
	this->name = name;
	this->radius = radius;
}

double Circle::getArea() {
	return 3.14*radius*radius;
}

string Circle::getName() {
	return name;
}

class CircleManager {
	Circle *p; // Circle �迭�� ���� ������
	int size; // �迭�� ũ��
public:
	CircleManager(int size); // size ũ���� �迭�� ���� ����. ����ڷκ��� �Է� �Ϸ�
	~CircleManager(); 
	void searchByName(); // ����ڷκ��� ���� �̸��� �Է¹޾� ���� ���
	void searchByArea(); // ����ڷκ��� ������ �Է¹޾� �������� ū ���� �̸� ���
};

CircleManager::CircleManager(int size) {
	p = new Circle [size];
	this->size = size;

	int radius;
	string name;
	for(int i=0; i<size; i++) {
		cout << "�� " << i+1 << "�� �̸��� ������ >> ";
		cin >> name >> radius;
		p[i].setCircle(name, radius);
	}
}

CircleManager::~CircleManager() {
	delete [] p;
}

void CircleManager::searchByName() {
	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	string name;
	cin >> name;
	for(int i=0; i<size; i++) {
		if(name == p[i].getName()) {
			cout << name << "�� ������ " << p[i].getArea() << endl;
			return;
		}
	}
	cout << name << "��  ã�� �� �����ϴ�." << endl;
}

void CircleManager::searchByArea() {
	cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
	int area;
	cin >> area;
	cout << area <<  "���� ū " << "���� �˻��մϴ�." << endl;
	int count = 0;
	for(int i=0; i<size; i++) {
		if(area < p[i].getArea()) {
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << ',';
			count ++;
		}
	}
	if(count == 0)
		cout << "area ���� ū " << "���� �����ϴ�.";
	cout << endl;
}

int main() {
	CircleManager *pManager;
	cout << "���� ���� >> ";
	int size;
	cin >> size;
	if(size <= 0) {
		cout << "����� �Է��ϼ���." << endl;
		return 0;
	}

	pManager = new CircleManager(size);
	pManager->searchByName();
	pManager->searchByArea();
	delete pManager;
}