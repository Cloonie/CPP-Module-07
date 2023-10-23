#include <cstdlib>  // For srand and rand
#include <ctime>    // For time
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	// Create a class Array and a standard int array and set random value
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));

	// assign the same rand value for both Array and mirror
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	// test copy and assign constructor
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	// handle error if both value are not the same
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	// testing exception cases (less than 0 || more than MAX_VAL)
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;
}