#include <assert.h>

#define ELT_T int

#include "09-list.c"
#define Stack			List
#define newStack()		newList()
// add more #defines here
#define Stack_isEmpty(Stack)  List_isEmpty(Stack)
#define Stack_push(Stack,elt)  List_addFirst(Stack, elt)
#define Stack_pop(Stack)   List_removeFirst(Stack)
#define Stack_top(Stack)  List_first(Stack)


 

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
