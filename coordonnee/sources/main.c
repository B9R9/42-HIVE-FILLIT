/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:54:54 by briffard          #+#    #+#             */
/*   Updated: 2022/02/04 11:37:13 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int				fd;
	t_dlist			pieces;
	char			**map;
/*looking for errors with parameters*/
	if (check_parameters(argc, argv[1]))
		return (0);
	else
	{
/*opening file who content tetriminos pieces*/
		fd = open(argv[1], O_RDONLY);
		if (check_fd(fd))
			return (0);
/*Creation of linked list who will conteint all information of the tetriminos
 * pieces*/
		pieces = create_dlist(fd);
//		print_all_list(pieces);
//		if (check_return(pieces))
//			return(0);
		if (check_fd(close(fd)))
			return (0);
		map = newmap(smallestmap(pieces));
		if (solver(pieces, map))
			printmap(map);
		else
			printf("MAIN:\tERROR\n");
	}
	return (0);
}