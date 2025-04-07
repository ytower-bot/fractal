LIBFT_PATH		=	libs/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	libs/minilibx/
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SRC_FILES		=	main.c
SRC_BONUS		=

SRC_DIR			=	src
BONUS_DIR		=	src_bonus

INCLUDES		=	includes
HEADER			=	$(INCLUDES)/fractol.h
HEADER_BONUS	=	$(INCLUDES)/fractol_bonus.h

SRC				=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SRC_BONUS))

OBJ			= 	$(SRC:.c=.o)
OBJ_BONUS	= 	$(BONUS_FILES:.c=.o)

NAME			=	fractol
NAME_BONUS		=	fractol_bonus

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L. -lXext -L. -lX11

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJ) $(HEADER)
				$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(MINILIBX) $(OBJ_BONUS) $(HEADER_BONUS)
					$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME_BONUS)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJ) $(OBJ_BONUS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:			all clean fclean re libft minilibx bonus
