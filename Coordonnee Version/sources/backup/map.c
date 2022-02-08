/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 09:57:14 by briffard          #+#    #+#             */
/*   Updated: 2022/01/28 16:41:20 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fillit.h"

/*FILL MAP WITH A CHAR*/
char	**fillmap(char **str, char c, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while(j < size)
			str[i][j++] = c;
		str[i][j] = '\0';
		i++;
	}
	;
	return (str);
}

/*CREATE OF MAP SIZE OF I*/
char	**newmap(int size)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)ft_memalloc((sizeof(char *) * size) + 1);
	if (!map)
	{
		ft_putstr_fd("Error: Dynamic alocation memory of map\n", 2);
		return (NULL);
	}
	else
	{
		while (i < size)
		{
			map[i] = (char *)ft_memalloc((sizeof(char) * size) + 1);
			if (!map[i])
				{
					ft_putstr_fd("Error: Dynamic alocation memory of map\n", 2);
					return(NULL);
				}
			i++;
		}
	}
	map = fillmap(map,'.', size);
	return (map);
}