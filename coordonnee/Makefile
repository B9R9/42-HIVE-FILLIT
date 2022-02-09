# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 15:26:05 by briffard          #+#    #+#              #
#    Updated: 2022/02/09 10:16:22 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	 fillit

SRC_DIR		=	./sources/
OBJ_DIR		=	./objects/

SRC			=	 main.c checkerrors.c readfile.c is_valid.c align.c		\
				dlist.c allocation_memory.c check_solver.c solver.version3.c		\
				display.c
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INCL_FILLIT	=	./sources/
INCL_LIBFT	=	./libft/includes/
LIBFT		=	./libft/ -lft

RM			=	rm

CC			=	gcc
CCFLAGS		=	-Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) $(CCFLAGS) -o $@ $^ -L $(LIBFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)	
	@$(CC) $(CCFLAGS) -I$(INCL_FILLIT) -I$(INCL_LIBFT) -o $@ -c $<

clean:
	@make -C ./libft/ clean
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@make -C ./libft/ fclean
	@$(RM) -f $(NAME)

re: fclean all clean

.PHONY: all clean fclean re lft tetriminos

