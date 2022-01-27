/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:56:36 by briffard          #+#    #+#             */
/*   Updated: 2022/01/27 17:17:47 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*le nombre de tetriminos dans le fichier doit etre compris entre 1 et 26*/
int		sidechecker(char *tetriminos,int index)
{
	int communside;

	communside = 0;

	if (tetriminos[index] == tetriminos[index - 1])
		communside += 1;
	if (tetriminos[index] == tetriminos[index - 5])
		communside += 1;
	if (tetriminos[index] == tetriminos[index + 5])
		communside += 1;
	if (tetriminos[index] == tetriminos[index + 1])
		communside += 1;
	return (communside);
	/*NEED PROTECTION WHEN THE RESULT > 18 and result < 0*/
}


t_bool	is_valid(char *tetriminos)
{
	int	index;
	int	counter;
	int	countside;
	int	charcount;

	index = 0;
	counter = 0;
	countside = 0;
	charcount = 0;
	while (tetriminos[index] != '\0')
	{
		if (tetriminos[index] != EMPTY && tetriminos[index] != BLOCK && tetriminos[index] != NEWLINE)
			return (false);
		if ((index % 5) == 8)
			if (tetriminos[index] != NEWLINE)
				return (false);
		if (ft_isprint(tetriminos[index]))
			charcount += 1;
		if (tetriminos[index] == BLOCK)
		{
			counter += 1;
			countside += sidechecker(tetriminos, index);
		}
		index++;
	}
	if (countside != 6 && countside != 8)
		return (false);
	if (charcount != 16)
		return (false);
	if(tetriminos[index] != '\0' && tetriminos[index] != '\n')
		return(false);
	if (counter > 4 || counter < 4)
		return (false);
	return (true);
}