/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:57:42 by briffard          #+#    #+#             */
/*   Updated: 2022/01/27 16:59:56 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fillit.h"

/*newlist creation*/
List_arr	newlist_arr(void)
{
	return (NULL);
}

List_bits	newlist_bit(void)
{
	return (NULL);
}

/*=============================================================================*/
/*
REMOVE ALL DOTS UNECESSARY

char	**ft_strtrim_dots(char **arr)
{
	if (!ft_strchr(arr[i], EMPTY))
		while(arr[i])
		{
			ft_bzero(arr[i], ft_strlen(arr[i]));
			arr[i] = ft_strdup
		}
}
*/

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
/*PRINT LIST*/
/*void	print_list(List li)
{
	if (!li)
	{
		ft_putstr("Nothing to print, the list is empty.\n");
		return;
	}
	while (li != NULL)
	{
		ft_putstr(li->tetriminos);
		li = li->next;
	}
	ft_putchar('\n');
}
*/

/*=============================================================================*/
/*PRINT BITS*/
void	printbit(uint64_t c)
{
	uint64_t	bit = 1 << 15;
	int 		i = 0;
	while (bit  != 0)
	{
		if (c & bit)
			ft_putchar('1');
		else
			ft_putchar('0');
		bit >>= 1;
		i++;
		if (i % 4 == 0)
			ft_putchar(' ');
	}
	ft_putchar('\n');
	ft_putchar('\n');
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

/*=============================================================================*/
/*TURN STR EN BIT*/
uint64_t	turn_to_bit(char *str)
{
	int	i;
	int bit = 0;
	int add = 1 << 15;

	i = 0;
	while (str[i])
	{
		if (str[i] == BLOCK)
			bit += add;
		if (str[i] == 0)
			add = 1;
		if (str[i] == BLOCK || str[i] == EMPTY)
			add /= 2;
		i++;
	}
	return (bit);
}

/*=============================================================================*/
/*Created a new element and put at the end of the list*/
List_bits	push_back_list_bit(List_bits li, char *shape)
{
	t_bit_tetri	*element;
	t_bit_tetri	*temp;
	

	element = malloc(sizeof(*element));
	if (!element)
	{
		ft_putstr_fd("Error: problem with dynamic allocation memory\n", 2);
		exit(EXIT_FAILURE);
	}
	element->bit = turn_to_bit(shape);
	element->next = NULL;
	if (!li)
		return (element);
	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return (li);
}

 /*==========================================================================*/

int	main(int argc, char **argv)
{
	List_arr			tetriminos;
	List_bits			bit_tetriminos;
	char			pieces[MAX_SIZE + 1];
	int				fd;
	int		 		ret;
	int				i = 0;
//	int 			j = 0;
//	int 			k = 0;

	tetriminos = newlist_arr();
	bit_tetriminos = newlist_bit();

	if (argc != 2)
		ft_putstr("Error// print usage message\n");
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_putstr("Error: open file.\n");
	while((ret = read(fd, pieces, MAX_SIZE)))//NOT AT THE NORM
		{
			pieces[ret] = '\0';
			if (is_valid(pieces))
			{
				tetriminos = push_back_list(tetriminos, pieces);
				bit_tetriminos = push_back_list_bit(bit_tetriminos, pieces);
			}
			else
			{
				ft_putstr_fd("Error: Not a valid tetriminos.\nEnd of the programm\n", 2);
				clear_list(tetriminos);
				break;
			}
		}
	close(fd);
//	print_list(tetriminos);
	while (bit_tetriminos != NULL)
	{
		i = 0;
		while (i < 4)
		{
			printf("%s\n", tetriminos->tetriminos[i]);
			i++;
		}
		i = 0;
		printf("Coordonne of #: \n");
		while (i < 4)
		{
			printf("line: %d\tcolumn: %d\n", tetriminos->coordonnee[i][0], tetriminos->coordonnee[i][1]);
			i++;
		}
		printf("Value of tetriminos in bit: \n");
		printbit(bit_tetriminos->bit);
		bit_tetriminos = bit_tetriminos->next;
		tetriminos = tetriminos->next;
	}
/*	while(tetriminos != NULL)
	{
		i = 0;
		printf("AVANT: Coordonne of #: \n");
		while (i < 4)
			{
				printf("line: %d\tcolumn: %d\n", tetriminos->coordonnee[i][0], tetriminos->coordonnee[i][1]);
				i++;
			}
		i = 0;
		while (i < 4)
		{
			printf("%s\n", tetriminos->tetriminos[i]);
			i++;
		}*/
//		tetriminos->coordonnee = align(tetriminos->coordonnee, check_coordonnee(tetriminos->coordonnee));
/*		printf("%s============================================================%s\n",YELLOW, NORMAL);
		i = 0;
		k = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (k < 4)
				{
					if (tetriminos->coordonnee[k][0] == i && tetriminos->coordonnee[k][1] == j)
					{
						ft_putchar('#');
					k++;
					}
					else
						ft_putchar('.');
				}
				else
					ft_putchar('.');
				j++;
			}
			ft_putchar('\n');
			i++;
		}
		printf("APRES: Coordonne of #: \n");
		i = 0;
		while (i < 4)
			{
				printf("line: %d\tcolumn: %d\n", tetriminos->coordonnee[i][0], tetriminos->coordonnee[i][1]);
				i++;
			}
		printf("%s============================================================%s\n",YELLOW, NORMAL);
		tetriminos = tetriminos->next;
	}*/

}