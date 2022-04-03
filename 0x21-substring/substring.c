#include "substring.h"

/**
 * find_substring - finds the possible substrings containing a list of words
 * @s: string
 * @words: array of words
 * @nb_words: number of words
 * @n: address which store the number of elements in the returned array.
 * Return: allocated array,
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{

	int current_idx, count, str_len, word_len, check_strs, i, j, k;
	int *match, *idx_array;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);
	str_len = strlen(s);
	word_len = strlen(words[0]);
	idx_array = malloc(str_len * sizeof(int));
	if (!idx_array)
		return (NULL);
	match = malloc(nb_words * sizeof(int));
	if (!match)
		return (NULL);
	for (i = count = 0; i <= str_len - nb_words * word_len; i++)
	{
		memset(match, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				current_idx = i + j * word_len;
				check_strs = strncmp(s + current_idx, *(words + k), word_len);
				if (!*(match + k) && !check_strs)
				{
					*(match + k) = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			*(idx_array + count) = i, count += 1;
	}
	free(match);
	*n = count;
	return (idx_array);
}
