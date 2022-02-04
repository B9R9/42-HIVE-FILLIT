/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:08:43 by briffard          #+#    #+#             */
/*   Updated: 2022/02/04 11:59:42 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fillit.h"

static t_bool		checksize(int **tab, int size);

/*check if a value is < map size*/
static t_bool		checksize(int **tab, int size)
{
	int	line;

	line = 0;
	while (line < 4)
	{
		if (tab[line][1] == size)
			return (true);
		line++;
	}
	return (false);
}

/*calculate the smallest map possible */
int		smallestmap(t_dlist li)
{
	int	totalblock;
	int result;
	int i = 0;	
	totalblock = li->length;
	result = totalblock * 4;
	while (i < result)
	{
		if (result <= (i * i))
			return (i);
		i++;
	}
	return (0);
}

/*check piece are inside the map*/
t_bool		check_limitsmap(int **tab, int size)
{
	int	line;

	line = 0;
	while (line < 4)
	{
		if(tab[line][0] == size)
				return (true);
		line++;
	}
	return (false);
}

/*check if a block is at the coordonnate*/
t_bool		block_checker(int **ar, char **map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map[ar[i][0]][ar[i][1]] != EMPTY || map[ar[i][0]][ar[i][1]] == '\0')
			return (true);
		i++;
	}
	return  (false);
}

/*Move coordonnate*/
int		**move_coordonnee(int **tab, int mapsize)
{
	int	line;
//	int i = 0;
//	while ( i < 4)
//	{
//		printf("coordonnee: Line: %d column: %d\n",tab[i][0], tab[i][1]);
//		i++;
//	}
	line = 0;
	while (line < 4)
	{
		tab[line][1] += 1;
		line++;
	}
	line = 0;
	if (checksize(tab, mapsize))
	{
		while (line < 4)
		{
			tab[line][0] += 1;
			tab[line][1] -= mapsize;// a Verifier
			line++;
		}
	}
	return (tab);
}