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
AUX				=			./min_aux/faux.c
GNL				=			get_next_line.c get_next_line_utils.c
SRCS_TEST 		= 			ft_printf_mandatory_test.c ft_printf_bonus_test.c \
							formatstring_test.c formatchar_test.c formatint_test.c formathex_test.c \
							printstring_test.c printchar_test.c printint_test.c
OUTS			=			./outs/
SOUTS			= 			$(addprefix $(OUTS), $(SRCS_TEST))
F				=			
HEADERS 		= 			minunit.h get_next_line.h
################ OTHERs		##################
FLAGS 			=			-Wall -Werror -Wextra
################ RULES		##################

all: 		m test valgrind

%.o:		%.c	$(HEADERS)
	@cd		$(DIR) && $(MAKE)
	@clang	-g $< $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf $(AUX) -o $(OUTS)$<

m: 			$(SRCS_TEST:.c=.o)

$(SOUTS):
	@echo  
	@echo  $(L_YELLOWB)[TEST $@]$(L_WHITE)
	@$@
	@echo  $(L_WHITEB)"*******************************************************************"$(L_WHITEB)

test: 		m $(SOUTS)

valgrind:	m
	@for X in $(SOUTS) ; do \
		echo  $(L_YELLOWB)[TEST $$X]$(L_WHITE) && \
		valgrind -s --track-origins=yes --error-exitcode=42 --leak-check=full $$X && \
		echo $(L_WHITEB)"*******************************************************************"$(L_WHITE) ; done

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

char: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g formatchar_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	$(L_YELLOWB)[RUN formatchar_test.c]$(L_WHITE)
	@./a.out

string: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g formatstring_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	$(L_YELLOWB)[RUN formatstring_test.c]$(L_WHITE)
	@./a.out

pstring: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g printstring_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	$(L_YELLOWB)[RUN printstring_test.c]$(L_WHITE)
	@./a.out

pchar: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g printchar_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	$(L_YELLOWB)[RUN printchar_test.c]$(L_WHITE)
	@./a.out

int: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g formatint_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	$(L_YELLOWB)[RUN formatint_test.c]$(L_WHITE)
	@./a.out

pint: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g printint_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	$(L_YELLOWB)[RUN printint_test.c]$(L_WHITE)
	@./a.out

hex: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g formathex_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	$(L_YELLOWB)[RUN formathex_test.c]$(L_WHITE)
	@./a.out
