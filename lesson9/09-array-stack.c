#include <assert.h>

#define ELT_T int

#include "09-array.c"
#define Stack			Array
#define newStack()		newArray(0)
// add more #defines here
#define Stack_isEmpty(Stack)   Array_isEmpty(Stack)
#define Stack_push(Stack,elt)  Array_append(Stack,elt)
#define Stack_pop(Stack)  Array_removeLast(Stack)
#define Stack_top(Stack)  Array_last(Stack)



int main(int argc, char **argv)
{
    struct Stack *stack = newStack();

    assert(Stack_isEmpty(stack));

    for (int i = 1;  i < 10;  ++i) {
	Stack_push(stack, i*i);
	assert(!Stack_isEmpty(stack));
	assert(Stack_top(stack) == i*i);
    }

    for (int i = 9;  i > 0;  --i) {
	assert(!Stack_isEmpty(stack));
	int j = Stack_pop(stack);
	assert(j == i*i);
    }

    assert(Stack_isEmpty(stack));

    printf("all tests passed\n");

    return 0;
}
