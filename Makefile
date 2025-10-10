NAME = fdf

CC = cc
CFLAGS = 
INCLUDES = -Iincludes -Isrc/gnl -Isrc/libft -Isrc/minilibx

SRC_DIR = src
GNL_DIR = $(SRC_DIR)/gnl
LIBFT_DIR = $(SRC_DIR)/libft
MLX_DIR = $(SRC_DIR)/minilibx

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parse.c \
	$(SRC_DIR)/draw.c \
	$(SRC_DIR)/utils.c \
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
