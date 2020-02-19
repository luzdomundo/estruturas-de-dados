#include "array.h"

struct array_t *array_create(void)
{
	struct array_t *array = {0};

	array = malloc(sizeof(struct array_t));
	array -> length = 1;
	array -> bytes = sizeof(TYPE) * array -> length;
	array -> data = malloc(array -> bytes);

