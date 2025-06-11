#include "sort.h"

/**
 * merge - merges arrays and sorts elements from smallest to largest
 * @arr: array of ints to be sorted
 * @sizeL: size of left array
 * @sizeR: size of right array
 */
void merge(int *arr, size_t sizeL, size_t sizeR)
{
	size_t i, l = 0, r = 0;
	int temp[1024];

	memcpy(temp, arr, sizeof(int) * (sizeL + sizeR));

	printf("Merging...\n[left]: ");
	for (i = 0; i < sizeL; i++)
	{
		if (i)
			printf(", ");
		printf("%d", temp[i]);
	}
	printf("\n[right]: ");
	for (i; i < sizeL + sizeR; i++)
	{
		if (i > sizeL)
			printf(", ");
		printf("%d", temp[i]);
	}
	printf("\n");

	i = 0;
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

	printf("[Done]: ");
	print_array(arr, sizeL + sizeR);
	printf("\n");
}

/**
 * merge_sort_algo - recursive helper to merge_sort
 * @array: array to be sorted
 * @size: size of array
 */
void merge_sort_algo(int *array, size_t size)
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

	merge_sort_algo(array, size);
}
