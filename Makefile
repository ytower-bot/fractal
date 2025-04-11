LIBFT_PATH		=	libs/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	libs/minilibx/
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SRC_FILES		=	main.c init.c render.c fractals.c events.c utils.c
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

CC				=	cc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLX_FLAGS		=	-L./libs/minilibx -lmlx -lXext -lX11 -lm

.c.o:
				$(CC) $(CFLAGS) -I./includes -I./libs/libft/includes -I./libs/minilibx -c $< -o $@

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(OBJ) $(HEADER)
				$(MAKE) -C $(LIBFT_PATH)
				$(MAKE) -C $(MINILIBX_PATH)
				$(CC) $(CFLAGS) $(OBJ) -L./libs/libft -lft $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS):		$(OBJ_BONUS) $(HEADER_BONUS)
					$(CC) $(CFLAGS) $(OBJ_BONUS) -L./libs/libft -lft $(MLX_FLAGS) -o $(NAME_BONUS)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJ) $(OBJ_BONUS)

fclean:			
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJ) $(OBJ_BONUS) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:			all clean fclean re libft minilibx bonus
