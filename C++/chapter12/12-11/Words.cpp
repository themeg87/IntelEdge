#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Words.h"

Words::Words(const char* fileName) {
	fin.open(fileName);
	if(!fin) {
		cout << fileName << " ���� ����" << endl;
		exit(0); // ���α׷� ����
	}

	// words.txt ������ �о� wordVector�� ����
	string word;
	while(getline(fin, word)) { // ���Ͽ��� �� ������ �д´�.
		wordVector.push_back(word); // ���� �ܾ ���Ϳ� �����Ѵ�.
	}

	// ���� �� �߻��� ���� seed ����
	srand( (unsigned)time( 0 ) );
}

Words::~Words() {
	fin.close();
}

string Words::getNext() { // ���ӿ� ����� �ܾ ���Ϳ��� �����Ͽ� �����Ѵ�.
	string word;
	int n = rand() % wordVector.size(); // ������ ���� ������ ������ ��ġ ����
	return wordVector[n]; // ���õ� ��ġ�� �ܾ �����Ѵ�.
}