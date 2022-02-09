/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:56:36 by briffard          #+#    #+#             */
/*   Updated: 2022/02/09 10:01:09 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bool	check_char(char tetriminos, int index);
static int		sidecheck(char *tetriminos);
static int		sidechecker(char *tetriminos, int index);
static t_bool	checker_valid_piece(int countside, int charcount, int counter);

/*le nombre de tetriminos dans le fichier doit etre compris entre 1 et 26*/
/*count how many commun side a block have with another block*/
static int		sidechecker(char *tetriminos,int index)
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

static t_bool	check_char(char tetriminos, int index)
{
	if (tetriminos != EMPTY && tetriminos != BLOCK && tetriminos != NEWLINE)
		return (true);
	if ((index % 5) == 4)
		if (tetriminos != NEWLINE)
			return (true);
	return (false);
}

static t_bool	checker_valid_piece(int countside, int charcount, int counter)
{
	if (countside != 6 || countside != 8)
		return (false);
	if (charcount != 16)
		return (false);
	if (counter != 4)
		return (false);
	return(true);
}

static int		sidecheck(char *tetriminos)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (tetriminos[i] != '\0')
	{
		if (tetriminos[i] == BLOCK)
			count += sidechecker(tetriminos, i);
		i++;
	}
	return (count);
}

t_bool	is_valid(char *tetriminos)
{
	int	index;
	int	counter;
	int	charcount;

	index = 0;
	counter = 0;
	charcount = 0;
	while (tetriminos[index] != '\0')
	{
		if (check_char(tetriminos[index], index))
			return (false);
		if (ft_isprint(tetriminos[index]))
			charcount += 1;
		if (tetriminos[index] == BLOCK)
			counter += 1;
		index++;
	}
	if (checker_valid_piece(sidecheck(tetriminos), charcount, counter))
		return (false);
	if (tetriminos[index] != '\0' && tetriminos[index] != '\n')
		return(false);
	return (true);
}