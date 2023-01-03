# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 16:31:13 by dapaulin          #+#    #+#              #
#    Updated: 2023/01/03 18:59:18 by dapaulin         ###   ########.fr        #
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
DIR_LIBFT		=			./libft/
DIR 			= 			./
HM		 		= 			./mandatory/ft_printf.h $(addprefix $(DIR_LIBFT), libft.h)
HB		 		= 			./bonus/ft_printf_bonus.h $(addprefix $(DIR_LIBFT), libft.h)
################ SOURCES	##################
SRCS			=			ft_printf.c			ft_printf_utils.c		ft_printf_formats.c \
							ft_printf_create.c	ft_print_functions.c	ft_print_flags.c	 flag_adm.c
BONUS_SRCS		=			ft_printf_bonus.c			ft_printf_utils_bonus.c		ft_printf_formats_bonus.c \
							ft_printf_create_bonus.c	ft_print_functions_bonus.c	ft_print_flags_bonus.c	 flag_adm_bonus.c
OBJSM			=			$(addprefix ./mandatory/, $(SRCS:.c=.o))
OBJSB			=			$(addprefix ./bonus/, $(BONUS_SRCS:.c=.o))
################ OTHERs		##################
FLAGS 			=			-Wall -Werror -Wextra
CHECKM			=			$(shell ar -t $(NAME) ft_printf.o 2>&1)
CHECKB			=			$(shell ar -t $(NAME) ft_printf_bonus.o 2>&1)
################ RULES		##################

ifeq ($(CHECKB), ft_printf_bonus.o)
all: $(HM) re
else
all: $(HM )$(NAME)
endif

ifeq ($(CHECKM),ft_printf.o)
bonus: fclean libft $(HB) $(OBJSB) 
else
bonus: libft $(HB) $(OBJSB) 
endif

$(NAME): libft $(OBJSM) $(HM)
       
libft:
	@cd 	$(DIR_LIBFT) && $(MAKE) --no-print-directory

%.o:	%.c
	cc		-o $@ -c $<  -I ./ $(FLAGS)
	ar -rc $(NAME) $@

clean:
	@rm			-f $(OBJSM) $(OBJSB)
	@cd 		$(DIR_LIBFT) && $(MAKE) $@ --no-print-directory

fclean: 	clean
	@rm 		-f $(NAME)
	@cd 		$(DIR_LIBFT) && $(MAKE) $@ --no-print-directory

re: fclean
	make

.PHONY: all libft
