# Nombre del archivo biblioteca
NAME = libft.a

# Compilador y flags de compilacion
CC = cc
FLAGS = -Wall -Werror -Wextra

# Archivos fuente y archivos objeto
SRC = ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strlen.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_strlcpy.c \
	  ft_memchr.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_itoa.c \
	  ft_strdup.c \
	  ft_memcmp.c \
	  ft_atoi.c \
	  ft_putnbr_fd.c\
	  ft_calloc.c \
	  ft_substr.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_split.c\
	  ft_strmapi.c\
	  ft_striteri.c \
	  
BONUS_SRC =  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Archivo de encabezado
INCLUDE = libft.h

# Crear biblioteca y eliminar archivos
AR = ar rcs
RM = rm -f

# Indica que las siguientes reglas no son archivos reales
.PHONY: all clean fclean re bonus

# Regla que por defecto compila todo
all: $(NAME)

# Regla para crear la biblioteca
$(NAME): $(OBJ)
	$(AR) $@ $^

# Pasar archivos .c a .o
%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -c -o $@ $<

# Regla para eliminar todos los archivos objetos creados
clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

# Eliminar todos los archivos .o y .a
fclean: clean
	$(RM) $(NAME)

re: fclean all

# Regla para compilar el bonus
bonus: $(OBJ) $(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)
