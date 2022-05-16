$(VERBOSE).SILENT:

NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wall
RM			=	rm -f
MKD			=	mkdir
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit

SRC_NAME	=	main.c \
				open_window.c \
				init_game.c \
				read_images.c \
				move_player.c \
				moves.c \
				valid_map.c \
				ft_itoa.c \
				put_image.c \
				game_bonus.c \
				libft_utils.c

SRC		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ		=	$(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRC))
DEPS	=	./ft_printf/ft_printf.a ./get_next_line/get_next_line.a

SRC_PATH = .
OBJ_PATH = ./objects

all: $(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(DEPS) $(OBJ_PATH) $(OBJ)
		$(CC) $(CFLAGS) $(DEPS) $(MLXFLAGS) $(OBJ) -o $(NAME)
		echo "\x1b[36m[SO_LONG COMPILED]\x1b[0m"

LIBPF_PATH	= ./ft_printf
./ft_printf/ft_printf.a: $(shell make -C $(LIBPF_PATH) -q ft_printf.a || echo force)
	make -C $(LIBPF_PATH)

GET_PATH	= ./get_next_line
./get_next_line/get_next_line.a: $(shell make -C $(GET_PATH) -q get_next_line.a ||echo force)
	make -C $(GET_PATH)

$(OBJ_PATH):
	$(MKD) -p objects

norminette:
	echo "\x1b[32m[NORMINETTE]\x1b[0m"
	norminette | egrep -B1 'Error|Warning' | sed ''/Error/s//$(printf "\033[31m\033[4mError\033[0m")/'' | sed ''/Warning/s//$(printf "\033[33m\033[4mWarning\033[0m")/''

clean:
	make clean -C $(LIBPF_PATH)
	make clean -C $(GET_PATH)
	$(RM) -r $(OBJ_PATH)
	echo "\033[33mRemoving object files...\033[0m"

fclean: clean
		make fclean -C $(LIBPF_PATH)
		make fclean -C $(GET_PATH)
		$(RM) $(NAME)
		echo "\033[31mRemoving $(NAME)...\033[0m"

re: fclean all

.PHONY:	all clean fclean re force