#include "sort.h"

/**
 * swap_node - Swaps a node with its previous one in a doubly linked list.
 * @head: Head of the doubly-linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	listint_t *prev1 = (*node1)->prev;
	listint_t *next2 = node2->next;

	(*node1)->next = next2;
	if (next2 != NULL)
		next2->prev = *node1;

	node2->prev = prev1;
	node2->next = *node1;

	if (prev1 != NULL)
		prev1->next = node2;
	else
		*head = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
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
