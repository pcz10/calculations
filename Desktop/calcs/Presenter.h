#ifndef PRESENTER_H
#define PRESENTER_H

#include "RandomValuesArray.h"

class Presenter
{
public:
	Presenter(RandomValuesArray& obj);

	void displayMean() const;
	void displaySum()const;
	void displayMedian() const;
	void displayVariance() const;
    void displayStandardDeviation() const;
	void displayMax() const;
	void displayMin() const;
	void displayAscendingOrder() const;
	void displayDescendingOrder() const;
	void makeAllOperations() const;
private:
	RandomValuesArray& o;
	void printArray() const;
};

#endif