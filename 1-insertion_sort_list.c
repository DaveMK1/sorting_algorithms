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
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort
 * @list: Pointer to the head of a doubly-linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter_node = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (iter_node)
	{
		while (iter_node->prev && iter_node->prev->n > iter_node->n)
		{
			iter_node = swap_node(iter_node, list);
			print_list(*list);
		}

		iter_node = iter_node->next;
	}
}
