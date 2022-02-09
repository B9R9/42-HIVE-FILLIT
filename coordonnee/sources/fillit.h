/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:33:45 by briffard          #+#    #+#             */
/*   Updated: 2022/02/09 10:16:15 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*INCLUDES*/
# include <fcntl.h>
# include <stdint.h>
# include "libft.h"
# include <stdio.h>

/*DEFINE*/
# define BUFF_SIZE 8

# define BLOCK '#'
# define EMPTY '.'
# define NEWLINE '\n'
# define MAX_SIZE 21

/*TYPEDEF*/
typedef struct	s_dlist
{
	int				length;
	struct s_tetri	*begin;
	struct s_tetri	*end;
}				*t_dlist;

typedef struct	s_tetri
{
//	char 					**tetriminos;
	char					letter;
	int						**coordonnee;
	int						**temp;
	struct s_tetri		*next;
	struct s_tetri		*back;
}				t_tetri;

/*PROTOTYPES*/
/*checkerrors.c*/
t_bool		check_parameters(int number, char *str);
t_bool		check_fd(int fd);
t_bool		check_return(t_tetri *li);
t_bool		check_return_dlist(t_dlist li);

/*readfile.c*/
t_dlist	create_dlist(int fd);

/*list.c*///COMPLETE FILE 5/5
t_dlist	push_back_list(t_dlist li, char *tetriminos);
t_dlist	pop_front_list(t_dlist li);
t_dlist	clearList(t_dlist li);
t_dlist	newlist(void);
t_bool	is_empty_dlist(t_dlist li);
int		**cp_to(int **tab, int **coord);

/*allocation_memory.c*/
t_tetri	allocate_memory(t_tetri li);
char		**newmap(int size);
void		clearmap(char **map);

/*display.c*/
void		print_all_list(t_dlist li);
void		printmap(char **map);
char		**printcoordonnee(int **tab, char **map, char c);

/*check_solver*/// 5/5 COMPLETE FILE
int			smallestmap(t_dlist li);
t_bool		check_limitsmap(int **tab, int size);
t_bool		block_checker(int **ar, char **map);
int			**move_coordonnee(int **tab, int mapsize);


/*is_valid.c*/
t_bool		is_valid(char *tetriminos);

/*align.c*/
t_bool		check_coordonnee(int **coordonnee);
int			**align(int **coordonnee, int result);

/*solver.c*/
int			solver(t_dlist li, char **map);

#endif