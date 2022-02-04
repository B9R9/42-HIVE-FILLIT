/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:16:13 by briffard          #+#    #+#             */
/*   Updated: 2022/02/04 10:19:55 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*Print all the list*/
void	print_all_list(t_dlist li)
{
	int	i;
	t_tetri	*temp;

	temp = li->begin;
	if (!li)
		ft_putstr("Nothing to print. List is empty!\n");
	while (temp != NULL)
	{
		i = 0;
		while (i < 4 )
		{
			printf("Line: %d Column: %d\n", temp->coordonnee[i][0], temp->coordonnee[i][1]);
			i++;
		}
		printf("Letter: %c\n", temp->letter);
		ft_putchar('\n');
		temp = temp->next;
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