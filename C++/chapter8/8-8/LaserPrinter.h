#ifndef LASERPRINTER_H
#define LASERPRINTER_H

#include <string>
#include "BasePrinter.h"
using namespace std;

class LaserPrinter : public BasePrinter {
	int availableToner;
public:
	LaserPrinter(string model, string manufacturer, int totalPapers, int totalToner);
	bool printLaser(int pages=1);
	void showState();
};

#endif