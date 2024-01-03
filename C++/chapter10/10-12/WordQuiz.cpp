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
	Word wordlist [] = { Word("love", "사랑"), Word("animal", "동물"), Word("human", "인간"), 
		Word("emotion", "감정"), Word("stock", "주식"), Word("trade", "거래"),
		Word("society", "사회"), Word("baby", "자기"), Word("honey", "애인"),
		Word("dall", "인형"), Word("bear", "곰"), Word("picture", "사진"), Word("painting", "그림"),
		Word("fault", "오류"), Word("example", "보기"), Word("eye", "눈"), Word("statue", "조각상")};

	for(int i=0; i<13; i++) {
		v.push_back(wordlist[i]);
	}

	srand((unsigned)time(0)); // 시작할 때마다, 다른 랜덤수를 발생시키기 위한 seed 설정
}

void WordQuiz::run() {
	cout << "***** 영어 어휘 테스트를 시작합니다. *****" << endl;
	int cmd;
	while(true) {
		cout << "어휘 삽입: 1, 어휘 테스트 : 2, 프로그램 종료:그외키 >> ";
		cin >> cmd;
		switch(cmd) {
		case 1:
			insert(); break;
		case 2:
			test(); break;
		default:
			return; // 프로그램 종료
		}
		cout << endl;
	}
}
void WordQuiz::insert() {
	cin.ignore(1, '\n'); // 아래의 getline()으로 읽기 위해 cin의 버퍼에 있는 문자 제거
	string eng, kor;
	cout << "영어 단어에 exit을 입력하면 입력 끝" << endl;
	while(true) {
		cout << "영어 >>";
		getline(cin, eng);
		if(eng == "exit") 
			return; // 입력 끝

		cout << "한글 >>";
		char s[100];
		cin.getline(s, 100);
		kor = s;
		Word w(eng, kor); // Word 객체 생성
		v.push_back(w); // Word 삽입
	}
}

void WordQuiz::test() {
	cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료." << endl;
	while(true) {
		int answerIndex = rand() % v.size();
		string eng = v[answerIndex].getEnglish();
		int example[4]; // 보기에 들어갈 벡터의 index 배열
		int answerLoc = makeExample(example, answerIndex); // 정답이 있는 보기 번호
		example[answerLoc] = answerIndex;

		// 문제를 출력합니다.
		cout << eng << "?" << endl;
		for(int i=0; i<4; i++)
			cout << '(' << i+1 << ") " << v[example[i]].getKorean() << ' '; // 보기 출력

		cout << ":>"; // 프롬프트
		int in;
		cin >> in; // 사용자의 정답 입력
		if(in < 1 || in > 4)
			break; // ouf of example range. 프로그램 종료

		in--; // 사용자가 1~4 사이의 정답 입력
		if(in == answerLoc)
			cout << "Excellent !!" << endl;
		else
			cout << "No. !!" << endl;
	}
}

int WordQuiz::makeExample(int ex[], int answerIndex) {
	int n[4] = {-1, -1, -1, -1}; // -1로 초기화
	int index;
	for(int i=0; i<4; i++) {
		do {
			index = rand() % v.size();
		} while(index == answerIndex || exists(n, index)); // 다시 시도
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