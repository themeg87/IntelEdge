#include "Hangman.h"
#include "Console.h"

void main() {
	Console *c = new Console();
	Hangman *e = new Hangman(c, 2); // ����� ������ ������ 2���� �Ѵ�.

	e->run();

	delete e;
	delete c;
}