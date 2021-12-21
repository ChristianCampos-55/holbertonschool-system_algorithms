CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

SRC0 = huffman.c
NAME0 = huffman
OBJ0 = $(SRC0:.c=.o)

.PHONY: all clean oclean flcean re

all: $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)

clean:
	$(RM) *~ $(NAME0)

oclean:
	$(RM) $(OBJ0)

fclean: clean oclean

re: oclean all

huffman: $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)
