# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 18:25:53 by fnicolau          #+#    #+#              #
#    Updated: 2025/04/25 19:08:15 by fnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# project settings
NAME	= ft_hexdump

# directories settings
SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= include

# files path settings
FILES 	= main.c
SRCS	= $(addprefix $(SRC_DIR)/, $(FILES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(FILES:%.c=%.o))

# compiler settings
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# commands
DELETE		= rm -rf
MAKE_DIR	= mkdir -p
CHECK_NORME	= norminette
ASSEMBLY	= $(CC) $(CFLAGS) -I$(INC_DIR)

# targets
all: $(NAME)

$(NAME): $(OBJS)
	$(ASSEMBLY) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MAKE_DIR) $(OBJ_DIR)
	$(ASSEMBLY) -c $< -o $@

clean:
	$(DELETE) $(OBJS)
fclean: clean
	$(DELETE) $(NAME)
re: fclean all

norme:
	$(CHECK_NORME)

.PHONY: all clean fclean re norme
