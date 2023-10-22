#pragma once

#include <iostream>

template <typename T, typename Func>
void	iter(T* array, int length, Func function)
{
	for (int i = 0; i < length; i++)
		function(array[i]);
}