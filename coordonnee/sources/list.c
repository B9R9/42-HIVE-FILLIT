/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:23:27 by briffard          #+#    #+#             */
/*   Updated: 2022/02/03 11:19:16 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	**save_coordonnee(char *str, int **tab);

/*save block coordonnee to a int ** */
static int	**save_coordonnee(char *str, int **tab)
{
	int	i;
	int count;
	int	line;
	int	column;

	column = 0;
	line = 0;
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			line++;
			column = 0;
			i++;
		}
		if (str[i] == BLOCK)
		{	
			tab[count][0] = line;
			tab[count][1] = column;
			count++;
		}
		i++;
		column++;
	}
	return (tab);
}

/*Create an new list*/
tetri_list	newlist(void)
{
	return (NULL);
}

/*Create a new element with coordonne and put it in a linked list*/
tetri_list	push_back_list(tetri_list li, char *tetriminos)
{
	t_tetri		*element;
	t_tetri		*temp;

	element = NULL;
	element = allocate_memory(element);
	if (check_return(element))
			return(NULL);
	element->coordonnee = save_coordonnee(tetriminos, element->coordonnee);
	element->coordonnee = align(element->coordonnee,check_coordonnee(element->coordonnee));
	element->temp = element->coordonnee;
	element->next = NULL;
	if (!li)
		return (element);
	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return(li);
}

/*remove an element from the beginning of the list*/
tetri_list	pop_front_list(tetri_list li)
{
	t_tetri		*element;

	element = (t_tetri *)ft_memalloc(sizeof(*element));
	if (!element)
	{
		ft_putendl_fd("Error: allocation memory", 2);
		return (NULL);
	}
	if (!li)
		return (li);
	element = li->next;
	ft_memdel((void **)&li);
	return (element);
}

/*clear all the list*/
tetri_list	clearList(tetri_list li)
{
	if (!li)
		return  (li);
	while (li->next != NULL)
		li = pop_front_list(li);
	return(li);
}
