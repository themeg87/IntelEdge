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
		text += next; // text에 next 문자열 덧붙이기 
	}
	void print() {
		cout << text << endl;
	}
};

#endif
