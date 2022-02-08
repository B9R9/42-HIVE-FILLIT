/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:23:27 by briffard          #+#    #+#             */
/*   Updated: 2022/02/04 11:09:53 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	**save_coordonnee(char *str, int **tab);

/*copye coordonnee in temp*/
int		**cp_to(int	**tab, int **coord)
{
	int		i;

	i = 0;
	while(i <4)
	{
		tab[i][0] = coord[i][0];
		tab[i][1] = coord[i][1];
		i++;
	}	
	return(tab);
}
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
t_dlist	newlist(void)
{
	return (NULL);
}

/*Create a new element with coordonne and put it in a linked list*/
t_dlist	push_back_list(t_dlist li, char *tetriminos)
{
	t_tetri		*element;
	int i = 0;

	element = malloc(sizeof(*element));
	//element = allocate_memory(*element);
	element->coordonnee = (int **) malloc((sizeof(int *) *4) + 1);
	element->temp = (int **) malloc((sizeof(int *) *4) + 1);
	while(i < 5)
	{
		element->coordonnee[i] = (int *) malloc((sizeof(int) * 4) + 1);
		element->temp[i] = (int *) malloc((sizeof(int) * 4) + 1);
		if(!element->coordonnee[i] || !element->temp[i])
			exit(EXIT_FAILURE);
		i++;
	}
	if (check_return(element))
			return(NULL);
	element->coordonnee = save_coordonnee(tetriminos, element->coordonnee);
	element->coordonnee = align(element->coordonnee,check_coordonnee(element->coordonnee));
	element->temp = cp_to(element->temp, element->coordonnee);
	element->next = NULL;
	if (is_empty_dlist(li))
	{
		li = malloc(sizeof(*li));
		if (check_return_dlist(li))
			exit(EXIT_FAILURE);
		li->length = 0;
		li->begin = element;
		li->end = element;
	}
	else
	{
		li->end->next = element;
		element->back = li->end;
		li->end = element;
	}
	li->length++;
	return(li);
}

/*remove an element from the back of the list*/
t_dlist	pop_back_list(t_dlist li)
{
	t_tetri		*temp;

	if(is_empty_dlist(li))
		return(NULL);
	if(li->begin == li->end)
	{
		ft_memdel((void**)&li);
		return(li);
	}
	temp = li->end;
	li->end = li->end->back;
	li->end->next = NULL;
	temp->next = NULL;
	temp->back = NULL;
	ft_memdel((void**)&temp);
	li->length--;
	return(li);
}

/*remove an element from the beginning of the list*/
t_dlist	pop_front_list(t_dlist li)
{
	t_tetri		*temp;

	if (is_empty_dlist(li))
		return (NULL);
	if(li->begin == li->end)
	{
		ft_memdel((void **)&li);
		return(li);
	}
	temp = li->begin;
	li->begin = li->begin->next;
	li->begin->back = NULL;
	temp->next = NULL;
	temp->back = NULL;
	ft_memdel((void**)&temp);
	return (li);
}

/*clear all the list*/
t_dlist	clearList(t_dlist li)
{
	while(!is_empty_dlist(li))
		li = pop_back_list(li);
	return(li);
}

/*check if tje list ios empty or not*/
t_bool	is_empty_dlist(t_dlist li)
{
	if (li == NULL)
		return (true);
	return (false);
}
