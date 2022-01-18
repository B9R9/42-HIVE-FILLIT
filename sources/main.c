/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:31:48 by briffard          #+#    #+#             */
/*   Updated: 2022/01/18 16:52:28 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
		ft_putstr("usage: ./fillit source_file");
	else
	{
		fd = open(argv[1], O_RDONLY);
		while(get_next_line(fd, &line) > 0)
		{
			ft_putstr(line);
			ft_putchar('\n');
		}
	}
	return (0);
}