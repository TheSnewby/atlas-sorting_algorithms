#include "sort.h"

/**
 * quick_sort - sorts an array of ints with the Lomuto quick sort
 * @array: array of ints
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int pivot;

	if (size < 2)
		return;

	pivot = helper_qs(array, 0, size - 1, size);

	quick_sort(array, pivot);
	quick_sort(array + pivot + 1, size - pivot - 1);
}

/**
 * helper_qs - recursive caller for quick sorting
 * @array: array of ints
 * @low: lower index of section being quick sorted
 * @high: upper index of section being quick sorted
 *
 * Return: increments i upwards by 1
 */
int helper_qs(int *array, int low, int high, size_t size)
{
	int pivot, i, j, swap;
	size_t original_size = size;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap = array[j];
			array[j] = array[i];
			array[i] = swap;
			print_array(array, original_size);
		}
	}
	swap = array[high];
	array[high] = array[i + 1];
	array[i + 1] = swap;
	print_array(array, original_size);
	return (i + 1);
}