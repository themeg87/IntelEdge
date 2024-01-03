#include <iostream>
using namespace std;

#include "Hangman.h"
#include "Console.h"
#include "Words.h"

Hangman::Hangman(Console *c, int hiddenCount) {
	pConsole = c;
	this->hiddenCount = hiddenCount;
	pWords = NULL;
	pWords = new Words("words.txt");
}

Hangman::~Hangman() {
	if(pWords)
		delete pWords;
}

void Hangman::run() {
	pConsole->write("--------------------------------");
	pConsole->write("���ݺ��� ��� ������ �����մϴ�.");
	pConsole->write("--------------------------------");

	while(true) {
		answerWord = pWords->getNext(); // ���ӿ� ����� �ܾ �����Ѵ�.
		pConsole->beep(); // �ý��� beep�� �︰��.
		makeHidden(answerWord); // ���� �ܾ 2 ���� ���ڰ� ������ �ܾ ����� hiddenWord�� �����Ѵ�.
//		pConsole->write(answerWord); // ���� �ܾ �����ش�.

		go(); // ����ڷκ��� Ű�� �Է¹ް� ������ �����Ѵ�.
		char ans = pConsole->prompt("Next(y/n)?");
		if(ans != 'y')
			break;
	}
}

void Hangman::makeHidden(string word) { // word�� 2���� ���ڸ� ���� '-'�� ��ġ�Ͽ� hiddenWord�� �����.
	hiddenWord = word;
	int length = word.length();
	for(int k=0; k<hiddenCount; k++) { // hiddenCount ���� ��ŭ ���� ����
		int n = rand() % length; // ���� �ܾ��� ��ġ�� �����ϰ� ����
		char c = word[n];
		for(int i=0; i<length; i++) {
			if(hiddenWord[i] == c)
				hiddenWord[i] = '-'; // ���� ���� ��ġ�� '-' ���� ����
		}
	}
}

void Hangman::go() {
	failCount=0;
	char key;
	do {
		if(failCount == 5) {
			pConsole->write("5�� ���� �Ͽ����ϴ�.");
			break;
		}
		pConsole->write(hiddenWord); // ������ ���ڰ� �ִ� �ܾ �����ش�.
		key = pConsole->prompt(">>"); // ����ڷκ��� Ű�� �Է¹޴´�.
	}while(!complete(key)); // ����ڰ� �Է��� Ű�� ������ Ű���� �˻��Ѵ�.
	// ������ Ű�� ��� ã������ complete()�� true�� �����Ѵ�.

	// ������ ������ ������ �����ش�.
	pConsole->write(answerWord);
}

bool Hangman::complete(char key) { // key�� �Էµ� ����
	bool hit = false;
	int length = hiddenWord.length();
	for(int i=0; i<length; i++) { // ������ �ܾ��� '-'�� ��� ���ڸ� key ���ڿ� ���Ͽ� ����
		if(hiddenWord[i] == '-')
			if(answerWord[i] == key) {  // key ���ڰ� ������ ���ڿ� �ش��ϸ�
				hiddenWord[i] = key; // hiddenWord�� '-' ���ڸ� key�� ����
				hit = true;
			}
	}
	if(!hit)
		failCount++; // ���� ȸ�� ����
	for(int i=0; i<length; i++) {
		if(hiddenWord[i] == '-') // ������ '-' ���ڰ� ���� ������ 
			return false;
	}
	return true; // '-' ���ڰ� �ϳ��� ������ ����
}