# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 16:31:13 by dapaulin          #+#    #+#              #
#    Updated: 2022/11/26 18:34:43 by dapaulin         ###   ########.fr        #
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
DIR_LIBFT		=			./libft/
LIBFT			=			libft.a
DIR 			= 			./
HEADERS 		= 			ft_printf.h $(addprefix $(DIR_LIBFT), libft.h)
################ SOURCES	##################
SRCS			=			ft_printf.c			ft_printf_utils.c		ft_printf_formats.c \
							ft_printf_create.c	ft_print_functions.c
################ OTHERs		##################
FLAGS 			=			-Wall -Werror -Wextra
################ RULES		##################

all: $(NAME)

$(NAME): $(SRCS:.c=.o) $(LIBFT)
	@ar -rc $(NAME) $(SRCS:.c=.o)
       
$(LIBFT):
	@cd		$(DIR_LIBFT) && $(MAKE) $@
	@cp		./libft/libft.a ./libftprintf.a

%.o:	%.c	$(HEADERS)
	@cc		-o $@ -c $<  -I ./ $(FLAGS)

norm:
	@norminette

clean:
	@rm		-f *.o
	@cd 		$(DIR_LIBFT) && $(MAKE) $@

fclean: 	clean
	@rm 		-f $(NAME)
	@cd 		$(DIR_LIBFT) && $(MAKE) $@

re: fclean all

.PHONY: all