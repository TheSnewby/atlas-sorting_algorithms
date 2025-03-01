#include "sort.h"

/**
 * selection_sort - sorts an array of ints ascendingly with selection sort
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min, swap;

	for (i = 0; i < (int)size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < (int)size; j++)
		{
			if (array[j] < array[min])
				min = j; /* index of new min */
		}
		if (min != i)
		{
			swap = array[i];
			array[i] = array[min];
			array[min] = swap;
			print_array(array, size);
		}
	}
}
