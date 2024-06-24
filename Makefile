NAME = so_long
SRCS = 	main.c exit.c so_long_utiles.c ft_key.c positiv_moov.c \
		map.c error.c ennemi_moov.c load.c init.c draw.c position.c \
		enemy.c wall_error.c set_get_map.c map_utiles.c negativ_moov.c
SRCS_B = ./bonus/main.c ./bonus/exit_bonus.c ./bonus/so_long_utiles_bonus.c \
		./bonus/ft_key_bonus.c ./bonus/positiv_moov_bonus.c ./bonus/map_bonus.c \
		./bonus/error_bonus.c ./bonus/ennemi_moov_bonus.c ./bonus/load_bonus.c \
		./bonus/init_bonus.c ./bonus/draw_bonus.c ./bonus/position_bonus.c \
		./bonus/enemy_bonus.c ./bonus/wall_error_bonus.c ./bonus/set_get_map_bonus.c \
		./bonus/map_utiles_bonus.c ./bonus/negativ_moov_bonus.c

SRCS_GNL = ./gnl/get_next_line_bonus.c ./gnl/get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)
AR = ar -rcs
CC = gcc -Wall -Wextra -Werror -g
MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
RM = rm -f
PRINTF_DIR = ./libftprintf

all : $(NAME)

print : libftprintf
		make -C $(PRINTF_DIR)
		cp $(PRINTF_DIR)/libft.a ./

$(NAME): print $(OBJS) $(OBJS_GNL)
		$(AR) libft.a $(OBJS) $(OBJS_GNL)
		$(CC) -o $(NAME) libft.a $(MLX)

bonus : print $(OBJS_B) $(OBJS_GNL)
		$(AR) libft.a $(OBJS_B) $(OBJS_GNL)
		$(CC) -o $(NAME) libft.a $(MLX)

clean:
		make clean -C $(PRINTF_DIR)
		$(RM) $(OBJS) $(OBJS_GNL) $(OBJS_B)

fclean: clean
		$(RM) $(NAME)
		$(RM) libft.a
		make fclean -C $(PRINTF_DIR)

re: fclean all

rebonus: fclean bonus
