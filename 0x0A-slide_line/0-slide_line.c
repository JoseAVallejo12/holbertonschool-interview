#include "slide_line.h"
/**
 * slide_line_left - slides and merge an integers array to left.
 * @line: pointer to an integers array.
 * @size: num of array elements.
 * Return: 1 if success, 0 if fails.
 */
int slide_line_left(int *line, size_t size)
{
	int n1 = 0, n2 = 0;
	size_t count = 0, i;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0 && n1 == 0)
			n1 = line[i];
		else if (line[i] != 0 && n1 != 0)
			n2 = line[i];
		if (n1 != 0 && n2 != 0)
		{
			if (n1 == n2)
			{
				line[count++] = n1 + n2;
				n1 = 0;
				n2 = 0;
			}
			else
			{
				line[count++] = n1;
				n1 = n2;
				n2 = 0;
				if (i == size - 1)
					line[count++] = n1;
			}
		}
		else if (n1 != n2 && i == size - 1)
			line[count++] = n1;
	}
	for (i = count; i < size; i++)
		line[i] = 0;

	return (1);
}
/**
 * slide_line_right - slides and merge an integers array to right.
 * @line: pointer to an integers array.
 * @size: num of array elements.
 * Return: 1 if success, 0 if fails.
 */
int slide_line_right(int *line, size_t size)
{
	int n1 = 0, n2 = 0;
	size_t count = size - 1, i;

	for (i = size - 1; i < size; i--)
	{
		if (line[i] != 0 && n1 == 0)
			n1 = line[i];
		else if (line[i] != 0 && n1 != 0)
			n2 = line[i];
		if (n1 != 0 && n2 != 0)
		{
			if (n1 == n2)
			{
				line[count--] = n1 + n2;
				n1 = 0;
				n2 = 0;
			}
			else
			{
				line[count--] = n1;
				n1 = n2;
				n2 = 0;
				if (i == 0)
					line[count--] = n1;
			}
		}
		else if (n1 != n2 && i == 0)
			line[count--] = n1;
	}
	for (i = 0; i < count + 1; i++)
		line[i] = 0;

	return (1);
}
/**
 * slide_line - slides and merge an integers array.
 * @line: pointer to an integers array.
 * @size: num of array elements.
 * @direction: can be either SLIDE_LEFT or SLIDE_RIGHT.
 * Return: 1 if success, 0 if fails.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_LEFT)
		return (slide_line_left(line, size));
	return (slide_line_right(line, size));
}
