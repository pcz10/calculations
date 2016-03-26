#ifndef RANDOMVALARRAY_H
#define RANDOMVALARRAY_H

#include<vector>
#include<functional>
class RandomValuesArray
{
public:
	RandomValuesArray(int N);
	void print();
	int size() const;
	int at(unsigned index) const;

	//osobiscie, wepchalbym te funkcje w osobn¹ klase, np. StatisticMethods
	double mean() const;
	int sum() const;
	double median() const;
	int variance() const;
	double standardDeviation() const;
	int max() const;
	int min() const;
	void sort(std::function<bool(int, int)>);
private:
	std::vector<int> tableOfValues;
	unsigned arrSize;
	int sortHelper(std::vector<int>&, int, int, std::function<bool(int, int)>);
	void divideOnPartitions(std::vector<int>&, int, int, std::function<bool(int, int)>);
};


#endif // !RANDOMVALARRAY_H