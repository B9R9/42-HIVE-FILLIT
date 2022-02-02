/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:54:54 by briffard          #+#    #+#             */
/*   Updated: 2022/02/02 19:41:07 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int				fd;
	tetri_list		pieces;
//	char			**map;
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
		pieces = create_tetri_list(fd);
//		print_all_list(pieces);
//		if (check_return(pieces))
//			return(0);
		if (check_fd(close(fd)))
			return (0);
		solver(pieces, newmap(smallestmap(pieces)),pieces->coordonnee);
	}
	return (0);
}