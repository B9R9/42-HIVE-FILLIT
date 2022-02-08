/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:58:56 by briffard          #+#    #+#             */
/*   Updated: 2022/02/01 16:16:19 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	smalest_column(int **arr);

/*Check if the column of the block is closest to 0*/
t_bool	check_coordonnee(int **coordonnee)
{
	int column = coordonnee[0][1]; // Valeur = 1
	int ordonne = 0;
	int absicce = 0;

	while (ordonne < 4)
	{
		if (column > coordonnee[ordonne][absicce])
			return (false);
		absicce++;
		if (absicce == 2)
		{
			ordonne++;
			absicce = 0;
		}
	}
	return (true);
}

/*===========================================================================*/
/*LOOKING FOR THE SMALLEST Column*/
static int	smalest_column(int **arr)
{
	int	i;
	int	ret;

	ret = arr[0][1];
	i = 0;
	while (i < 4)
	{
		if (ret > arr[i][1])
			ret = arr[i][1];
		i++;
	}
	return (ret);
}
/*===========================================================================*/
/*Align all piece to the most upper left side of their on map*/

int	**align(int	**coordonnee, int result)
{
	int subtractline = coordonnee[0][0];
	int subtractcolumn = smalest_column(coordonnee);
	int i = 0;

	if (result)
	{
		while (i < 4)
		{
			coordonnee[i][0] = coordonnee[i][0] - subtractline;
			coordonnee[i][1] = coordonnee[i][1] - subtractcolumn;
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < 4)
		{
			coordonnee[i][0] = coordonnee[i][0] - subtractline;
			coordonnee[i][1] = coordonnee[i][1] - subtractcolumn;
			i++;
		}
	}
	return (coordonnee);
}
