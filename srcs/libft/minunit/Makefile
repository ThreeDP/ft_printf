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
DIR 			= 			../srcs/
LIB 			= 			libft.a
SRCS 			= 			$(wildcard ./mandatory/*.c)
SRCS_BONUS 		= 			$(wildcard ./bonus/*.c)
SRCS_EXTRA 		= 			$(wildcard ./extra/*.c)
HEADERS 		= 			minunit.h test.h
FLAGS 			= 			-Wall -Werror -Wextra
################ RULES		##################

all: 		m b e

m:			$(SRCS:.c=.o)
	@echo		"$(L_GREENB)**********[Compiled Mandatory!]**********$(L_WHITE)"

b:			$(SRCS_BONUS:.c=.o)
	@echo		"$(L_GREENB)************[Compiled Bonus!]************$(L_WHITE)"

e:			$(SRCS_EXTRA:.c=.o)
	@echo		"$(L_GREENB)************[Compiled Extra!]************$(L_WHITE)"

%.o: 		%.c $(HEADERS) 
	@cd 		$(DIR) && $(MAKE)
	@cc 		-o $@ -c $< $(FLAGS)
	@gcc		$(FLAGS) $@ -I $(DIR) -L $(DIR) -lft
	@echo		"$(L_YELLOWB)[testing: $@]$(L_WHITE)"
	@./a.out

norm:
	@cd 		$(DIR) && $(MAKE) $@

cleann:
	@rm			-f $(SRCS:.c=.o)
	@rm			-f $(SRCS_BONUS:.c=.o)
	
clean:		cleann
	@cd 		$(DIR) && $(MAKE) $@

fclean: 	cleann
	@rm 		-f a.out
	@cd 		$(DIR) && $(MAKE) $@

re: fclean all

.PHONY: m b e re clean fclean norm
