# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 16:31:13 by dapaulin          #+#    #+#              #
#    Updated: 2022/12/09 21:27:29 by dapaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################  COLORS	##################
L_RED			=			\033[0;31m
L_REDB			=			\033[1;31m
L_WHITE			=			\033[0;37m
L_WHITEB		=			\033[1;37m
L_YELLOW		=			\033[0;33m
L_YELLOWB		=			\033[1;33m
L_GREEN			=			\033[0;32m
L_GREENB		=			\033[1;32m
################ CONFIG		##################
NAME			=			libftprintf.a
DIR_LIBFT		=			./libft/srcs/
LIBFT			=			libft.a
DIR 			= 			./
HEADERS 		= 			ft_printf.h $(addprefix $(DIR_LIBFT), libft.h)
################ SOURCES	##################
SRCS			=			ft_printf.c			ft_printf_utils.c		ft_printf_formats.c \
							ft_printf_create.c	ft_print_functions.c	ft_print_flags.c	 flag_adm.c
################ OTHERs		##################
FLAGS 			=			-Wall -Werror -Wextra
################ RULES		##################

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS:.c=.o)
	@ar -rc $(NAME) $(SRCS:.c=.o)
       
$(LIBFT):
#	@git	clone git@github.com:ThreeDP/Libft.git libft
	@cd		$(DIR_LIBFT) && $(MAKE) $@
	@cp		./libft/srcs/libft.a ./libftprintf.a

%.o:	%.c	$(HEADERS)
	@cc		-o $@ -c $<  -I ./ $(FLAGS)

bonus: all

norm:
	@norminette

clean:
	@rm			-f *.o
	@cd 		$(DIR_LIBFT) && $(MAKE) $@

fclean: 	clean
	@rm 		-f $(NAME)
	@cd 		$(DIR_LIBFT) && $(MAKE) $@
#	@rm 		-rf ./libft

re: fclean all

.PHONY: all
