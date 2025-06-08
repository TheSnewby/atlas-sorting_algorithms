#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * create_htable - Creates a new hash table
 * @size: The desired size of the hash table (number of elements)
 *
 * Return: A pointer to the newly created hash_t structure, or NULL if
 *          memory allocation fails.
 */
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

/**
 * destroy_htable - Destroys a hash table and frees allocated memory
 * @ht: A pointer to the hash_t structure to be destroyed
 *
 * Return: void
 */
void destroy_htable(hash_t *ht)
{
	free(ht->array);
	free(ht);
}

/**
 * print_htable - Prints the elements of a hash table
 * @ht: A pointer to the hash_t structure to be printed
 *
 * Return: void
 */
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

/**
 * counting_sort - sorts an array of ints in ascending order with Counting Sort
 * @array: array of positive integers
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int i, key, max;
	hash_t *count = NULL, *output = NULL;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	count = create_htable(max + 1);
	output = create_htable(max + 1);

	for (i = 0; i < (int)size; i++)
	{
		key = array[i]; /* key */
		count->array[key] += 1;
	}

	for (i = 1; i <= max; i++)
		count->array[i] += count->array[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		key = array[i];
		count->array[key] = count->array[key] - 1;
		output->array[count->array[key]] = array[i];
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output->array[i];

	print_htable(count);
	destroy_htable(output);
	destroy_htable(count);

}
