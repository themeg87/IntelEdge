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
		delete v->at(i); //원소 객체를 하나씩 소멸 시킨다.

	delete v;
}

void GraphicEditor::paint() { // 벡터에 연결된 모든 객체를 그린다.
	if(v->size() == 0) {
		UI::println("그려진 도형이 없습니다.");
		return;
	}
	for(int i=0; i<v->size(); i++) {
		UI::print(i); // 인덱스 출력
		UI::print(": "); 
		v->at(i)->paint(); // 원소 객체(도형) 그리기
	}
}

void GraphicEditor::run() { // 그래픽 에디터의 메인 함수
	UI::println("그래픽 에디터입니다.");
	while(true) {
		int menu = UI::getMainMenu();
		switch(menu) {
			case EDIT: // 삽입
				edit(); break;
			case REMOVE: // 삭제
				remove(); break;
			case PAINT: // 다시 그리기
				paint(); break;
			case EXIT: // 끝내기
				return;
			default:
				UI::println("명령 선택 오류");
		}
	}
}

void GraphicEditor::edit() {
	int shapeType = UI::getShapeType();
	switch(shapeType) {
		case LINE: // 라인
			add(new Line()); break;
		case CIRCLE: // 원
			add(new Circle()); break;
		case RECT: // 사각형
			add(new Rect()); break;
		default:
			UI::println("도형 선택 오류");
	}
}

void GraphicEditor::remove() {
	int shapeIndex = UI::getShapeIndex();
	remove(shapeIndex);
}

void GraphicEditor::remove(int shapeIndex) {
	// shapeIndex의 원소를 삭제한다.
	if(v->size() == 0) {
		UI::println("그려진 도형이 없습니다.");
		return;
	}	

	ShapeVector::iterator it = v->begin() + shapeIndex;
	delete v->at(shapeIndex); // 도형 메모리 반환
	v->erase(it); // 벡터의 원소 삭제
}

void GraphicEditor::add(Shape* p) {
	v->push_back(p);
}