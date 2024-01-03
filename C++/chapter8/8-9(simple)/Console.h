#ifndef CONSOLE_H
#define CONSOLE_H

#include<string>
using namespace std;

class Console{
public:
	static int getMainMenu();
	static int getScheduleMenu();
	static string getName();
	static int getSeatNo();
	static void print(string);
};

#endif