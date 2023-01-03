################  COLORS	##################
L_RED			=			\033[0;31m
L_REDB			=			\033[1;31m
L_WHITE			=			\033[0;37m
L_WHITEB		=			\033[1;37m
L_YELLOW		=			\033[0;33m
L_YELLOWB		=			\033[1;33m
L_GREEN			=			\033[0;32m
L_GREENB		=			\033[1;32m
################ LIBRARY	##################
NAME 			= 			../libftprintf.a
################ MANDATORY	##################
SRCS 			=			ft_isalpha.c 		ft_isdigit.c 		ft_isalnum.c	\
							ft_isascii.c 		ft_isprint.c		ft_toupper.c	\
							ft_tolower.c		ft_strlen.c 		ft_memset.c		\
							ft_bzero.c 			ft_memcpy.c 		ft_memmove.c 	\
							ft_strlcpy.c 		ft_strlcat.c  		ft_strchr.c		\
							ft_strrchr.c 		ft_strncmp.c 		ft_memchr.c		\
							ft_memcmp.c 		ft_strnstr.c 		ft_atoi.c		\
							ft_calloc.c			ft_strdup.c			ft_substr.c		\
							ft_strjoin.c 		ft_strtrim.c 		ft_split.c		\
							ft_itoa.c 			ft_strmapi.c 		ft_striteri.c	\
							ft_putchar_fd.c 	ft_putstr_fd.c 		ft_putendl_fd.c	\
							ft_putnbr_fd.c		ft_isspace.c		ft_islower.c	\
							ft_isupper.c		ft_strndup.c		ft_uitoa.c		\
							ft_puthex_fd.c		ft_itoa_base.c
################ OTHERs		##################
FLAGS 			=			-Wall -Werror -Wextra
HEADER 			=	 		libft.h
################ RULES		##################
all: 		$(NAME)

%.o: 		%.c
	cc -o 		$@ -c $< -I ./ $(FLAGS)
	ar -rcs 	$(NAME) $@

$(NAME): 	$(SRCS:.c=.o)
	@echo		"$(L_YELLOWB)"Compile libft"$(L_WHITE)"

clean:
	@rm -f 		$(SRCS:.c=.o)

fclean: 	clean
	@rm -f 		$(NAME)

re: 		fclean all

.PHONY: 	all fclean clean re
