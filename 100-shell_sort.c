#include <stdio.h>

/**
 * print_array - prints an array
 * @array: integer array to be sorted
 * @size: size of the array
 */
void print_array(int *array, size_t size)
{
	size_t i;
	printf(("["));
	for (i = 0; i < size; i++)
	{
		if (i)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("]\n");
}

/**
 * shell_sort - performs the Donald Shell sorting algorithm
 * @array: integer array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int swap;
	size_t gap, i, j, largest_gap;

	for (gap = 0; gap <= size / 2; gap = gap * 3 + 1)
		largest_gap = gap;

	for (gap = largest_gap; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i+= 1)
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
/*
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    shell_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
*/