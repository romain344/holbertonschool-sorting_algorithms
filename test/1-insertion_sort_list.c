#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		prev = current->prev;
		next = current->next;

		while (prev != NULL && current->n <prev->n)
		{
			current->prev = prev->prev;
			prev->next = current->next;
			current->next = prev;
			if (current->next != NULL)
				prev->prev->next = current;
			if (current->next != NULL)
				current->next->prev = prev;
			prev->prev = current;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
		}

		current = next;
	}
}
