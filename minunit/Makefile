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
SRCS_TEST 		= 			ft_printf_mandatory_test.c ft_printf_mandatory_bonus_test.c \
							formatstring_test.c formatchar_test.c \
							printstring_test.c
OUTS			=			./outs/
SOUTS			= 			$(addprefix $(OUTS), $(SRCS_TEST))
F				=			
HEADERS 		= 			minunit.h get_next_line.h
################ OTHERs		##################
FLAGS 			=			-Wall -Werror -Wextra
################ RULES		##################

all: m test valgrind

%.o:	%.c	$(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g $< $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf -o $(OUTS)$<

$(SOUTS):
	$@

test: m $(SOUTS)

m: 			$(SRCS_TEST:.c=.o)

valgrind:	m
	for X in $(SOUTS) ; do \
		echo  $(L_YELLOWB)[TEST $$X]$(L_WHITE) && \
		valgrind -s --track-origins=yes --error-exitcode=42 --leak-check=full $$X &&\
		echo	$(L_YELLOWB)[END VALGRIND $$X]$(L_WHITE) ; done

norm:
	@cd 		$(DIR) && $(MAKE) $@	

clean:
	@rm			-f *.o
	@rm			-f $(OUTS)*.c
	@rm			-rf $(OUTS)*.dSYM
	@cd 		$(DIR) && $(MAKE) $@

fclean: 	clean
	@rm 		-f *.out
	@rm			-rf *.dSYM
	@cd 		$(DIR) && $(MAKE) $@

re: fclean all

c:
	@rm			-f ./files/*

.PHONY: $(SOUTS)

string: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g formatstring_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	$(L_YELLOWB)[RUN formatstring_test.c]$(L_WHITE)
	@./a.out

char: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g formatchar_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	$(L_YELLOWB)[RUN formatchar_test.c]$(L_WHITE)
	@./a.out