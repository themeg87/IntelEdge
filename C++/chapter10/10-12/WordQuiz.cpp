#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Word {
	string english;
	string korean;
public:
	Word(string english, string korean) {
		this->english = english;
		this->korean = korean;
	}
	string getEnglish() { return english; }
	string getKorean() { return korean; }
};

class WordQuiz {
	vector<Word> v;
	int makeExample(int ex[], int answerIndex);
	bool exists(int n[], int index);
	void test();
	void insert();
public:
	WordQuiz();
	void run();
};

WordQuiz::WordQuiz() {
	Word wordlist [] = { Word("love", "���"), Word("animal", "����"), Word("human", "�ΰ�"), 
		Word("emotion", "����"), Word("stock", "�ֽ�"), Word("trade", "�ŷ�"),
		Word("society", "��ȸ"), Word("baby", "�ڱ�"), Word("honey", "����"),
		Word("dall", "����"), Word("bear", "��"), Word("picture", "����"), Word("painting", "�׸�"),
		Word("fault", "����"), Word("example", "����"), Word("eye", "��"), Word("statue", "������")};

	for(int i=0; i<13; i++) {
		v.push_back(wordlist[i]);
	}

	srand((unsigned)time(0)); // ������ ������, �ٸ� �������� �߻���Ű�� ���� seed ����
}

void WordQuiz::run() {
	cout << "***** ���� ���� �׽�Ʈ�� �����մϴ�. *****" << endl;
	int cmd;
	while(true) {
		cout << "���� ����: 1, ���� �׽�Ʈ : 2, ���α׷� ����:�׿�Ű >> ";
		cin >> cmd;
		switch(cmd) {
		case 1:
			insert(); break;
		case 2:
			test(); break;
		default:
			return; // ���α׷� ����
		}
		cout << endl;
	}
}
void WordQuiz::insert() {
	cin.ignore(1, '\n'); // �Ʒ��� getline()���� �б� ���� cin�� ���ۿ� �ִ� ���� ����
	string eng, kor;
	cout << "���� �ܾ exit�� �Է��ϸ� �Է� ��" << endl;
	while(true) {
		cout << "���� >>";
		getline(cin, eng);
		if(eng == "exit") 
			return; // �Է� ��

		cout << "�ѱ� >>";
		char s[100];
		cin.getline(s, 100);
		kor = s;
		Word w(eng, kor); // Word ��ü ����
		v.push_back(w); // Word ����
	}
}

void WordQuiz::test() {
	cout << "���� ���� �׽�Ʈ�� �����մϴ�. 1~4 �� �ٸ� �Է½� ����." << endl;
	while(true) {
		int answerIndex = rand() % v.size();
		string eng = v[answerIndex].getEnglish();
		int example[4]; // ���⿡ �� ������ index �迭
		int answerLoc = makeExample(example, answerIndex); // ������ �ִ� ���� ��ȣ
		example[answerLoc] = answerIndex;

		// ������ ����մϴ�.
		cout << eng << "?" << endl;
		for(int i=0; i<4; i++)
			cout << '(' << i+1 << ") " << v[example[i]].getKorean() << ' '; // ���� ���

		cout << ":>"; // ������Ʈ
		int in;
		cin >> in; // ������� ���� �Է�
		if(in < 1 || in > 4)
			break; // ouf of example range. ���α׷� ����

		in--; // ����ڰ� 1~4 ������ ���� �Է�
		if(in == answerLoc)
			cout << "Excellent !!" << endl;
		else
			cout << "No. !!" << endl;
	}
}

int WordQuiz::makeExample(int ex[], int answerIndex) {
	int n[4] = {-1, -1, -1, -1}; // -1�� �ʱ�ȭ
	int index;
	for(int i=0; i<4; i++) {
		do {
			index = rand() % v.size();
		} while(index == answerIndex || exists(n, index)); // �ٽ� �õ�
		n[i] = index;
	}

	for(int i=0; i<4; i++) ex[i] = n[i];
	return rand() % 4;
}

bool	WordQuiz::exists(int n[], int index) { 
	for(int i=0; i<4; i++) {
		if(n[i] == index)
			return true;
	}
	return false;
}

int main() {
	WordQuiz quiz;
	quiz.run();
}