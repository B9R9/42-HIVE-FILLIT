/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:33:45 by briffard          #+#    #+#             */
/*   Updated: 2022/01/26 15:04:01 by briffard         ###   ########.fr       */
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
typedef struct	s_arr_tetri
{
	char 					**tetriminos;
	int						**coordonnee;
//	int						position_horizontal;
//	int	 					position_verticale;
	struct s_arr_tetri		*next;
}				t_arr_tetri,*List_arr;

typedef struct	s_bits_tetri
{
	uint64_t 				bit;
	struct s_bits_tetri		*next;
}				t_bit_tetri, *List_bits;

/*Value of false = 0 and value of true = 1*/
typedef enum
{
	false,
	true
}	t_bool;

/*PROTOTYPES*/
List_arr	newlist_arr(void);
List_arr	push_back_list(List_arr li, char *shape);
void	print_list(List_arr li);
List_arr	pop_front_list(List_arr li);
List_arr	clear_list(List_arr li);

t_bool	is_valid(char *tetriminos);
int		sidechecker(char *tetriminos, int index);

#endif