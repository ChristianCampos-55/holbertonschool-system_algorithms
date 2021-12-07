#include "heap.h"

/**
 * heap_create - creates a Heap data structure
 * @data_cmp: pointer to a comparison functio
 * Return: new heap or null
 */

heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *h = NULL;

	h = malloc(sizeof(*h));

	if (!h)
		return (NULL);

	h->root = NULL;
	h->size = 0;
	h->data_cmp = data_cmp;

	return (h);
}
