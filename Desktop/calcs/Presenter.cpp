#include "Presenter.h"
#include <iostream>
Presenter::Presenter(RandomValuesArray& obj) : o(obj) { }

void Presenter::displayMean() const
{
	std::cout <<"Mean: "<< o.mean() << std::endl;
}
void Presenter::displaySum() const
{
	std::cout <<"Sum: " << o.sum() << std::endl;
}
void Presenter::displayMedian() const
{
	std::cout <<"Median: " << o.median() << std::endl;
}
void Presenter::displayVariance() const
{
	std::cout << "Variance: " << o.variance() << std::endl;
}
void Presenter::displayStandardDeviation() const
{
	std::cout << "Standard deviation: " << o.standardDeviation() << std::endl;
}
void Presenter::displayMax() const
{
	std::cout << "Max value: " << o.max() << std::endl;
}
void Presenter::displayMin() const
{
	std::cout << "Min value: " << o.min() << std::endl;
}
void Presenter::displayAscendingOrder() const
{
	std::cout << "Descending Order: " << std::endl;
	o.sort(std::greater<int>());
	printArray();
}
void Presenter::displayDescendingOrder() const
{
	std::cout << "Ascending Order: " << std::endl;
	o.sort(std::less<int>());
	printArray();
}
void Presenter::printArray() const
{
	for (auto i = 0; i < o.size(); ++i)
		std::cout << " " << o.at(i);
	std::cout << "" << std::endl;
}
void Presenter::makeAllOperations() const
{
	this->displayMean();
	this->displaySum();
	this->displayMedian();
	this->displayVariance();
	this->displayStandardDeviation();
	this->displayMax();
	this->displayMin();
	this->displayAscendingOrder();
	this->displayDescendingOrder();
}
