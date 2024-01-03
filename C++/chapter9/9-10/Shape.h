#ifndef SHAPE_H
#define SHAPE_H

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	void paint();
	Shape* getNext() { return next; }
	Shape* add(Shape* p) { next = p; return p; }
};

#endif
