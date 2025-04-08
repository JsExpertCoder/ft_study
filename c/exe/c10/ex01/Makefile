# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 15:31:53 by fnicolau          #+#    #+#              #
#    Updated: 2025/04/08 16:23:17 by fnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# project settings
NAME	= ft_cat

# directories settings
SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= include

# file path settings
FILES	= main.c ft_putstr_fd.c ft_putchar_fd.c
SRCS	= $(addprefix $(SRC_DIR)/, $(FILES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

# compiler settings
CC			= gcc
MAKE_DIR	= mkdir -p
CFLAGS		=  -Wall -Wextra -Werror
ASSEMBLY	= $(CC) $(CFLAGS) -I$(INC_DIR) -c

# commands
DELETE		= rm -rf
CHECK_NORME	= norminette

# targets
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJS) -o $@

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
