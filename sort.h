#ifndef sort_h
#define sort_h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * struct hash_s - Structure for a hash table
 * @array: Pointer to the array that stores the hash table elements
 * @size: The size of the hash table (number of elements in the array)
 *
 * Description: This structure defines a simple hash table that uses an
 * integer array to store its elements.
 */
typedef struct hash_s
{
	int *array;
	int size;
} hash_t;


void print_array(const int *, size_t);
void print_list(const listint_t *);
void bubble_sort(int *, size_t);
void insertion_sort_list(listint_t **);
void selection_sort(int *, size_t);
void quick_sort(int *, size_t);
int helper_qs(int *, int, int, size_t);
void recursive_qs(int *, int, int, size_t);
void shell_sort(int *, size_t);
void counting_sort(int *, size_t);
void merge_sort(int *, size_t);

#endif
