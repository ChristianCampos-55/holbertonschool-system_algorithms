#include "huffman.h"

/**
 * symbol_create - creates a symbol_t data structure
 * @data: data to be stored in the structure
 * @freq: associated frequency of char
 * Return: a new symbol struct pointer
 */

symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *s;

	s = malloc(sizeof(symbol_t));
	if (s == NULL)
		return (NULL);
	s->data = data;
	s->freq = freq;
	return (s);
}
