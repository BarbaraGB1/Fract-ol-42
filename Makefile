NAME = fractol
SRC = main.c \
	  mlx_functions/mlx_generate.c \
	  mlx_functions/mlx_hooks.c \
	  mlx_functions/hooks.c \
	  mlx_functions/hook_color.c \
	  operations/scale.c \
	  operations/formula.c \
	  operations/checkers.c \
	  operations/colors.c \
	  setters/set_scale.c \
	  setters/set_formula.c \
	  setters/set_factors.c \
	  setters/set_colors.c \
	  print_message/message.c\
	  print_message/utils.c\
	  GNL/get_next_line.c\
	  GNL/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -rf
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINT_DIR = ft_printf
PRINT = $(PRINT_DIR)/libftprintf.a
all = $(NAME)
$(NAME): $(OBJ) $(LIBFT) $(PRINT)
		$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(PRINT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
$(LIBFT):
		make bonus -C $(LIBFT_DIR)
$(PRINT):
		make -C $(PRINT_DIR)
clean:
		$(RM) $(OBJ) fractol.dSYM
		$(MAKE) clean -C $(LIBFT_DIR)
		$(MAKE) clean -C $(PRINT_DIR)
fclean: clean
		$(RM) $(NAME) $(LIBFT) $(PRINT)
re: fclean
	$(MAKE) $(all)
.PHONY: re fclean clean all new
