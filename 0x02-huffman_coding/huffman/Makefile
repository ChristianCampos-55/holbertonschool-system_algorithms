CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

SRC0 = comp_decomp.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = huffman


.PHONY: all clean oclean flcean re


all: $(OBJ0)
	$(CC) $(OBJ0) -o huffman


clean:
	$(RM) *~ huffman


oclean:
	$(RM) $(OBJ0)


fclean: clean oclean


re: oclean all


comp_decomp: $(OBJ0)
	$(CC) $(OBJ0) -o huffman
