#include "sort.h"

/**
 * quick_sort - sorts an array of ints with the Lomuto quick sort
 * @array: array of ints
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int pivot;
	int *Larray = array;
	int *Rarray;

	if (size < 2)
		return;

	pivot = helper_qs(Larray, 0, size - 1, array, size);
	Rarray = array + pivot + 1;

	quick_sort(Larray, pivot);
	quick_sort(Rarray, size - pivot - 1);
}

/**
 * helper_qs - recursive caller for quick sorting
 * @array: array of ints
 * @low: lower index of section being quick sorted
 * @high: upper index of section being quick sorted
 * @orig_array: pointer to start of full array
 * @size: size of original full array
 *
 * Return: increments i upwards by 1
 */
int helper_qs(int *array, int low, int high, int *orig_array, size_t size)
{
	int pivot, i, j, swap;

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
			print_array(orig_array, size);
		}
	}
	swap = array[high];
	array[high] = array[i + 1];
	array[i + 1] = swap;
	print_array(orig_array, size);
	return (i + 1);
}