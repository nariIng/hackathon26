NAME = libftprintf.a
SRCS = 	ft_print_hex.c \
		ft_print_num.c \
		ft_print.c \
		ft_printf.c \
		ft_put_fd.c \
		ft_putstr_fd.c

CC = gcc -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f
OBJS = $(SRCS:.c=.o)
LBFT_DIR = ./libft

all : $(NAME)

lbft : libft
	make bonus -C $(LBFT_DIR)
	cp $(LBFT_DIR)/libft.a ./

$(NAME) : lbft $(OBJS)
	$(AR) libft.a $(OBJS)

clean :
	make clean -C $(LBFT_DIR)
	$(RM) $(OBJS)

fclean : clean
	$(RM) libft.a
	make fclean -C $(LBFT_DIR)

re : fclean all
