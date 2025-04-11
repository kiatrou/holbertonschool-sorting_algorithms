#include "sort.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
/**
 * lomuto_partition - takes a segment of the array, picks the last element
 * as the pivot and reorders the array
 * @array: array being used
 * @low: starting index
 * @high: ending index
 * @size: size of array
 *
 * Return: final position of pivot
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot_index = array[high];

	int i = low - 1;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot_index)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quick_sort_recursive - sorts the array
 * @array: array being sorted
 * @low: starting index
 * @high: ending index
 * @size: size of array
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm and the Lomuto partition scheme
 * @array: array being sorted
 * @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_recursive(array, 0, size - 1, size);
}
