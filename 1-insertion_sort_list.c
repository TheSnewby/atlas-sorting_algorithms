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
		if (current->n < head->n) /* check head first */
		{
			updateCurrentSurroundingNodes(list, current);
			current->next = head; /* update current's next & prev */
			current->prev = NULL;
			head->prev = current;
			head = current; /* update head */
			print_list(head);
		}
		else
		{
			/* insert current element in between others if not largest */
			temp = current->prev; /* iterator */
			while (temp != NULL)
			{	/* updates current's surrounding nodes */
				if (current->n > temp->n && current->n < temp->next->n)
				{
					updateCurrentSurroundingNodes(list, current);
					current->next = temp->next;
					current->prev = temp;
					current->next->prev = current;
					current->prev->next = current;
					print_list(head);
					break;
				}
				temp = temp->prev; /* iterate */
			}
		}
		current = current_next;
	}
	*list = head; /* consider for final action */
}

/**
 * updateCurrentSurroundingNodes - updates next->prev & prev->next at current
 * @list: pointer to doubly linked list
 * @current: pointer to current node
 */
void updateCurrentSurroundingNodes(listint_t **list, listint_t *current)
{
/* update current's surrounding nodes */
	if (current->next != NULL)
	{
		current->next->prev = current->prev;
		current->prev->next = current->next;
	}
	else
		current->prev->next = NULL; /* update prev's next */
}
