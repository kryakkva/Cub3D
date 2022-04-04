NAME =		libft.a

SRCS = 		ft_atoi.c 			ft_bzero.c 			ft_calloc.c 			ft_isalnum.c 		ft_isalpha.c\
			ft_isascii.c 		ft_isdigit.c 		ft_isprint.c 			ft_itoa.c 			ft_memccpy.c\
	    	ft_memchr.c 		ft_memcmp.c 		ft_memcpy.c 			ft_memmove.c 		ft_memset.c\
			ft_putchar_fd.c 	ft_putendl_fd.c 	ft_putnbr_fd.c 			ft_putstr_fd.c 		ft_split.c\
	   		ft_strchr.c 		ft_strdup.c 		ft_strjoin.c 			ft_strlcat.c 		ft_strlcpy.c\
			ft_strlen.c 		ft_strmapi.c 		ft_strncmp.c 			ft_strnstr.c 		ft_strrchr.c\
	   		ft_strtrim.c		ft_substr.c 		ft_tolower.c 			ft_toupper.c		ft_strcmp.c\
			ft_in_charset.c		ft_itoa_width.c		ft_nbrlen.c				ft_swap.c			ft_min_int.c

SRCS_B =	ft_lstadd_back.c 	ft_lstadd_front.c 	ft_lstclear.c 			ft_lstdelone.c 		ft_lstiter.c\
			ft_lstlast.c 		ft_lstmap.c 		ft_lstnew.c 			ft_lstsize.c

OBJ = $(patsubst %.c,%.o,$(SRCS))
OBJ_B = $(patsubst %.c,%.o,$(SRCS_B))

OPTFLAGS = -O2

BLUE	=	\033[36m
DEF		=	\033[0m

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIB = ar rcs $(NAME)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(LIB)  $?

%.o : %.c libft.h
	@echo "$(BLUE)❱❱$(DEF)\c"
	@$(CC) $(CFLAGS) $(OPTFLAGS) -c $< -o $@ 

bonus : $(OBJ_B)
	@$(LIB)  $?

clean:
	@${RM} $(OBJ) $(OBJ_B)

fclean: clean
	@${RM} $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus