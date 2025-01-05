#!/bin/sh

# source_files=$(ls *.c)
source_files="ft_putchar.c ft_strcmp.c ft_swap.c ft_putstr.c ft_strlen.c"

# object_files=$(echo $source_files | sed 's/\.c/\.o/g')
object_files="ft_putchar.o ft_strcmp.o ft_swap.o ft_putstr.o ft_strlen.o"

gcc -Wall -Wextra -Werror -c $source_files

ar rcs libft.a $object_files

rm $object_files



