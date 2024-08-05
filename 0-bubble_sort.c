#include "sort.h"

/**
 * performs a bubble sort on sortable data in ascending order
 * @array: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, newn, swap;

	while (size > 1)
	{
		newn = 0;
		for (i = 0; i <= size - 1; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap = array[i];
				array[i] = array[i - 1];
				array[i - 1] = swap;
				newn = i;
			}
		}
		size = newn;
	}
}
