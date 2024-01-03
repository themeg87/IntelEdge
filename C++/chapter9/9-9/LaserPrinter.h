#ifndef LASERPRINTER_H
#define LASERPRINTER_H

#include <string>
#include "BasePrinter.h"
using namespace std;

class LaserPrinter : public BasePrinter {
	int availableToner;
public:
	LaserPrinter(string model, string manufacturer, int totalPapers, int totalToner);
	bool print(int pages=1);
	void show();
};

#endif