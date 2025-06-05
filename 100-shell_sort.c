#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - performs the Donald Shell sorting algorithm
 * @array: integer array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int swap;
	size_t gap, i, j, largest_gap;

	if (!array || size < 2)
		return;

	for (gap = 1; gap <= size; gap = gap * 3 + 1)
		largest_gap = gap;

	for (gap = largest_gap; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i += 1)
		{
			swap = array[i];

			for (j = i; (j >= gap) && (array[j - gap] > swap); j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = swap;
		}
		print_array(array, size);
	}
}
