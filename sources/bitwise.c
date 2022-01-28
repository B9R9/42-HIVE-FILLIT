/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:57:42 by briffard          #+#    #+#             */
/*   Updated: 2022/01/28 09:43:13 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fillit.h"

List_bits	newlist_bit(void)
{
	return (NULL);
}

/*============================================================================*/
/*PRINT BITS*/
void	printbit(uint64_t c)
{
	uint64_t	bit = 1 << 15;
	int 		i = 0;
	while (bit  != 0)
	{
		if (c & bit)
			ft_putchar('1');
		else
			ft_putchar('0');
		bit >>= 1;
		i++;
		if (i % 4 == 0)
			ft_putchar(' ');
	}
	ft_putchar('\n');
	ft_putchar('\n');
}

/*============================================================================*/
/*TURN STR EN BIT*/
uint64_t	turn_to_bit(char *str)
{
	int	i;
	int bit = 0;
	int add = 1 << 15;

	i = 0;
	while (str[i])
	{
		if (str[i] == BLOCK)
			bit += add;
		if (str[i] == 0)
			add = 1;
		if (str[i] == BLOCK || str[i] == EMPTY)
			add /= 2;
		i++;
	}
	return (bit);
}

/*=============================================================================*/
/*Created a new element and put at the end of the list*/
List_bits	push_back_list_bit(List_bits li, char *shape)
{
	t_bit_tetri	*element;
	t_bit_tetri	*temp;
	

	element = malloc(sizeof(*element));
	if (!element)
	{
		ft_putstr_fd("Error: problem with dynamic allocation memory\n", 2);
		exit(EXIT_FAILURE);
	}
	element->bit = turn_to_bit(shape);
	element->next = NULL;
	if (!li)
		return (element);
	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return (li);
}