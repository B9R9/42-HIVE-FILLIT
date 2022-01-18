# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 15:26:05 by briffard          #+#    #+#              #
#    Updated: 2022/01/18 17:37:01 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	 fillit

SRC_DIR		=	./sources/
OBJ_DIR		=	./objects/

SRC			=	main.c
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INCL_FILLIT	=	./includes
INCL_LIBFT	=	./libft/includes
LIBFT		=	./libft/ -lft

RM			=	rm

CC			=	gcc
CCFLAGS		=	-Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^ -L $(LIBFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)	
	$(CC) $(CCFLAGS) -I$(INCL_FILLIT) -I $(INCL_LIBFT) -o $@ -c $<

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) -f $(NAME)
	$(RM) -f tetriminos_generator

re: fclean all clean

lft:
	make -C libft/ fclean && make -C libft/  && make -C libft/ clean 

tetriminos:
	@bash tetriminos_generator.sh

.PHONY: all clean fclean re lft tetriminos

