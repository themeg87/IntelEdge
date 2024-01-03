#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Words {
	ifstream fin;
	vector<string> wordVector;
	void search(string word);
public:
	Words();
	void gamerun();
	~Words();
};

Words::Words() {
	fin.open("words.txt");
	if(!fin) {
		cout << "words.txt" << " ���� ����" << endl;
		exit(0); // ���α׷� ����
	}

	// words.txt ������ �о� wordVector�� ����
	string word;
	while(getline(fin, word)) {
		wordVector.push_back(word);
	}
	cout << "... words.txt ���� �ε� �Ϸ�" << endl;
}

void Words::search(string word) {
	int count = 0;
	int length = word.length();
	for(int i=0; i<wordVector.size(); i++) {
		string tmp = wordVector[i];
		if((int)tmp.length() >= length) { // ���̰� word ���� ���� �ܾ�� ����
			int index = tmp.find(word);
			if(index == 0) { // ù ���ں��� ����. ã����. 
				cout << tmp << endl;
				count++;
			}
		}
	}
	if(count == 0)
		cout << "�߰��� �� ����" << endl;
}

Words::~Words() {
	fin.close();
}

void Words::gamerun() {
	cout << "�˻��� �����մϴ�. �ܾ �Է��� �ּ���." << endl;
	while(true) {
		cout << "�ܾ�>> ";
		string word;
		getline(cin, word); // Ű���忡�� �� ������ �д´�.
		if(word == "exit")
			return; // ���� ����
		search(word);
	}
}

int main() {
	Words w;
	w.gamerun();
}