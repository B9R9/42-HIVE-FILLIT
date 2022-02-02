/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2readfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:57:42 by briffard          #+#    #+#             */
/*   Updated: 2022/01/28 09:54:09 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fillit.h"

/*newlist creation*/
List_arr	newlist_arr(void)
{
	return (NULL);
}

/*=============================================================================*/
/*COPY SHAPE IN A DOUBLE ARR*/
char	**cpy_to_double_arr(char *str, char **arr)
{
	int		line;
	int		column;
	int i = 0;

	line = 0;
	column = 0;

	while (str[i] != '\0')
	{
		if (str[i] == NEWLINE)
		{
			arr[line][column] = '\0';
			line++;
			i++;
			column = 0;
		}
		arr[line][column] = str[i];
		i++;
		column++;
	}
	arr[line][0] = '\0';
//	printf("line = %3d\ncolumn = %3d\n", line, column);
	return (arr);
}

/*=============================================================================*/
/*SAVE coordonne of every block in ARR of INT (4 lines and 2 columns))*/

int		**save_coordonne(char	**str, int	**tab)
{
	int	index;
	int	line;
	int count;

	index = 0;
	line = 0;
	count = 0;
	while (str[line][index] != '\0')
	{
		while (str[line][index] != '\0')
		{
			if (str[line][index] == '#')
			{
				tab[count][0] = line;
				tab[count][1] = index;
				count++;
			}
			index++;
		}
		line++;
		index = 0 ;
	}
	return (tab);
}
/*=============================================================================*/
/*Created a new element and put at the end of the list*/
List_arr	push_back_list(List_arr li, char *shape)
{
	int				i;
	t_arr_tetri		*element;
	t_arr_tetri		*temp;
	

	i = 0;
	element = malloc(sizeof(*element));
	if (!element)
	{
		ft_putstr_fd("Error: problem with dynamic allocation memory\n", 2);
		exit(EXIT_FAILURE);
	}
	element->tetriminos = (char **)ft_memalloc((sizeof(char *) * 4) + 1);
	element->coordonnee = (int **)ft_memalloc((sizeof(int *) * 4) + 1);
	while (i < 5)
	{
		element->tetriminos[i] = (char *)ft_memalloc((sizeof(char) * 4) + 1);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		element->coordonnee[i] = (int *)ft_memalloc((sizeof(int) * 2) + 1);
		i++;
	}
	element->tetriminos = cpy_to_double_arr(shape, element->tetriminos);
	element->coordonnee = save_coordonne(element->tetriminos, element->coordonnee);
	element->coordonnee = align(element->coordonnee, check_coordonnee(element->coordonnee));
	element->next = NULL;
	if (!li)
		return (element);
	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return (li);
}

/*============================================================================*/
/*REMOVE AN ELEMENT FROM THE BEGINING OF THE LIST*/
List_arr	pop_front_list(List_arr li)
{
	t_arr_tetri		*element;
	
	element = malloc(sizeof(*element));
	if (!element)
	{
		ft_putstr_fd("Error: problem dynamic allocation memory\n", 2);
		exit(EXIT_FAILURE);
	}
	if (!li)
		return (li);
	element = li->next;
	free(li);
	li = NULL;
	return (element);
}

/*===========================================================================*/
/*CLEAR ALL THE LIST*/

List_arr	clear_list(List_arr li)
{
	if (!li)
		return (li);
	while (li->next != NULL)
		li = pop_front_list(li);
	return (li);
}

/*===========================================================================*/
/*PRINT LIST*/

void	print_list(List_arr li, char *str)
{
	int	i;

	i = 0;
	if  (!li)
		ft_putstr("Nothing to print. The list is empty.\n");
	while (li != NULL)
	{
		if (ft_strcmp(str, "tetri") == 0)
		{
			i = 0;
			while (i < 4)
				ft_putstr(li->tetriminos[i++]);
		}
		else if (ft_strcmp(str, "coordonnee") == 0)
		{
			i = 0;
			while (i < 4)
			{
				printf("line: %d\tcolumn: %d\n",li->coordonnee[i][0], li->coordonnee[i][1]);
				i++;
			}
			ft_putchar('\n');
		}
		li = li->next;
	}
	ft_putchar('\n');
}