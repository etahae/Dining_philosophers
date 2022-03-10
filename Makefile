# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnamir <tnamir@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 18:52:29 by tnamir            #+#    #+#              #
#    Updated: 2022/03/10 21:43:15 by tnamir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = philosophers.h

SRC = philosophers.c ft_atoi.c initializer.c fcts.c

all : $(NAME) $(HEADER)

$(NAME) : $(SRC)
	@cc -Werror -Wall -Wextra $(SRC) -o philo

clean :
	@rm -rf philo

fclean : clean

re : fclean all