#include "sort.h"

/**
 * bubble_sort - sort array elements from minimum to maximum value
 * @array: The array of integers to sort
 * @size: The array size
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;

	while (!swapped)
	{
		swapped = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_int(array + i, array + i + 1);
				print_array(array, size);
				swapped = false;
			}
		}
		len--;
	}
}

/**
 * swap_int - Swap two integers
 * @a: first integer
 * @b: second integer
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
