# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 16:12:04 by briffard          #+#    #+#              #
#    Updated: 2022/02/08 17:14:04 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


bitwise:
	make -C ./bitwise/ all

coordonnee:
	make -C ./coordonnee/ all

alltest:
	
validtest:

invalidtest:


clean:
	make -C ./bitwise/ clean
	make -C ./coordonnee/ clean

fclean:
	make -C ./bitwise/ fclean
	make -C ./coordonnee/ fclean

.PHONY: bitwise coordonnee alltest validtest invalidtest clean fclean

