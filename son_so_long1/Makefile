NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MINILIBX = minilibx-linux/libmlx.a\
FT_PRINTF = ft_printf/libftprintf.a
MLXFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm -L./ft_printf -lftprintf
INCLUDES = -I. -I./minilibx-linux -I./get_next_line -I./ft_printf -I./libft -I./main -I./read -I./collectiables 

SRC = main/main.c \
	read/read_map.c \
	collectiables/check_collectiables.c \
	map_control.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	libft/utils.c \
	main/window.c \
	main/move.c \
	main/height.c \
	main/map.c \
	read/map_info.c \
	read/check_map.c \
	collectiables/c1.c \
	collectiables/c2.c 

OBJ = $(SRC:.c=.o)

all : $(MINILIBX) $(FT_PRINTF) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MINILIBX):
	@make -C minilibx-linux

$(FT_PRINTF):
	@make -C ft_printf

clean:
	rm -f $(OBJ)
	@make -C minilibx-linux clean
	@make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	@make -C minilibx-linux clean
	@make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re