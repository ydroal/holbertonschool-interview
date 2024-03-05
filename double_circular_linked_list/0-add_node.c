#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_end(List **list, char *str)
{
	List *new;
	List *last;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);

	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->prev = new;
		new->next = new;
		*list = new;
	} else
	{
	/*循環listなので、先頭ノードのprevが最後のノードを指す*/
		new->next = *list;
		last = (*list)->prev;
		(*list)->prev = new;
		new->prev = last;
		last->next = new;
	}
	return (new);
}

/**
 * add_node_begin - Add a new node to the beginning of
 * a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_begin(List **list, char *str)
{
	List *new;
	List *last;

	new = malloc(sizeof(List));

	if (new == NULL)
		return (NULL);

	new->str = strdup(str);

	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->prev = new;
		new->next = new;
		*list = new;
	} else
	{
		last = (*list)->prev;
		new->next = *list;
		new->prev = last;
		last->next = new;
		(*list)->prev = new;
		(*list) = new;
	}
	return (new);
}


