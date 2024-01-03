NAME = so_long

SRCS = map.c utils.c items.c main.c error.c dispose.c image.c control.c

MLX_DIR	= library/minilibx
MLX		= $(MLX_DIR)/libmlx.a
LIBFT_DIR = library/libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(MLX_DIR)

$(NAME) : $(MLX) $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

$(MLX):
	make -s -C $(MLX_DIR)

$(LIBFT): $(LIBFT_DIR)/getnextline/get_next_line.c $(LIBFT_DIR)/getnextline/get_next_line_utils.c 
	make -s -C $(LIBFT_DIR)

clean:
	make -s -C $(LIBFT_DIR) clean
	make -s -C $(MLX_DIR) clean

fclean: clean
	make -s -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
