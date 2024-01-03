SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
       ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
       ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
       ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
       ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
       ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCSB = ft_lstnew.c ft_lstadd_front.c \
	ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
NAME = libft.a
ARFLAGS = -rc
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

GNL_DIR = getnextline
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

FT_PRINTF_DIR = printf
FT_PRINTF_SRCS = $(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_printf_1.c $(FT_PRINTF_DIR)/ft_printf_2.c
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

all: ${NAME}

${NAME}: ${OBJS} $(FT_PRINTF_OBJS) $(GNL_OBJS)
	ar -rc $(NAME) $(OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)

bonus: ${OBJSB}
	ar $(ARFLAGS) $(NAME) $(OBJSB)

clean:
	rm -f ${OBJS} ${OBJSB} $(FT_PRINTF_OBJS) $(GNL_OBJS)

fclean: clean
	rm -f ${NAME}

re: fclean all
