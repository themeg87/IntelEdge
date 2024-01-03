#ifndef BASEPRINTER_H
#define BASEPRINTER_H

#include <string>
using namespace std;

class BasePrinter {
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
public:
	BasePrinter(string model, string manufacturer, int totalPapers);
protected:
	virtual bool print(int pages=1);
	virtual void show();

	string getModel() { return model; }
	string getManufacturer() { return manufacturer; }
	int getPrintedCount() { return printedCount; }
	int getAvailableCount() { return availableCount; }

};

#endif