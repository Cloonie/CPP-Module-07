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
		std::cout << "Using operator=: ";
		Array<int> tmp = numbers;
		std::cout << "Using obj(int n): ";
		Array<int> test(tmp);
	}

	// numbers[123] = 123;

	// handle error if both value are not the same
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << " (mirror[i]: " << mirror[i] << ", numbers[i]: " << numbers[i] << ")" << std::endl;
			return 1;
		}
	}

	// testing exception cases (less than 0 || more than MAX_VAL)
	try
	{
		std::cout << "Test Case 1: ";
		numbers[-1] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Test Case 2: ";
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

	// Array member function size()
	std::cout << numbers.size() << std::endl;

	delete [] mirror;
	return 0;
}