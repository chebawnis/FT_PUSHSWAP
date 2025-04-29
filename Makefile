CC = cc
CFLAGS = -Wall -Wextra -Werror -I include -g
NAME = push_swap
SRC = src/main.c \
		src/list_functions/list_functions.c \
		src/list_functions/list_utils.c \
		src/list_functions/list_utils_2.c \
		src/movements/push.c \
		src/movements/swap.c \
		src/movements/rotate.c \
		src/movements/r_rotate.c \
		src/sort_functions/first_part.c \
		src/sort_functions/second_part.c \
		src/sort_functions/get_number_shot.c \
		src/utils/parsing.c \
		src/utils/utils.c \
		src/utils/utils_2.c \
		src/utils/ft_split.c
OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
