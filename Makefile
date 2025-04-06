NAME = fractol
INCLUDE = includes
LIBFT_DIR = libs/libft
SRC_DIR = src
OBJ_DIR = obj
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I $(INCLUDE)

LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES = main.c init_stack.c sort_stack.c sort_stack_utils.c utils.c push.c swap.c rotate.c rev_rotate.c smart_sort.c smart_sort_utils.c error.c check_args.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
