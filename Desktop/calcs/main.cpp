#include "RandomValuesArray.h"
#include "Presenter.h"
#include <iostream>
#include <string>
int main(int argc, char** argv)
{
	if (argc < 2) 
	{
		std::cout << "No arguments passed.";
		return 0;
	}
	for (auto i = 1; i < argc; ++i)
	{
		std::cout << "*******************************************************************" << std::endl;
		std::cout << "Object :" << i << std::endl;
		RandomValuesArray arrayObject{ std::stoi(argv[i]) };
		Presenter viewer(arrayObject);
		viewer.makeAllOperations();
		std::cout << "*******************************************************************" << std::endl;
	}
	return 0;
}