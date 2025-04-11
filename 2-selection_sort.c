#include "sort.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
/**
 * selection_sort - sorts an array of integers in ascending
 * order using the selection sort algorithm
 * @array: array being sorted
 * @size: size of array
*/
void selection_sort(int *array, size_t size)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int temp;
	unsigned int min_index;

	if (size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
