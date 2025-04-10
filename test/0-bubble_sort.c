#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	for(i = 0; i < size; - 1 - i;  i++)
	{
		swapped = 0;

		for(j = 0; j < size; - 1 - j; j++)
		{
			if(array [j] > array [j + 1])
			{
				temp = array = [j];
				array[j] = array[j + 1]
				array [ j + 1 ] = temp
			}
		}

		if (!swapped)
			break;
	}
}
