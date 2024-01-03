#ifndef PRINTERMANAGER_H
#define PRINTERMANAGER_H

#include "InkJetPrinter.h"
#include "LaserPrinter.h"

class PrinterManager {
	InkJetPrinter *ip;
	LaserPrinter *lp;
public:
	PrinterManager();
	~PrinterManager();
	void operate();
};

#endif