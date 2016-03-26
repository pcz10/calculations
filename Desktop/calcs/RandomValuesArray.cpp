#include "RandomValuesArray.h"
#include <random>
#include <ctime>
#include <iostream>
#include<algorithm>
#include<numeric>
#define RANGE_OF_RANDOMS 100

RandomValuesArray::RandomValuesArray(int N) : arrSize(N)
{
	srand((unsigned)time(NULL));
	   
	for (int i = 0; i < N; ++i)
	{
		int b = rand() % RANGE_OF_RANDOMS + 1;
		tableOfValues.push_back(b);
	}
}
int  RandomValuesArray::size() const
{
	return arrSize;
}
int RandomValuesArray::at(unsigned index) const
{
	if (index > arrSize || index < 0) 
		throw std::out_of_range{ "Index out of range" };
	return tableOfValues[index];
}
double  RandomValuesArray::mean() const
{
	return  static_cast<double>(sum()) / tableOfValues.size();
}

int RandomValuesArray::sum() const
{
	return  std::accumulate(tableOfValues.cbegin(), tableOfValues.cend(), 0);
}

double RandomValuesArray::median() const
{
	if (tableOfValues.size() % 2 == 0)
		return static_cast<double>(static_cast<double>(tableOfValues[(arrSize / 2) - 1]) + static_cast<double>(tableOfValues[(arrSize / 2)])) / 2;
	return tableOfValues[(arrSize / 2)];
}
int RandomValuesArray::variance() const
{
	return  std::pow(standardDeviation(), 2);
};
double RandomValuesArray::standardDeviation() const
{
	int controlVar{ 0 };
	for (auto& item : tableOfValues)
	{
		controlVar += std::pow((item - mean()), 2);
	}
	return static_cast<double>(sqrt(controlVar / tableOfValues.size()));
}
int RandomValuesArray::max() const
{
	auto biggestValue = std::max_element(tableOfValues.cbegin(), tableOfValues.cend());
	return *biggestValue;
}
int RandomValuesArray::min() const
{
	auto smallestValue = std::min_element(std::cbegin(tableOfValues), std::cend(tableOfValues));
	return *smallestValue;
}
void RandomValuesArray::divideOnPartitions(std::vector<int>& A, int p, int q, std::function<bool(int, int)> compare)
{
	int partitioner;
	if (p < q)
	{
		partitioner = sortHelper(A, p, q, compare);
		divideOnPartitions(A, p, partitioner, compare);
		divideOnPartitions(A, partitioner + 1, q, compare);
	}
}
void RandomValuesArray::sort(std::function<bool(int, int)> compare)
{
	divideOnPartitions(tableOfValues, 0, arrSize, compare);
}
int RandomValuesArray::sortHelper(std::vector<int>& tab, int p, int q, std::function<bool(int,int)> compare)
{
	int x = tab[p];
	int i = p;
	int j;
	
	for (j = p + 1; j < q; ++j)
	{
		if (compare(tab[j],x))
		{
			i += 1;
			std::swap(tab[i], tab[j]);
		}
	}
	std::swap(tab[i], tab[p]);
	return i;
}

