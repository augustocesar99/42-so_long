# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 11:19:15 by acesar-m          #+#    #+#              #
#    Updated: 2025/03/19 11:14:02 by acesar-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I$(INC)
XFLAGS =  -lmlx -lXext -lX11
RM = rm -f

INC = ./include
LIBFT = ./libs/libft
MLX := ./libs/minilibx

GREEN=\033[0;32m
YELLOW=\033[0;33m
RESET=\033[0m

FILES = srcs/so_long.c srcs/valid.c srcs/valid_map_draw.c \
		srcs/valid_map_draw2.c srcs/exit.c srcs/map_memory.c \
		srcs/game_init.c srcs/take_sprites.c srcs/fill_map.c \
		srcs/put_images.c srcs/gameplay.c srcs/steps.c \
		srcs/ending_animation.c srcs/free_images.c
OBJS = $(FILES:.c=.o)

BONUS_FILES = srcs/so_long.c srcs/valid.c srcs/valid_map_draw.c \
		srcs/valid_map_draw2_bonus.c srcs/exit.c srcs/map_memory.c \
		srcs/game_init.c srcs/take_sprites.c srcs/fill_map.c \
		srcs/put_images.c srcs/gameplay.c srcs/steps.c \
		srcs/ending_animation.c srcs/free_images.c
BONUS_OBJS = $(BONUS_FILES:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -s -C $(LIBFT)
	@make -s -C $(MLX) > /dev/null 2>&1
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -L$(MLX) -o $(NAME) $(XFLAGS) > /dev/null 2>&1
	@printf "$(GREEN)Success!$(RESET)\n"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	@make -s -C $(LIBFT) > /dev/null
	@make -s -C $(MLX) > /dev/null 2>&1
	@$(CC) $(BONUS_OBJS) $(CFLAGS) $(LIBFT)/libft.a -L$(MLX) -o $(NAME_BONUS) $(XFLAGS) > /dev/null 2>&1
	@printf "$(GREEN)Success!$(RESET)\n"
	
clean:
	@make clean -C $(LIBFT) > /dev/null
	@make clean -C $(MLX) > /dev/null 2>&1
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make fclean -C $(LIBFT) > /dev/null
	@$(RM) $(NAME) $(NAME_BONUS)
	@printf "$(YELLOW)fclean Success!$(RESET)\n"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus