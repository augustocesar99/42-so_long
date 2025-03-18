# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 15:39:16 by acesar-m          #+#    #+#              #
#    Updated: 2025/03/18 15:39:18 by acesar-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../include
RM = rm -f
FILES = ft_strlen.c ft_strjoin.c ft_strchr.c ft_strncmp.c get_next_line.c \
			ft_printf.c print_char.c print_str.c print_ptr.c print_nbr.c \
			print_unint.c print_hex.c ft_itoa.c
OBJS = $(FILES:.c=.o)

all: $(NAME)
	@echo "libft is ready!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re