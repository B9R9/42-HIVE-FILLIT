/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:16:13 by briffard          #+#    #+#             */
/*   Updated: 2022/02/02 11:59:18 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*Print all the list*/
void	print_all_list(tetri_list li)
{
	int	i;

	if (!li)
		ft_putstr("Nothing to print. List is empty!\n");
	while (li != NULL)
	{
		i = 0;
		while (i < 4 )
		{
			printf("Line: %d Column: %d\n", li->coordonnee[i][0], li->coordonnee[i][1]);
			i++;
		}
		printf("Letter: %c\n", li->letter);
		ft_putchar('\n');
		li = li->next;
	}
	ft_putchar('\n');
}

/*print map*/
void	printmap(char **map)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(map[0]))
		printf("%s\n", map[i++]);
	ft_putchar('\n');
}

/*print coordonnee on the map*/
char	**printcoordonnee(int **tab, char **map, char c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map[tab[i][0]][tab[i][1]] = c;
		i++;
	}
	return (map);
}