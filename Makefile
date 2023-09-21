# COLOR MAKEFILE
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;36m
COLOUR_YELLOW = \033[0;93m
COLOUR_MAGENTA = \033[0;95m
END_COLOR=\033[0m

# VAR
NAME = so_long
ORIGIN = main.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include/
CDFLAGS = -Wall -Wextra -Werror -g -I./include/

DIR_UTILS = utils/
SRCS_UTILS =	$(DIR_UTILS)exit_free.c \
				$(DIR_UTILS)ft_create_array.c \
				$(DIR_UTILS)fn_utils.c \
				$(DIR_UTILS)for_dev.c \


DIR_GNL =		get_next_line/
SRCS_GNL =	$(DIR_GNL)get_next_line_utils.c $(DIR_GNL)get_next_line.c

DIR_PARS = parsing/
SRCS_PARS =	$(DIR_PARS)check_map.c\
			$(DIR_PARS)valid_map.c\
			$(DIR_PARS)ft_parsing.c\
			$(DIR_PARS)ft_flood_fill.c\

DIR_GAME = game/
SRCS_GAME =	$(DIR_GAME)create_window.c\
			$(DIR_GAME)event.c\
			$(DIR_GAME)ft_game.c\
			$(DIR_GAME)draw_window.c\
			$(DIR_GAME)move_player.c\
			$(DIR_GAME)manage_game.c\

# DIR_X = x/
# SRCS_PARS =	$(DIR_X)y.c\

SRCS = $(SRCS_GNL) $(SRCS_UTILS) $(SRCS_PARS) $(SRCS_GAME) $(ORIGIN)
OBJS = $(SRCS:.c=.o)

# RULES
all: $(NAME)

libft:
	@make -C ./include/libft

minilibX:
	@make -C ./mlx

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) $(OBJS) libft minilibX
	$(CC) $(CFLAGS) -I ./include $(OBJS) ./include/libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(COLOUR_MAGENTA) generate with minilbX 🥳$(END_COLOR)"
	@echo "$(COLOUR_MAGENTA)objs & NAME generate 🌸$(END_COLOR)"

run: $(OBJ) libft minilibX
	$(CC) $(CFLAGS) -I ./include $(SRCS) ./include/libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(COLOUR_MAGENTA) generate with minilbX 🥳$(END_COLOR)"
	@echo "$(COLOUR_GREEN)$(NAME) generate 🍀$(END_COLOR)"

norme:
	norminette $(SRCS) ./include/*.h

leaks: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean:
	@cd ./include/libft; make clean
	@cd ./mlx; make clean
	@rm -rf $(OBJS)
	@echo "$(COLOUR_BLUE) clean 🐟$(END_COLOR)"

fclean: clean
	@cd ./include/libft; make fclean
	@rm -rf $(NAME) $(NAME)
	@echo "$(COLOUR_BLUE)$(NAME) fclean 🐳$(END_COLOR)"

re:fclean all
	@echo "$(COLOUR_MAGENTA)make re OK 🌸$(END_COLOR)"

.PHONY: all clean fclean re run libft
