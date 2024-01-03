#include <iostream>
#include <vector>
using namespace std;

#include "GraphicEditor.h"
#include "Shape.h"
#include "UI.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"

GraphicEditor::GraphicEditor() {
	v = new ShapeVector;
}

GraphicEditor::~GraphicEditor() {
	int n=v->size();
	for(int i=0; i<n; i++) 
		delete v->at(i); //���� ��ü�� �ϳ��� �Ҹ� ��Ų��.

	delete v;
}

void GraphicEditor::paint() { // ���Ϳ� ����� ��� ��ü�� �׸���.
	if(v->size() == 0) {
		UI::println("�׷��� ������ �����ϴ�.");
		return;
	}
	for(int i=0; i<v->size(); i++) {
		UI::print(i); // �ε��� ���
		UI::print(": "); 
		v->at(i)->paint(); // ���� ��ü(����) �׸���
	}
}

void GraphicEditor::run() { // �׷��� �������� ���� �Լ�
	UI::println("�׷��� �������Դϴ�.");
	while(true) {
		int menu = UI::getMainMenu();
		switch(menu) {
			case EDIT: // ����
				edit(); break;
			case REMOVE: // ����
				remove(); break;
			case PAINT: // �ٽ� �׸���
				paint(); break;
			case EXIT: // ������
				return;
			default:
				UI::println("��� ���� ����");
		}
	}
}

void GraphicEditor::edit() {
	int shapeType = UI::getShapeType();
	switch(shapeType) {
		case LINE: // ����
			add(new Line()); break;
		case CIRCLE: // ��
			add(new Circle()); break;
		case RECT: // �簢��
			add(new Rect()); break;
		default:
			UI::println("���� ���� ����");
	}
}

void GraphicEditor::remove() {
	int shapeIndex = UI::getShapeIndex();
	remove(shapeIndex);
}

void GraphicEditor::remove(int shapeIndex) {
	// shapeIndex�� ���Ҹ� �����Ѵ�.
	if(v->size() == 0) {
		UI::println("�׷��� ������ �����ϴ�.");
		return;
	}	

	ShapeVector::iterator it = v->begin() + shapeIndex;
	delete v->at(shapeIndex); // ���� �޸� ��ȯ
	v->erase(it); // ������ ���� ����
}

void GraphicEditor::add(Shape* p) {
	v->push_back(p);
}