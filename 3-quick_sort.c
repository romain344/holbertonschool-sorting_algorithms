#include "sort.h"
#include <stdio.h>

/**
 * swap - function to swap value
 * @a: pointer to the first value
 * @b: pointer to the second value
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * Lomuto_partition - function to find the partition position
 * @array: array to sort
 * @low: starting index of the partition
 * @high: ending index of the partition
 *
 * Return: return the partition point
 */

int Lomuto_partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_rec - Recursive quick sort
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 */

void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = Lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, pivot_index - 1, size);
		quick_sort_rec(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - function to quicksort the value of an array
 * @array: pointer to the array
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
