# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 22:09:34 by fnicolau          #+#    #+#              #
#    Updated: 2025/03/27 20:06:19 by fnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# project settings
NAME		= ft_display_file

SRC_DIR		= src
OBJ_DIR		= obj
INCLUDE_DIR	= include
FILES 		= main.c ft_display_file.c ft_putstr_fd.c

# generate paths
SRCS = $(addprefix $(SRC_DIR)/, $(FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

# compiler settings
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# commands
DELETE		= rm -rf
CHECK_DIR	= mkdir -p
CHECK_NORME	= norminette -R CheckForbiddenSourceHeader

# targets
all: $(NAME)

$(NAME): $(OBJS)
	${CC} ${CFLAGS} -I$(INCLUDE_DIR) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CHECK_DIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	$(DELETE) $(OBJS)
fclean: clean
	$(DELETE) $(NAME)
re: fclean all

norme:
	$(CHECK_NORME) $(INCLUDE_DIR)/* $(SRC_DIR)/*

.PHONY: all clean fclean re norme
