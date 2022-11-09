# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 16:31:13 by dapaulin          #+#    #+#              #
#    Updated: 2022/11/07 18:30:05 by dapaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################  COLORS	##################
L_RED			=			'\033[0;31m'
L_REDB			=			'\033[1;31m'
L_WHITE			=			'\033[0;37m'
L_WHITEB		=			'\033[1;37m'
L_YELLOW		=			'\033[0;33m'
L_YELLOWB		=			'\033[1;33m'
L_GREEN			=			'\033[0;32m'
L_GREENB		=			'\033[1;32m'
################ CONFIG		##################
NAME			=			libftprintf.a
DIR 			= 			./
HEADERS 		= 			ft_printf.h
################ SOURCES	##################
SRCS			=			ft_printf.c
################ OTHERs		##################
FLAGS 			=			-Wall -Werror -Wextra
################ RULES		##################

all: $(NAME)

$(NAME): $(SRCS:.c=.o)
	ar -rc $(NAME) $(SRCS:.c=.o) 
       
%.o:	%.c	$(HEADERS)
	cc		-o $@ -c $< $(FLAGS)

norm:
	@norminette

clean:
	@rm		-f *.o

fclean: 	clean
	@rm 		-f $(NAME)

re: fclean all

.PHONY: all