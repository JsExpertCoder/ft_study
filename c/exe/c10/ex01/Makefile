# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 15:31:53 by fnicolau          #+#    #+#              #
#    Updated: 2025/04/12 16:37:29 by fnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# project settings
NAME	= ft_cat

# directories settings
SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= include

# file path settings
FILES			= main.c ft_putstr_fd.c ft_putchar_fd.c print_error.c ft_cat.c
HEADER_FILES	= ft_cat.h
SRCS	= $(addprefix $(SRC_DIR)/, $(FILES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
HEADERS	= $(addprefix $(INC_DIR)/, $(HEADER_FILES))

# compiler settings
CC			= gcc
MAKE_DIR	= mkdir -p
CFLAGS		= -Wall -Wextra -Werror
ASSEMBLY	= $(CC) $(CFLAGS) -include $(HEADERS) -c

# commands
DELETE		= rm -rf
CHECK_NORME	= norminette

# targets
all: $(NAME)

$(NAME): norme $(OBJS)
	$(CC) $(CFLAGS) -include $(HEADERS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MAKE_DIR) $(OBJ_DIR)
	$(ASSEMBLY) $< -o $@

clean:
	$(DELETE) $(OBJS)

fclean: clean
	$(DELETE) $(NAME)

re: fclean all

norme:
	$(CHECK_NORME)

.PHONY: all clean fclean re norme