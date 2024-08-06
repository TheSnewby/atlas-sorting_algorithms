#include "sort.h"

/**
 * quick_sort - sorts an array of ints with the Lomuto quick sort
 * @array: array of ints
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_qs(array, 0, size - 1, size);
}

/**
 * recursive_qs - recursive qs calls
 * @array: pointer to array
 * @low: low index of section being quicksorted
 * @high: high index of section being quicksorted
 * @size: size of array
 */
void recursive_qs(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = helper_qs(array, low, high, size);

		recursive_qs(array, low, pivot - 1, size);
		recursive_qs(array, pivot + 1, high, size);
	}
}

/**
 * helper_qs - helper for recursive calls for quick sorting
 * @array: array of ints
 * @low: lower index of section being quick sorted
 * @high: upper index of section being quick sorted
 * @size: size of original full array
 *
 * Return: increments i upwards by 1
 */
int helper_qs(int *array, int low, int high, size_t size)
{
	int pivot, i, j, swap;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[j];
				array[j] = array[i];
				array[i] = swap;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap = array[high];
		array[high] = array[i + 1];
		array[i + 1] = swap;
		print_array(array, size);
	}
	return (i + 1);
}
