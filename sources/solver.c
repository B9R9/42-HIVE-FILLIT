/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:28:59 by briffard          #+#    #+#             */
/*   Updated: 2022/02/01 19:36:07 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				solver(tetri_list li, char **map)
{
	int mapsize;
	if (!li)
	{
		printmap(map);
		return (0);
	}
	mapsize = ft_strlen(map[0]);
	if (check_limitsmap(li->coordonnee, mapsize))
	{
		printf("TESTi(3)\n");
		clearmap(map);
		solver(li, newmap(mapsize + 1));
	}
	else
	{
		printf("TEST\n");
		if  (block_checker(li->coordonnee, map))
		{
			li->coordonnee = move_coordonnee(li->coordonnee, mapsize);
			solver(li, map);
		}
		else
		{
			map = printcoordonnee(li->coordonnee,map);
			li = li->next;
			printmap(map);
			solver(li, map);
		}
	}
	return(0);
}