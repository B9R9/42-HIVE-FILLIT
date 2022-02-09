/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:07:55 by briffard          #+#    #+#             */
/*   Updated: 2022/02/04 11:52:11 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*checking argc and argv[1] match with our criteria*/
t_bool	check_parameters(int number, char *str)
{
	if (number == 1)
	{
		ft_putendl_fd("./fillit: missing file operand", 2);
		return (true);
	}
	else if (number > 2)
	{
		ft_putendl_fd("Too many arguments", 2);
		return (true);
	}
	else if (number == 2 && ft_strcmp(str, "test24") != 0)
	{
		ft_putendl_fd("Wrong file name", 2);
		return (true);
	}
	else
		return (false);
}

/*Check FD return*/
t_bool	check_fd(int fd)
{
	if (fd < 0)
	{
		ft_putendl_fd("Error: open file", 2);
		return (true);
	}
	return (false);
}

/*check allocation memory return*/
t_bool	check_return(t_tetri *li)
{
	if (li == NULL)
	{
		ft_putendl_fd("Error: allocation memory(1)", 2);
		return (true);
	}
	return (false);
}
/*check return of dlist*/
t_bool check_return_dlist(t_dlist li)
{
	if (li == NULL)
	{
		ft_putendl_fd("Error: allocation memory(1)", 2);
		return (true);
	}
	return (false);
}