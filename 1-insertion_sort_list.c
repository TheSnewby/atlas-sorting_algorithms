#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *head = *list, *temp = NULL, *current_next;

	if (*list == NULL || (*list)->next == NULL)
		return;

	current = head->next;
	while (current != NULL)
	{
		current_next = current->next; /* tracks current's next node */
		temp = current->prev; /* backwards iterator */
		while (temp != NULL)
		{
			if (current->n < temp->n)
			{
				temp->next = current->next;
				if (current->next != NULL)
					current->next->prev = temp;
				current->next = temp;
				current->prev = temp->prev;
				if (temp->prev != NULL)
					temp->prev->next = current;
				else
					head = current;
				temp->prev = current;
				print_list(head);
			}
			temp = temp->prev; /* iterate */
	}
		current = current_next;
	}
	*list = head;
}
