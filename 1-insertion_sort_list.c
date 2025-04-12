#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * 			 in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;

		while (temp->prev && temp->n < temp->prev->n)
		{
			listint_t *prev = temp->prev;


			prev->next = temp->next;
			if (temp->next)
				temp->next->prev = prev;

			temp->prev = prev->prev;
			temp->next = prev;

			if (prev->prev)
				prev->prev->next = temp;
			else
				*list = temp;

			prev->prev = temp;

			print_list(*list);
		}

		current = current->next;
	}
}
