# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tetriminos_generator.sh                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 16:12:39 by briffard          #+#    #+#              #
#    Updated: 2022/01/18 16:26:59 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

gcc -Wall -Werror -Wall ./tetriminos/tetriminos_generator.c -o tetriminos_generator
printf "How many tetriminos do you want? "
read ANSWER
./tetriminos_generator $ANSWER > ./tetriminos/tetriminos.fillit
