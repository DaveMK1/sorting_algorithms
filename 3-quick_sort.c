#include "sort.h"

/**
 * swap - Swap integers
 * @k: First integer to swap
 * @l: Second integer to swap
 */
void swap(int *k, int *l)
{
	int tmp;

	tmp = *k;
	*k = *l;
	*l = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: array
 * @low: starting index
 * @high: ending index
 * @size: array size
 *
 * Return: The position of the final element sorted
 */
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot;
	ssize_t i;
	ssize_t j;

	i = low - 1;

	pivot = array[high];

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort_imp - Implement the quicksort algorithm recursively
 * @array: array
 * @low: starting index
 * @high: ending index
 * @size: array size
 */
void quicksort_imp(int *array, ssize_t low, ssize_t high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, low, high, size);

		quicksort_imp(array, low, partition - 1, size);
		quicksort_imp(array, partition + 1, high, size);
	}
}

/**
 * quick_sort - Sort an array of integers using the quicksort algorithm
 * @array: array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_imp(array, 0, size - 1, size);
}
