#include "regex.h"

/**
 * regex_match - checks whether a pattern matches a string
 *
 * @str: the string to scan
 * @pattern: the regular expression
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */

int regex_match(char const *str, char const *pattern)
{
	if (!*pattern)
	{
		if (!*str)
		{
			return (1);
		}
		return (0);
	};

	int first_match = *str && (*pattern == '.' || *pattern == *str);

	if (*(pattern + 1) == '*')
		return (regex_match(str, pattern + 2) ||
		(first_match && regex_match(str + 1, pattern)));
	else
		return (first_match && regex_match(str + 1, pattern + 1));
}
