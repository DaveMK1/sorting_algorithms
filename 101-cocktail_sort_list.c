#include "sort.h"

/**
 * swap_node - Swaps a node with its previous one in a doubly linked list.
 * @node: Node to be swapped
 * @list: Linked list containing the node
 * Return: Pointer to the node that was moved
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *temp_node = node->prev, *iter_node = node;

	temp_node->next = iter_node->next;

	if (iter_node->next)
		iter_node->next->prev = temp_node;

	iter_node->next = temp_node;
	iter_node->prev = temp_node->prev;
	temp_node->prev = iter_node;

	if (iter_node->prev)
		iter_node->prev->next = iter_node;
	else
		*list = iter_node;

	return (iter_node);
}

/**
 * cocktail_sort_list - Cocktail sort implementation for doubly linked lists
 * @list: Pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;

	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				current = swap_node(current->next, list);
				swapped = 1;
				print_list(*list);
			}

			else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = 0;

		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				current = swap_node(current, list);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}

