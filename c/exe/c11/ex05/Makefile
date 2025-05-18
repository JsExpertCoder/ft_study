# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 18:45:53 by fnicolau          #+#    #+#              #
#    Updated: 2025/05/18 20:37:04 by fnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# project settings
NAME = do-op

# directories settings

# files settings
SRCS = main.c utils.c compute.c
OBJS = $(SRCS:.c=.o)

# compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# commands
DELETE = rm -rf

# targets
all: $(OBJS)
	$(CC) $(CFLAGS) -include "header.h" $^ -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -include "header.h" -c $< -o $@
clean:
	$(DELETE) $(OBJS)
fclean: clean
	$(DELETE) $(NAME)
re: fclean all
.PHONY: all clean fclean re