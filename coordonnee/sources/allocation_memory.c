/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:32:13 by briffard          #+#    #+#             */
/*   Updated: 2022/02/04 12:00:03 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**fillmap(char **str, char c, int size);


/*Fill map with empty*/
static char	**fillmap(char **str, char c, int size)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			str[i][j] = c;
			j++;
		}
		str[i][j] = '\0';
		i++;
	}
	return (str);
}

/*Allocate memory to coordonnee*/
t_tetri	allocate_memory(t_tetri li)
{
	/*int	i;

	i = 0;
	li = ft_memalloc(sizeof(*li));
	if (!li)
		return (NULL);
	li->coordonnee = (int **)ft_memalloc((sizeof(int *) * 4) + 1);
	li->temp = (int **)ft_memalloc((sizeof(int *) * 4) + 1);
	if (!li->coordonnee || !li->temp)
		exit(EXIT_FAILURE);
	while (i < 5)
	{
		li->coordonnee[i] = (int *)ft_memalloc((sizeof(int *) * 4) + 1);
		li->temp[i] = (int *)ft_memalloc((sizeof(int *) * 4) + 1);
		if (!li->coordonnee[i] || !li->temp[i])
		{
			ft_putendl_fd ("Error: allocation memory(2)", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}*/
	return (li);
}

/*Create a new mapsize of i*/
char	**newmap(int size)
{
	int		i;
	char	**map;
	i = 0;
	map = (char **)ft_memalloc((sizeof(char *) * size));
	if (!map)
	{
		ft_putendl_fd("Error: allocation memory map", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (i < size)
		{
			map[i] = (char *)ft_memalloc((sizeof(char) * size));
			if (!map[i])
			{
				ft_putendl_fd("Error: allocation memory map", 2);
				exit(EXIT_FAILURE);
				
			}
			i++;
		}
	}
	map = fillmap(map, '.', size);
	return (map);
}

/*destroy map ** */
void	clearmap(char **map)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(map[0]))
	{
		ft_memdel((void **)&map[i]);
		i++;
	}
}