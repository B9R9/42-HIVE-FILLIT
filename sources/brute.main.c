/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:57:42 by briffard          #+#    #+#             */
/*   Updated: 2022/02/01 10:02:39 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fillit.h"

int	main(int argc, char **argv)
{
	List_arr			tetriminos;
	List_bits			bit_tetriminos;
	char				pieces[MAX_SIZE + 1];
	int					fd;
	int		 			ret;
	char				**map;
	size_t					i = 0;
	
	map = newmap(4);
	tetriminos = newlist_arr();
	bit_tetriminos = newlist_bit();

	if (argc != 2)
		ft_putstr("Error// print usage message\n");
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_putstr("Error: open file.\n");
	while((ret = read(fd, pieces, MAX_SIZE)))//NOT AT THE NORM
		{
			printf("RET =%d\n", ret);
			pieces[ret] = '\0';
			if (is_valid(pieces))
			{
				tetriminos = push_back_list(tetriminos, pieces);
				bit_tetriminos = push_back_list_bit(bit_tetriminos, pieces);
			}
			else
			{
				ft_putstr_fd("Error: Not a valid tetriminos.\nEnd of the programm\n", 2);
				clear_list(tetriminos);
				break;
			}
		}
	close(fd);
	//print_list(tetriminos,"coordonnee");
	printf("%sLongueur de map: %ld%s\n", GREEN, ft_strlen(map[0]),NORMAL);
	i = 0;
	printf("ORIGNAL MAP:\n");
	while (i < ft_strlen(map[0]))
		printf("%s%s%s\n", BLUE, map[i++],NORMAL);
	printmap(tetriminos, map);
	

}
	/*while (bit_tetriminos != NULL)
	{
		i = 0;
		while (i < 4)
		{
			printf("%s\n", tetriminos->tetriminos[i]);
			i++;
		}
		i = 0;
		printf("Coordonne of #: \n");
		while (i < 4)
		{
			printf("line: %d\tcolumn: %d\n", tetriminos->coordonnee[i][0], tetriminos->coordonnee[i][1]);
			i++;
		}
		printf("Value of tetriminos in bit: \n");
		printbit(bit_tetriminos->bit);
		bit_tetriminos = bit_tetriminos->next;
		tetriminos = tetriminos->next;
	}
	while(tetriminos != NULL)
	{
		i = 0;
		printf("AVANT: Coordonne of #: \n");
		while (i < 4)
			{
				printf("line: %d\tcolumn: %d\n", tetriminos->coordonnee[i][0], tetriminos->coordonnee[i][1]);
				i++;
			}
		i = 0;
		while (i < 4)
		{
			printf("%s\n", tetriminos->tetriminos[i]);
			i++;
		}*/
//		tetriminos->coordonnee = align(tetriminos->coordonnee, check_coordonnee(tetriminos->coordonnee));
/*		printf("%s============================================================%s\n",YELLOW, NORMAL);
		i = 0;
		k = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (k < 4)
				{
					if (tetriminos->coordonnee[k][0] == i && tetriminos->coordonnee[k][1] == j)
					{
						ft_putchar('#');
					k++;
					}
					else
						ft_putchar('.');
				}
				else
					ft_putchar('.');
				j++;
			}
			ft_putchar('\n');
			i++;
		}
		printf("APRES: Coordonne of #: \n");
		i = 0;
		while (i < 4)
			{
				printf("line: %d\tcolumn: %d\n", tetriminos->coordonnee[i][0], tetriminos->coordonnee[i][1]);
				i++;
			}
		printf("%s============================================================%s\n",YELLOW, NORMAL);
		tetriminos = tetriminos->next;
	}*/