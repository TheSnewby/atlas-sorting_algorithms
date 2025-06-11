#include "sort.h"

/**
 * merge - merges arrays and sorts elements from smallest to largest
 * @arr: array of ints to be sorted
 * @temp: temporary array
 * @sizeL: size of left array
 * @sizeR: size of right array
 */
void merge(int *arr, int *temp, size_t sizeL, size_t sizeR)
{
	size_t i = 0, l = 0, r = 0;

	/* consider using malloc in order to handle very large arrays */
	memcpy(temp, arr, sizeof(int) * (sizeL + sizeR));

	while (l < sizeL && r < sizeR)
	{
		if (temp[l] < temp[r + sizeL])
			arr[i] = temp[l++];
		else
			arr[i] = temp[r++ + sizeL];
		i++;
	}

	while (l < sizeL)
		arr[i++] = temp[l++];

	while (r < sizeR)
		arr[i++] = temp[r++ + sizeL];
}

/**
 * merge_sort_algo - recursive helper to merge_sort
 * @array: array to be sorted
 * @temp: temporary array for handling
 * @size: size of array
 */
void merge_sort_algo(int *array, int *temp, size_t size)
{
	size_t midpoint, rightSize;

	if (!array || size < 2)
		return;

	midpoint = size / 2;
	rightSize = size - midpoint;

	merge_sort(array, midpoint);
	merge_sort(array + midpoint, rightSize);

	merge(array, temp, midpoint, rightSize);
}
/**
 * merge_sort - top-down merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = (int *)malloc(sizeof(int) * size);
	merge_sort_algo(array, temp, size);
	free(temp);
}
