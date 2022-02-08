/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.version3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:23:53 by briffard          #+#    #+#             */
/*   Updated: 2022/02/04 11:39:33 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	t_dlist	giveletter_to(t_dlist li);
static	char	**replace_block(char **map, int **position);

void	printcoord(int **tab, int **temp)
{
	int	i = 0;
	printf("\t\tFROM coordo\t\t----\t\tFROM temp\n");
	while (i < 4)
	{
		printf("Line:%3d\t||\tColumn:%3d\t---\tLine:%3d\t||\tColumn:%3d\n", tab[i][0], tab[i][1], temp[i][0], temp[i][1]);
	i++;
	}
}

static	char	**replace_block(char **map, int **position)
{
	map = printcoordonnee(position, map, EMPTY);
	return(map);
}

static t_dlist	giveletter_to(t_dlist li)
{
	char	letter;
	t_tetri	*temp;

	temp = li->begin;

	letter = 'A';
	while (temp != NULL)
	{
		temp->letter = letter;
		letter++;
		temp = temp->next;
	}
	return (li);
}

int	solver(t_dlist li, char **map)
{
	int				mapsize;
	t_tetri			*temp;

	temp = li->begin;
	mapsize = ft_strlen(map[0]);
	if(!temp->letter)
		giveletter_to(li);

/*
	printf("SOLVER:\tValeur de mapsize: %d\n", mapsize);
	printf("%s===========================================%s\n", CYAN, NORMAL);
	printf("%sDISPLAY COORDONNEE:\n",YELLOW);
	printcoord(temp->coordonnee, temp->coordonnee);
	printf("%s===========================================%s\n", CYAN, NORMAL);
*/
	while (temp != NULL)
	{
		/*
		printf("temp->letter: %c\n", temp->letter);
		printf("%s===========================================%s\n", CYAN, NORMAL);
		printf("%sDISPLAY COORDONNEE:\n",YELLOW);
		printcoord(temp->coordonnee, temp->temp);
		printf("%s===========================================%s\n", CYAN, NORMAL);*/
		if (check_limitsmap(temp->temp, mapsize))
		{
			if(temp->letter == 'A')
			{
				clearmap(map);
				map = newmap(mapsize + 1);
				temp->temp = cp_to(temp->temp,temp->coordonnee);
				move_coordonnee(temp->temp,mapsize);
				}
			else if(temp->letter != 'A')
			{
				temp->temp = cp_to(temp->temp,temp->coordonnee);
				temp = temp->back;
				replace_block(map, temp->temp);
				move_coordonnee(temp->temp,mapsize);
			}
		}
		else if(!block_checker(temp->temp, map))
		{
			printcoordonnee(temp->temp, map, temp->letter);
			//printmap(map);
			temp = temp->next;
		}
		else
		{
			move_coordonnee(temp->temp,mapsize);
		}
	}
	return (true);
}