#ifndef __STACK_H
#define __STACK_H

#include <stdlib.h>

#define MEM_EXPONENT 2
#define TYPE __uint32_t

struct stack_t {
	size_t bytes;
	size_t length;
	TYPE *data;
};

struct stack_t *stack_create(void);
void stack_pop(struct stack_t *stack);
void stack_push(struct stack_t *stack, TYPE data);
TYPE stack_top(const struct stack_t *stack);
void stack_clear(struct stack_t *stack);
void stack_free(struct stack_t *stack);

#endif
