# Nom de l'exécutable
NAME = push_swap

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -no-pie -g

SRC_DIR = src
WRAP_DIR = src/wrappers
SRC =	$(SRC_DIR)/check_input.c \
		$(SRC_DIR)/init_stack.c \
		$(SRC_DIR)/operations.c \
		$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/set_index.c \
		$(SRC_DIR)/sort_stack.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/free_stack.c \
		$(SRC_DIR)/mini_sort.c \
		$(SRC_DIR)/mini_sort2.c \
		$(SRC_DIR)/deja_sort.c \
		$(WRAP_DIR)/pa.c \
		$(WRAP_DIR)/pb.c \
		$(WRAP_DIR)/ra.c \
		$(WRAP_DIR)/rb.c \
		$(WRAP_DIR)/rr.c \
		$(WRAP_DIR)/rra.c \
		$(WRAP_DIR)/rrb.c \
		$(WRAP_DIR)/rrr.c \
		$(WRAP_DIR)/sa.c \
		$(WRAP_DIR)/sb.c \
		$(WRAP_DIR)/ss.c \
	
OBJ = $(SRC:.c=.o)

# Répertoire de la libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Compilation
all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "libft OK"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) > /dev/null
	@echo "push_swap OK"

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(NAME)

re: fclean all