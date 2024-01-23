#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm
 * @array: Array
 * @size: array size
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		size_t min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (i != min_index)
		{
			swap(array + i, array + min_index);
			print_array(array, size);
		}
	}
}

/**
 * swap - Swap two integers
 * @i: First integer to swap
 * @j: Second integer to swap
 */
void swap(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}
