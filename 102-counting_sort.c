// #include "sort.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct hash_s {
	int *array;
	int size;
} hash_t;

hash_t *create_htable(size_t size)
{
	hash_t *new_htable = (hash_t *)malloc(sizeof(hash_t));
	if (!new_htable)
		perror("Failed to create new_htable");
	new_htable->array = (int *)calloc(size, sizeof(int));
	if (!new_htable->array)
		perror("Failed to create new_htable->array");
	new_htable->size = size;

	return (new_htable);
}

void destroy_htable(hash_t *ht)
{
	free(ht->array);
	free(ht);
}

void print_htable(hash_t *ht)
{
	int i;

	for (i = 0; i < ht->size; i++)
	{
		if (i)
			printf(", ");
		printf("%d", ht->array[i]);
	}
}

void print_array(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (i)
			printf(", ");
		printf("%d", array[i]);
	}
}

/**
 * counting_sort - sorts an array of ints in ascending order with Counting Sort
 * @array: array of positive integers
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int i, j;
	int key, max;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	hash_t *count = create_htable(max + 1);
	hash_t *output = create_htable(max + 1);

	for (i = 0; i < size; i++)
	{
		j = array[i]; /* key */
		count->array[j] += 1;
	}

	for (i = 1; i <= max; i++)
		count->array[i] += count->array[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		j = array[i];
		count->array[j] = count->array[j] - 1;
		output->array[count->array[j]] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = output->array[i];

	print_htable(output);
	destroy_htable(output);
	destroy_htable(count);

}

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    counting_sort(array, n);
    printf("\n");
    print_array(array, n);
	printf("\n");
    return (0);
}
