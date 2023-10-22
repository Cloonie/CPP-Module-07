#include "iter.hpp"

template <typename T>
void printElement(const T& element)
{
	std::cout << element << " ";
}

int	main(void)
{
	const char	*array = "Hello World!";
	char		charArray[] = {'A', 'B', 'C', 'D', 'E'};
	int			intArray[] = {1, 2, 3, 4, 5};
	double		doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

	iter(array, 12, printElement<char>);
	std::cout << std::endl;
	iter(charArray, 5, printElement<char>);
	std::cout << std::endl;
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;
	iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl;
}