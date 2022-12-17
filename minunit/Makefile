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
GNL				=			get_next_line.c				get_next_line_utils.c
PSRCS_TEST 		= 			ft_printf_mandatory_test.c	ft_printf_bonus_test.c 
ESRCS_TEST		=			formatstring_test.c 		formatchar_test.c				formatint_test.c			formathex_test.c \
							printstring_test.c			printchar_test.c				printint_test.c				printhex_test.c
OUTS			=			./outs/
SOUTS			= 			$(addprefix $(OUTS), $(PSRCS_TEST)) $(addprefix $(OUTS), $(ESRCS_TEST))
HEADERS 		= 			minunit.h get_next_line.h
################ OTHERs		##################
FLAGS 			=			-Wall -Werror -Wextra
################ RULES		##################

all: 		t v

%.o:		%.c	$(HEADERS)
	@clang	-g $< $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf -o $(OUTS)$<

libft:
	@cd		$(DIR) && $(MAKE)

compile: 			libft $(PSRCS_TEST:.c=.o) $(ESRCS_TEST:.c=.o)

$(SOUTS):
	@echo  
	@echo  "$(L_YELLOWB)[TEST $@]$(L_WHITE)"
	@$@
	@echo  "$(L_WHITEB)"*******************************************************************"$(L_WHITEB)"

### TESTING CODE
t: 			compile $(SOUTS)

### VALGRIND
v:			compile
	@for X in $(SOUTS) ; do \
		echo  "$(L_YELLOWB)[TEST $$X]$(L_WHITE)" && \
		valgrind --track-origins=yes --error-exitcode=42 --leak-check=full $$X && \
		echo "$(L_WHITEB)"*******************************************************************"$(L_WHITE)" ; done

### NORMINETTE
n:
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

extra: compile c pc s ps i pi h ph

m: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g ft_printf_mandatory_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	"$(L_YELLOWB)[RUN ft_printf_mandatory_test.c]$(L_WHITE)"
	@./a.out

b: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g ft_printf_bonus_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	"$(L_YELLOWB)[RUN ft_printf_bonus_test.c]$(L_WHITE)"
	@./a.out

c: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g formatchar_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	"$(L_YELLOWB)[RUN formatchar_test.c]$(L_WHITE)"
	@./a.out

pc: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g printchar_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	"$(L_YELLOWB)[RUN printchar_test.c]$(L_WHITE)"
	@./a.out

s: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g formatstring_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	"$(L_YELLOWB)[RUN formatstring_test.c]$(L_WHITE)"
	@./a.out

ps: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g printstring_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	"$(L_YELLOWB)[RUN printstring_test.c]$(L_WHITE)"
	@./a.out

i: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g formatint_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	"$(L_YELLOWB)[RUN formatint_test.c]$(L_WHITE)"
	@./a.out

pi: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g printint_test.c $(GNL) $(FLAGS) -I $(DIR) -L $(DIR) -lftprintf
	@echo	"$(L_YELLOWB)[RUN printint_test.c]$(L_WHITE)"
	@./a.out

h: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g formathex_test.c $(GNL) -I $(DIR) -L $(DIR) -lftprintf
	@echo	"$(L_YELLOWB)[RUN formathex_test.c]$(L_WHITE)"
	@./a.out

ph: $(HEADERS)
	@cd		$(DIR) && $(MAKE)
	clang	-g printhex_test.c $(GNL) -I $(DIR) -L $(DIR) -lftprintf
	@echo	"$(L_YELLOWB)[RUN printhex_test.c]$(L_WHITE)"
	@./a.out

.PHONY: $(SOUTS)