/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:33:45 by briffard          #+#    #+#             */
/*   Updated: 2022/02/01 17:06:53 by briffard         ###   ########.fr       */
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
typedef struct	s_tetri
{
//	char 					**tetriminos;
	int						**coordonnee;
	struct s_tetri		*next;
}				t_tetri,*tetri_list;
/*
typedef struct	s_bits_tetri
{
	uint64_t 				bit;
	struct s_bits_tetri		*next;
}				t_bit_tetri, *List_bits;
*/
/*Value of false = 0 and value of true = 1*/
typedef enum
{
	false,
	true
}	t_bool;

/*PROTOTYPES*/
/*checkerrors.c*/
t_bool		check_parameters(int number, char *str);
t_bool		check_fd(int fd);
t_bool		check_return(tetri_list li);

/*readfile.c*/
tetri_list	create_tetri_list(int fd);

/*list.c*///COMPLETE FILE 5/5
tetri_list	push_back_list(tetri_list li, char *tetriminos);
tetri_list	pop_front_list(tetri_list li);
tetri_list	clearList(tetri_list li);
tetri_list	newlist(void);

/*allocation_memory.c*/
tetri_list	allocate_memory(tetri_list li);
char		**newmap(int size);
void		clearmap(char **map);

/*display.c*/
void		print_all_list(tetri_list li);
void		printmap(char **map);
char		**printcoordonnee(int **tab, char **map);

/*check_solver*/// 5/5 COMPLETE FILE
int			smallestmap(tetri_list li);
t_bool		check_limitsmap(int **tab, int size);
t_bool		block_checker(int **ar, char **map);
int			**move_coordonnee(int **tab, int mapsize);


/*is_valid.c*/
t_bool		is_valid(char *tetriminos);

/*align.c*/
t_bool		check_coordonnee(int **coordonnee);
int			**align(int **coordonnee, int result);

/*solver.c*/
int			solver(tetri_list li, char **map);


/*=======================================================================*/
/*
List_arr	newlist_arr(void);
List_arr	push_back_list(List_arr li, char *shape);
void	print_list(List_arr li, char *str);
List_arr	pop_front_list(List_arr li);
List_arr	clear_list(List_arr li);
char		**cpy_to_double_arr(char *str, char **arr);
int			**save_coordonne(char **str, int **tab);

t_bool	is_valid(char *tetriminos);
int		sidechecker(char *tetriminos, int index);

t_bool	check_coordonnee(int **coordonnee);
int		**align(int **coordonnee, int result);

List_bits		newlist_bit(void);
List_bits		push_back_list_bit(List_bits li, char *shape);
void			printbit(uint64_t c);
uint64_t		turn_to_bit(char *str);
char			**newmap(int i);

int			printmap(List_arr li, char **map);
*/
#endif