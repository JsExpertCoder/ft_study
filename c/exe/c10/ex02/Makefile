# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 16:07:02 by fnicolau          #+#    #+#              #
#    Updated: 2025/04/20 20:31:06 by fnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# project settings
NAME	= ft_tail

# directories settings
SRC_DIR	= src
OBJ_DIR = obj
INC_DIR	= include

# file settings
FILES	= main.c ft_putstr_fd.c ft_putchar_fd.c option_parser.c ft_tail.c \
		  ft_strncmp.c ft_strcmp.c print_error.c ft_strlen.c ft_atoi.c    \
		  ft_strcpy.c files_parses.c
		  
SRCS	= $(addprefix $(SRC_DIR)/, $(FILES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

# compiler settings
CC		= gcc
CFLAGS	=  -Wall -Wextra -Werror

# commands
DELETE		= rm -rf
LINKING		= $(CC) $(CFLAGS) -I $(INC_DIR) -o
ASSEMBLY	= $(CC) $(CFLAGS) -I $(INC_DIR) -c
MAKE_DIR	= mkdir -p
CHECK_NORME	= norminette
TEST		= tests/test_ft_tail.sh

# targets
all: $(NAME)

$(NAME): $(OBJS)
	$(LINKING) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MAKE_DIR) $(OBJ_DIR)
	$(ASSEMBLY) $< -o $@

clean:
	$(DELETE) $(OBJS)

fclean: clean
	$(DELETE) $(NAME)

re: $(fclean) all

run:
	@./$(NAME)

norme:
	$(CHECK_NORME)

tests:
	$(TEST)

.PHONY: all clean fclean re run norme tests