# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 18:25:53 by fnicolau          #+#    #+#              #
#    Updated: 2025/04/25 18:36:33 by fnicolau         ###   ########.fr        #
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
H_FILES	= ft_hexdump.h
SRCS	= $(addprefix $(SRC_DIR)/, $(FILES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(FILES:%.c=%.o))
HEADERS	= $(addprefix $(INC_DIR)/, $(HEADER_FILES))

# compiler settings
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# commands
DELETE		= rm -rf
MAKE_DIR	= mkdir -p
NORME		= norminette
ASSEMBLY	= $(CC) $(CFLAGS) -I $(HEADERS)

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
	$(NORME)

.PHONY: all clean fclean re norme
