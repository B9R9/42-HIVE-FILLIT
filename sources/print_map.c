/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:13:04 by briffard          #+#    #+#             */
/*   Updated: 2022/02/01 16:09:20 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*CHECK IF THERE IS BLOCK AT THE COORDONNEE*/
t_bool	check_block(int **tab, char **map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map[tab[i][0]][tab[i][1]] == BLOCK || map[tab[i][0]][tab[i][1]] == '\0')
			return false;
		i++;
	}
	return (true);
}
/*===========================================================================*/
/*CHECK IF A VALUE IS < ARR SIZE*/
t_bool		checksize(int **tab, int size)
{
	int	line;

	line = 0;
	while (line < 4)
	{
		if (tab[line][1] == size)
			return(false);
		line++;
	}

	return (true);
}
/*===========================================================================*/
/*MOVE COORDONNEE */
int		**move_coordonnee(int **tab, int arrsize)
{
	int	line;
	int	count;

	count = 0;
	line = 0 ;
	while (line < 4)
	{
		tab[line][1] += 1;
		line++;
		count++;
	}
	line = 0;
	if (checksize(tab, arrsize) == 0)
	{
		while (line < 4)
		{
			tab[line][0] += 1;
			tab[line][1] -= (arrsize - 1);
			line++;
		}
	}
	return (tab);
}

/*===========================================================================*/
/*CHECK IF WE ARE STILL INSIDE THE MAP*/
t_bool		check_arr_limits(int **tab, int size)
{
	int	line;

	line = 0;
	while (line < 4)
	{
		if (tab[line][1] == size)
			if (tab[line + 1][0] == (size - 1) && tab[line + 1][1] == size)
				return (false);
		line++;
	}
	return(true);
}

/*===========================================================================*/
/*PRINT MAP*/
void	displaymap(char **map, int	arrsize)
{
	int i;

	i = 0;
	while (i < arrsize)
		printf("%s%s%s\n",GREEN, map[i++], NORMAL);
}

/*===========================================================================*/
/*PRINT A MAP WITH 1 TETRI BASE COORDONNEE IN LIST*/
int		printmap(List_arr li, char **map)
{
	int				i;
	int				j;
	int				k;
	int				arrsize;
	size_t			count;

	printf("\nBEGINING PRINT MAP  ===================================\n");
	arrsize = ft_strlen(map[0]);
	printf("%sValeur de arrsize = %d%s\n",YELLOW, arrsize, NORMAL);
	printf("=======================================================\n");
	printf("%sMAP : \n", BLUE);
	count = 0;
	while (count < ft_strlen(map[0]))
		printf("%s\n", map[count++]);
	printf("%s=======================================================\n", NORMAL);
	printf("LES COORDONNEES:\n");
	if (li)
		{
			i = 0;
			while (i < 4)
			{
				printf("LINE: %d COLUMN: %d\n", li->coordonnee[i][0], li->coordonnee[i][1]);
				i++;
			}
		}
	printf("=======================================================\n");
	if(!li)
	{
		i = 0;
	printf("=======================================================\n");
	printf("SOLUTION\n");
	while (i < arrsize)
			printf("%s%s%s\n",CYAN, map[i++], NORMAL);
		return(0);
	}
	printf("=======================================================\n");
	printf("Return of check_arr_limits = %d\n", check_arr_limits(li->coordonnee, arrsize));
	printf("=======================================================\n");
	if (check_arr_limits(li->coordonnee, arrsize) == 0)
	{
		i = 0;
		while (i < arrsize)
		{
			ft_memdel((void **)&map[i]);
			i++;
		}
		printmap(li, newmap(arrsize + 1));
	}
	if (check_block(li->coordonnee, map) == 0)
		{
			li->coordonnee = move_coordonnee(li->coordonnee, arrsize);
			printmap(li, map);
		}
	k = 0;
	i = 0;
	while (i < arrsize)
	{
		j = 0;
		while (j < arrsize)
		{
			if (li->coordonnee[k][0] == i && li->coordonnee[k][1] == j && k < 4)
			{
				map[i][j] = BLOCK;
				k++;
			}
			//else
			//	map[i][j] = EMPTY;
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	li = li->next;
	printmap(li,map);
	return(0);
}

/*===========================================================================*/
