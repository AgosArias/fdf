NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR)

SRC_DIR = src
MLX_DIR = $(SRC_DIR)/minilibx
GNL_DIR = $(SRC_DIR)/gnl

SRC = 	$(SRC_DIR)/main.c \
		$(SRC_DIR)/parse.c \
		$(SRC_DIR)/draw.c \
		$(SRC_DIR)/utils.c 

SRC_GNL= $(GNL_DIR)/get_next_line.c \
		$(GNL_DIR)/get_next_line_utils.c 

OBJ = $(SRC:.c=.o)


MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Compilación completa: $(NAME)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf %.o
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all 