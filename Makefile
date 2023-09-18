# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 11:43:07 by atangil           #+#    #+#              #
#    Updated: 2023/09/18 15:55:17 by atangil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror -g

all:
	@echo Mandatory compiled
	@gcc $(FLAG) server.c -o server
	@gcc $(FLAG) client.c -o client
	@rm -rf server.dSYM
	@rm -rf client.dSYM
	@rm -rf server_bonus
	@rm -rf client_bonus
	
bonus:
	@echo Bonus compiled
	@gcc $(FLAG) server_bonus.c -o server_bonus
	@gcc $(FLAG) client_bonus.c -o client_bonus
	@rm -rf server_bonus.dSYM
	@rm -rf client_bonus.dSYM
	@rm -rf server
	@rm -rf client

run: all
	@./server
brun: bonus
	@./server_bonus
clean:
	@echo Cleaned
	@rm -rf server
	@rm -rf client
	@rm -rf server_bonus
	@rm -rf client_bonus

fclean: clean

re: fclean all

.PHONY : all bonus clean fclean	