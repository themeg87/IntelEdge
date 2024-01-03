#ifndef ENGINE_H
#define ENGINE_H

#include <string>
using namespace std;

#include "Container.h"

// Ŀ�� ���Ǳ��� �ٽ� Ŭ�����μ�, ������� Ŀ�� �������κ���
// �� �뿡 ��� �ִ� ��Ḧ ���̰ų� �ø��� ��, 
// Ŀ�� ���Ǳ⸦ �ùķ��̼� �ϴ� Ŭ����
class Engine { 
	Container *con; // ��ü ��鿡 ���� ������
public:
	Engine(Container []);
	void run(); // ���� �۵� 
	void show();
	void printWarning(int id);
};

#endif