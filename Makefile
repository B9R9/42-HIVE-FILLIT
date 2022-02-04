# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 15:26:05 by briffard          #+#    #+#              #
#    Updated: 2022/02/04 08:09:25 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	 fillit

SRC_DIR		=	./sources/
OBJ_DIR		=	./objects/

SRC			=	 main.c checkerrors.c readfile.c is_valid.c align.c		\
				dlist.c allocation_memory.c check_solver.c solver.version3.c		\
				display.c
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INCL_FILLIT	=	./includes
INCL_LIBFT	=	./sources/libft/includes
LIBFT		=	./sources/libft/ -lft

RM			=	rm

CC			=	gcc
CCFLAGS		=	-Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CCFLAGS) -o $@ $^ -L $(LIBFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)	
	@$(CC) $(CCFLAGS) -I$(INCL_FILLIT) -I $(INCL_LIBFT) -o $@ -c $<

clean:
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@$(RM) -f $(NAME)

re: fclean all clean

lft:
	@make -C ./sources/libft/ fclean && make -C ./sources/libft/  && make -C ./sources/libft/ clean 

tetrigen:
	@make -C eval_test/tetrigen/ fclean && make -C eval_test/tetrigen
	@./eval_test/tetrigen/runtetrigen.sh

.PHONY: all clean fclean re lft tetriminos

