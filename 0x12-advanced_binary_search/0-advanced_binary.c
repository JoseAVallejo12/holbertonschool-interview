#include "search_algos.h"
/**
 * advanced_binary - binary search
 * @array: array
 * @size: size of the array
 * @value: the value
 * Return:  index or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, mid, idx = 0;
	int aux;

	if (array == NULL)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
		i == size - 1 ? printf("%d\n", array[i]) : printf("%d, ", array[i]);

	if (size == 1 && array[0] != value)
		return (-1);
	mid = (size - 1) / 2;
	if (array[mid] == value)
	{
		if (array[mid - 1] < value)
			return (mid);
	}
	if (array[mid] < value)
	{
		idx += mid + 1, array += mid + 1;
		size % 2 != 0 ? mid-- : 0;
	}
	mid++;
	aux = advanced_binary(array, mid, value);
	if (aux != -1)
		return (aux + idx);
	return (-1);
}
