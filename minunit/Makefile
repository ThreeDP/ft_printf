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
DIR 			= 			../srcs/
GNL				=			get_next_line.c get_next_line_utils.c
SRCS_TEST 		= 			ft_printf_mandatory_test.c
HEADERS 		= 			minunit.h get_next_line.h
################ OTHERs		##################
FLAGS 			=			-Wall -Werror -Wextra
################ RULES		##################

all:		$(SRCS_TEST:.c=.o)
       
%.o:	%.c	$(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g $< $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@./a.out

norm:
	@cd 		$(DIR) && $(MAKE) $@	

clean:
	@rm			-f ./files/*
	@rm			-f *.o
	@cd 		$(DIR) && $(MAKE) $@

fclean: 	clean
	@rm 		-f a.out
	@cd 		$(DIR) && $(MAKE) $@

re: fclean all

c:
	@rm			-f ./files/*

