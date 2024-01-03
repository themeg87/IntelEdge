#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H

#include <vector>
using namespace std;

class Shape;

typedef vector<Shape*> ShapeVector;

class GraphicEditor {
	vector<Shape*> *v;
	enum {LINE=1, CIRCLE=2, RECT=3};
	enum {EDIT=1, REMOVE=2, PAINT=3, EXIT=4};
	Shape* pStart;
	Shape* pLast;
	void add(Shape* p);
protected:
	void paint();
	void edit();
	void remove(int shapeIndex);
	void remove();
public:
	GraphicEditor();
	~GraphicEditor();
	void run();
};

#endif;