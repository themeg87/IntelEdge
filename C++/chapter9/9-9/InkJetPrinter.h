#ifndef INKJETPRINTER_H
#define INKJETPRINTER_H

#include <string>
#include "BasePrinter.h"
using namespace std;

class InkJetPrinter : public BasePrinter {
	int availableInk;
public:
	InkJetPrinter(string model, string manufacturer, int totalPapers, int totalInk);
	bool print(int pages=1);
	void show();
};

#endif