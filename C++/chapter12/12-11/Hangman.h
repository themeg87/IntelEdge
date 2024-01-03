#ifndef GHANGMAN_H
#define GHANGMAN_H

#include <string>
using namespace std;

class Console;
class Words;

class Hangman {
	Console *pConsole;
	int hiddenCount; // ����� ������ ����
	Words* pWords;
	string answerWord;
	string hiddenWord;
	int failCount;
	void makeHidden(string word);
	void go();
	bool complete(char key);
public:
	Hangman(Console *p, int hiddenCount);
	~Hangman();
	void run();
};

#endif