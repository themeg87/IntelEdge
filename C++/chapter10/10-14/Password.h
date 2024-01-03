#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
#include <map>
using namespace std;

class PasswordManager {
	string program;
	map<string, string> passwordMap;
	void add();
	void search();
	bool checkInputError();
public:
	PasswordManager(string);
	void run();
};

#endif
