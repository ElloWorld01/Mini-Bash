CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = \
	./ft_atoi.c			\
	./ft_bzero.c		\
	./ft_calloc.c		\
	./ft_isalnum.c		\
	./ft_isalpha.c		\
	./ft_isascii.c		\
	./ft_isdigit.c		\
	./ft_isprint.c		\
	./ft_itoa.c			\
	./ft_lstadd_back.c	\
	./ft_lstadd_front.c	\
	./ft_lstclear.c		\
	./ft_lstdelone.c	\
	./ft_lstiter.c		\
	./ft_lstlast.c		\
	./ft_lstmap.c		\
	./ft_lstnew.c		\
	./ft_lstsize.c		\
	./ft_memchr.c		\
	./ft_memcmp.c		\
	./ft_memmove.c		\
	./ft_memcpy.c		\
	./ft_memset.c		\
	./ft_putchar_fd.c	\
	./ft_putstr_fd.c	\
	./ft_putendl_fd.c	\
	./ft_putnbr_fd.c    \
	./ft_split.c		\
	./ft_strchr.c		\
	./ft_strcmp.c		\
	./ft_strdup.c		\
	./ft_striteri.c		\
	./ft_strjoin.c		\
	./ft_strlcat.c		\
	./ft_strlcpy.c		\
	./ft_strlen.c		\
	./ft_strmapi.c		\
	./ft_strncmp.c		\
	./ft_strnstr.c		\
	./ft_strrchr.c		\
	./ft_strtrim.c		\
	./ft_substr.c		\
	./ft_tolower.c		\
	./ft_toupper.c		\
	./ft_printf/ft_printf.c       \
	./ft_printf/numbers_cases.c   \
	./ft_printf/chars_cases.c     \
	./ft_printf/hexa_cases.c      \
	./ft_printf/pointer_case.c    \
	./ft_printf/hexadeci_utils.c  \
	./ft_printf/unsigned_case.c	\
	./get_next_line/get_next_line.c	\
	./get_next_line/get_next_line_utils.c \

INCLUDES = -I. -I./get_next_line

OBJS = $(SRCS:.c=.o)

NAME = libft.a

all :	${NAME}

.c.o:
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME} :	${OBJS}
	@ar rc ${NAME} ${OBJS}

clean:
	@rm -f ${OBJS}

fclean:	clean
	@rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
