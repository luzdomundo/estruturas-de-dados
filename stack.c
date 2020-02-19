#include "stack.h"

struct stack_t *stack_create(void)
{
	struct stack_t *stack = 0;

	stack = malloc(sizeof(struct stack_t));
	stack -> bytes = sizeof(TYPE) * MEM_EXPONENT;
	stack -> data = malloc(stack -> bytes);
	stack -> length = 0;
	return stack;
}

void stack_pop(struct stack_t *stack)
{
	long long unsigned int lower_limit = stack -> bytes / MEM_EXPONENT;

	if(stack -> length > 0) {
		stack -> length -= 1;
	}
	if(stack -> length == lower_limit) {
		stack -> bytes = lower_limit;
		stack -> data = realloc(stack -> data, stack -> bytes);
	}
}

void stack_push(struct stack_t *stack, TYPE data)
{
	stack -> length += 1;
	if(stack -> length > stack -> bytes / sizeof(TYPE)) {
		stack -> bytes *= MEM_EXPONENT;
		stack -> data = realloc(stack -> data, stack -> bytes);
	}
	stack -> data[stack -> length - 1] = data;
}

TYPE stack_top(const struct stack_t *stack)
{
	if(stack -> length > 0) {
		return stack -> data[stack -> length - 1];
	}
	return 0;
}

void stack_clear(struct stack_t *stack)
{
	while(stack -> length > 0) {
		stack_pop(stack);
	}
}

void stack_free(struct stack_t *stack)
{
	stack_clear(stack);
	free(stack -> data);
	free(stack);
}

