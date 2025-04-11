#include "sort.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion algorithm
 * @list: list being sorted
*/
void insertion_sort_list(listint_t **list)
{
	/*Traverses list*/
	listint_t *current;
	/*Holds temp values*/
	listint_t *temp;

	current = *list;
	current = current->next;
	if (list == NULL || (*list)->next == NULL)
		return;
	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current;

			/*Link next and previous nodes together*/
			if (current->next != NULL)
			{
				current->next->prev = temp->prev;
			}
			current->prev->next = temp->next;
			/*Move to previous node, insert temp node before it*/
			current = current->prev;
			temp->prev = current->prev;
			temp->next = current;
			if (current->prev != NULL)
			{
				current->prev->next = temp;
			}
			current->prev = temp;
			/*If node is new head of list*/
			if (temp->prev == NULL)
			{
				*list = temp;
			}
			print_list(*list);
			current = current->prev;
		}
		current = current->next;
	}
}
