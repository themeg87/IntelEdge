#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <string>
using namespace std;

class Buffer {
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) {
		text += next; // text�� next ���ڿ� �����̱� 
	}
	void print() {
		cout << text << endl;
	}
};

#endif
