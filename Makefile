# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:41:52 by acesar-m          #+#    #+#              #
#    Updated: 2025/02/07 12:07:35 by acesar-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= so_long

LIBFT				= ./libs/libft/libft.a
MLX_PATH			:= ./libs/mlx42
MLX_BUILD_PATH		:= $(MLX_PATH)/build
MLX_LIB				:= $(MLX_BUILD_PATH)/libmlx42.a
INC					= include/
SRC_DIR				= commands/
OBJ_DIR				= obj/

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I$(INC)
RM					= rm -f

COMMANDS_SRCS		= $(SRC_DIR)main.c

SRCS 				= $(COMMANDS_SRCS)

OBJ 				= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all:				$(MLX_LIB) $(NAME) 

$(NAME):			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_LIB) -lglfw -lm -ldl -lpthread -o $(NAME)
					@printf "\033[0;32mCompilation completed successfully!\033[0m\n"

$(LIBFT):
					@make -C ./libs/libft all

$(MLX_LIB):
					@cmake -B $(MLX_BUILD_PATH) -S $(MLX_PATH)
					@cmake --build $(MLX_BUILD_PATH)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -s -C ./libs/libft

fclean: clean
					@$(RM) $(NAME)
					@make fclean -s -C ./libs/libft
					@printf "\033[0;33mFiles removed successfully!\033[0m\n"

re: fclean all

.PHONY: all clean fclean re