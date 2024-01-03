#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Nation {
	string nation;
	string capital;
public:
	Nation(string nation, string capital) {
		this->nation = nation;
		this->capital = capital;
	}
	string getCapital() { return capital; }
	string getNation() { return nation; }
	void show() {
		cout << '(' << nation << ',' << capital << ')';
	}
};

class NationGame {
	vector<Nation> v;
	void input();
	void list();
	void quiz();
	bool exist(string nation);
public:
	NationGame();
	void run();
};

NationGame::NationGame() {
	Nation n[] = { Nation("�̱�", "�ͽ���"), Nation("����", "����"), Nation("������", "�ĸ�"),
		Nation("�߱�", "������"), Nation("�Ϻ�", "����"), Nation("���þ�", "��ũ��"),
		Nation("�����", "���������"), Nation("����", "������"), Nation("�߽���", "�߽��ڽ�Ƽ")};

	for(int i=0; i<9; i++)
		v.push_back(n[i]);

	srand((unsigned)time(0)); // ������ ������, �ٸ� �������� �߻���Ű�� ���� seed ����
}

void NationGame::run() {
	cout << "***** ������ ���� ���߱� ������ �����մϴ�. *****" << endl;
	while(true) {
		int cmd;
		cout << "���� �Է�: 1, ����: 2, ����: 3 >> ";
		cin >> cmd;
		switch(cmd) {
			case 1 : input(); break;
			case 2 : quiz(); break;
			case 3 : return;
		}
	}
}
void NationGame::quiz() {
	while(true) {
		int index = rand() % v.size(); // 0���� RAND_MAX(32767) ������ ������ ������ n�� �߻�
		cout << v[index].getNation() << "�� ������?";
		string capital;
		cin >> capital;
		if(capital == "exit") 
			return; // quiz �׸�
		if(v[index].getCapital() == capital)
			cout << "Correct !!" << endl;
		else
			cout << "NO !!" << endl;
	}
}

void NationGame::input() {
	string nation, capital;
	cout << "���� " << v.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�." << endl;
	cout << "����� ������ �Է��ϼ���(no no �̸� �Է³�)" << endl;
	while(true) {
		cout << v.size()+1 << ">>";
		cin >> nation >> capital;
		if(nation == "no" && capital=="no") 
			break;
		if(exist(nation)) {
			cout << "already exists !!" << endl;
			continue;
		}
		Nation n(nation, capital);
		v.push_back(n);
	}
	// list();
	return;
}

bool NationGame::exist(string nation) {
	for(int i=0; i<v.size(); i++) {
		if(v[i].getNation() == nation)
			return true;
	}

	return false;
}

void NationGame::list() {
	for(int i=0; i<v.size(); i++) {
		v[i].show();
		cout << endl;
	}
}

int main() {
	NationGame game;
	game.run();
}