#include "holberton.h"

/**
 * skip_wildcards - Skip over wildcard characters ('*') in a s2 string.
 * @s2: Pointer to the string may containing consecutive '*' characters.
 *
 * Return: A pointer to the the last consecutive ('*') character in s2,
 *         or to the '*' character if there are no consecutive '*' characters.
 */

char *skip_wildcards(char *s2)
{
	if (*s2 == '*' && *(s2 + 1) == '*')
		return (skip_wildcards(s2 + 1));

	return (s2);
}

/**
 * wildcmp - Compares two strings and returns 1 if the strings can be
 * considered identical, otherwise return 0.
 * @s1: The first string to compare.
 * @s2: The second string to compare, may contain the special character *.
 *
 * Return: 1 if the strings can be considered identical, otherwise 0.
 */

int wildcmp(char *s1, char *s2)
{

	if (!s1 || !s2)
		return (0);

	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* 一文字ずつ再帰的にチェック */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
	{
		/* 文字列中にある連続する*をスキップ */
		/* 複数の*が連続していても1つの*として扱う*/
		s2 = skip_wildcards(s2);

		/* *が文字列末尾なら文字列は同一とみなす */
		if (*(s2 + 1) == '\0')
			return (1);

	/* *が1文字以上にマッチする場合と */
	/* 0文字にマッチする場合 */
	if (*s1 && (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1)))
		return (1);
	}

	return (0);
}
