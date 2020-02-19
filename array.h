#ifndef __ARRAY_H
#define __ARRAY_H

#include <stdlib.h>

#define TYPE char32_t

struct array_t {
	size_t length;
	size_t bytes;
	char32_t data[];
};

struct array_t *array_create(void);
void array_traverse(struct array_t *array);
void array_insertion(struct array_t *array, size_t index, TYPE element);
void array_deletion(struct array_t *array, size_t index);
void array_search(struct array_t *array, TYPE element);
void array_update(struct array_t *array, size_t index, TYPE element);

#endif
