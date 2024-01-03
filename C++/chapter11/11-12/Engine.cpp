#include <iostream>
using namespace std;

#include "define.h"
#include "Container.h"
#include "Engine.h"
#include "Panel.h"

Engine::Engine(Container con[]) { // Ŀ�� ���Ǳ⿡ �����ϴ� ��鿡 ���� ������ ���� ����
	this->con = con;
}

void Engine::run() { // ���� �۵�
	show(); // ���� Ŀ�� ���Ǳ� ���� ���. ���� �� ���� �뷮 ���

	while(true) {
		int menu = Panel::getButton(); // ����ڷκ��� Ŀ�� ���� �����Ͽ� ����
		switch(menu) {
			case BLACK_COFFEE :
				if(!con[COFFEE].consume()) { // Ŀ�� ����
					printWarning(COFFEE);
					break;
				}
				if(!con[WATER].consume()) { // �� ����
					printWarning(WATER);
					break;
				}
				if(!con[CUP].consume()) { // �� ����
					printWarning(CUP);
					break;
				}
				cout << "���ִ� �� Ŀ�� ���Խ��ϴ�~~" << endl;
				break;
			case SUGAR_COFFEE :
				if(!con[COFFEE].consume()) { // Ŀ�� ����
					printWarning(COFFEE); // Ŀ�ǰ� ���� �� ��� �޽��� ���
					break;
				}
				if(!con[WATER].consume()) { // �� ����
					printWarning(WATER);
					break;
				}
				if(!con[CUP].consume()) { // �� ����
					printWarning(CUP);
					break;
				}
				if(!con[SUGAR].consume()) { // ���� ����
					printWarning(SUGAR);
					break;
				}
				cout << "���ִ� ���� Ŀ�� ���Խ��ϴ�~~" << endl;
				break;
			case NORMAL_COFFEE:
				if(!con[COFFEE].consume()) { // Ŀ�� ����
					printWarning(COFFEE);
					break;
				}
				if(!con[WATER].consume()) { // �� ����
					printWarning(WATER);
					break;
				}
				if(!con[CUP].consume()) { // �� ����
					printWarning(CUP);
					break;
				}
				if(!con[SUGAR].consume()) { // ���� ����
					printWarning(SUGAR);
					break;
				}
				if(!con[CREAM].consume()) { // ũ�� ����
					printWarning(CREAM);
					break;
				}
				cout << "���ִ� �ٹ� Ŀ�� ���Խ��ϴ�~~" << endl;
				break;
			case FILL: // ��� ��Ḧ �ִ�� ä���.
				cout << "��� ���� ä��ϴ�.~~" << endl;
				for(int i=0;  i<5; i++) con[i].fill(); // ��� �뿡 ��� �ִ�� ä��
				break;
			case EXIT: // ���� �޴�
				return; // ���� ����
		}
		show();
	}
}

void Engine::show() {
	for(int i=0;  i<5; i++) 
		con[i].show();
	cout << endl;
}

void Engine::printWarning(int id) {
	switch(id) {
		case COFFEE : cout << "Ŀ�ǰ� �����ϴ�." <<endl;  break;
		case SUGAR : cout << "������ �����ϴ�." <<endl;  break;
		case CREAM : cout << "ũ���� �����ϴ�." <<endl;  break;
		case WATER : cout << "���� �����ϴ�." <<endl;  break;
		case CUP : cout << "���� �����ϴ�." <<endl;  break;
	}
}