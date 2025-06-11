#include "sort.h"

/**
 * merge - merges arrays and sorts elements from smallest to largest
 * @arr: array of ints to be sorted
 * @sizeL: size of left array
 * @sizeR: size of right array
 */
void merge(int *arr, size_t sizeL, size_t sizeR)
{
	size_t i = 0, l = 0, r = 0;
	int *temp;

	temp = (int *)malloc(sizeof(int) * (sizeL + sizeR));
	/* consider using malloc in order to handle very large arrays */
	memcpy(temp, arr, sizeof(int) * (sizeL + sizeR));

	while (l < sizeL && r < sizeR)
	{
		if (temp[l] < temp[r + sizeL])
		{
			arr[i] = temp[l];
			l++;
		}
		else
		{
			arr[i] = temp[r + sizeL];
			r++;
		}
		i++;
	}

	while (l < sizeL)
	{
		arr[i++] = temp[l++];
	}

	while (r < sizeR)
	{
		arr[i++] = temp[r++ + sizeL];
	}

}

/**
 * merge_sort - top-down merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t midpoint, rightSize;

	if (!array || size < 2)
		return;

	midpoint = size / 2;
	rightSize = size - midpoint;

	merge_sort(array, midpoint);
	merge_sort(array + midpoint, rightSize);

	merge(array, midpoint, rightSize);
}
