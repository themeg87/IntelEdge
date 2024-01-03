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
	bool print(int pages=1);
	string getModel() { return model; }
	string getManufacturer() { return manufacturer; }
	int getPrintedCount() { return printedCount; }
	int getAvailableCount() { return availableCount; }
	void show();
};

#endif