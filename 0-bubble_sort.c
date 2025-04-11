#include "sort.h"
#include <stdio.h>
#include <stddef.h>
/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble Sort algorithm
 * @array: array being sorts
 * @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	unsigned int i;
	int temp;
	int swapped;

	/*If array has less than 2 elements, no swap needed*/
	if (size < 2)
	{
		return;
	}
	/*run this loop until no swaps happen during a full pass*/
	while (1)
	{
		/*resetting variable*/
		swapped = 0;
		/*compares each adjacent element*/
		for (i = 0; i < size - 1; i++)
		{
			/*if greater than, swap*/
			if (array[i] > array[i + 1])
			{
				/*swap using temp variable*/
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		/*check for completion*/
		if (swapped == 0)
		{
			/*used to break out of loop*/
			break;
		}
	}
}
