/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.version2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:55:10 by briffard          #+#    #+#             */
/*   Updated: 2022/02/03 11:23:43 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static tetri_list	giveletter_to_list(tetri_list li);
//static char			**replace_empty(char **map, int **position);
/*
static char			**replace_empty(char **map, int **position)
{
	map = printcoordonnee(position, map, EMPTY);
	return (map);
}
*/
static tetri_list	giveletter_to_list(tetri_list li)
{
	char letter;

	letter = 'A';
	while(li != NULL)
	{
		li->letter = letter;
		letter++;
		li = li->next;
	}
	return (li);
}
void	printcoord(int **tab, int **coord)
{
	int i = 0;
	printf("     FROM LIST        ---   FROM POSITION\n");
	while (i < 4)
	{
		printf("Line: %d || column: %d  --- line: %d || column:  %d\n",tab[i][0], tab[i][1], coord[i][0], coord[i][1]);
		i++;
	}
	ft_putchar('\n');
}

int		solver(tetri_list li, char **map, int **position)
{
	int	mapsize;
	int	i;
	int	j;

	mapsize = ft_strlen(map[0]);
	if (!li->letter)
	{
		giveletter_to_list(li);
		temp = li;
	}
	
	if (position == (mapsize * mapsize) && li == NULL)
	{
		printmap;
		return (1);
	}
	if (position == (mapsize * mapsize) && li != NULL)
	{
		cleanmap(map);
		map = newmap(,apsize + 1);
		solver(li, map, 0);
	}
	printmap(map);
	i = position / mapsize;
	j = position % mapsize;
	if (map[i][j] == BLOCK)
		return(solver(li,position + 1));
	while (li != NULL)
	{
		if (condition to print pieces on map are good)
		{
			printcoordonnee(--------,map, li->letter);
			li = li->next;
			if (solver(li, map, position + 1, ))
				return (1);
		}
	}
	replace_empty(map. ---------- );
	return (0);













































	printf("\nPIECES = %c\n", li->letter);
	printcoord(li->coordonnee, position);
	printf("Size of map: %d\n", mapsize);
	printmap(map);
	
	solver(li, map, move_coordonnee(temp->coordonnee, mapsize));
	/*while (temp != NULL)
	{
		if (!block_checker(position, map) && !check_limitsmap(position, mapsize))
		{
			map = printcoordonnee (position, map, temp->letter);
			printmap(map);
			temp = temp->next;
			if (!solver(li, map, temp->coordonnee))
				{
					if (solver(li, map,move_coordonnee(position, mapsize)))
					{
						printf("ICI\n");
					}
				}	
		}
		solver(li, map, move_coordonnee(position, mapsize));
		//li = li->next;
		//if (solver(li, map, li->coordonnee))
		//	return (true);
		//li = li->next;
		//map = replace_empty(map, position);
	}*/
	/*printf("test(2)\n");
	temp = temp->next;
	solver(li, map, temp->coordonnee);
	map = replace_empty(map, position);*/
	return (false);
}