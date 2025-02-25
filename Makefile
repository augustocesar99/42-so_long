NAME := so_long

CC := clang
CFLAGS := -Wall -Werror -Wextra
RM := rm -rf

INCLUDES_DIR := includes
LIBS_DIR := libs
MLX := mlx
LIBFT := $(LIBS_DIR)/libft
LIBS := \
	-L$(LIBS_DIR)/$(MLX) -l$(MLX)_Linux -L/usr/lib -L$(LIBFT) -lft -lXext -lX11
INCLUDES := -I/usr/include -I$(INCLUDES_DIR) -I$(LIBS_DIR)/$(MLX) -I$(LIBFT)

HEADERS := $(INCLUDES_DIR)/so_long.h

SRC_DIR := src
SRCS := \
	$(SRC_DIR)/main.c $(SRC_DIR)/hooks.c $(SRC_DIR)/map.c $(SRC_DIR)/render.c \
	$(SRC_DIR)/controller.c $(SRC_DIR)/utils.c $(SRC_DIR)/errors.c

OBJ_DIR := objects
OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(MLX) $(LIBFT) $(OBJ_DIR) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $@

$(MLX):
	[ -f $(LIBS_DIR)/$(MLX)/libmlx_Linux.a ] || $(MAKE) -C $(LIBS_DIR)/$(MLX)

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(LIBS_DIR)/$(MLX) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all $(LIBFT) clean fclean re norm