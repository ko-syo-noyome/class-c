#include <assert.h>

#define ELT_T int
#include "09-list.c"

#define Queue			List
#define newQueue()		newList()
// add more #defines here
#define Queue_isEmpty(Queue) List_isEmpty(Queue)
#define Queue_add(Queue,elt)     List_addLast(Queue, elt)
#define Queue_remove(Queue)      List_removeFirst(Queue)
#define Queue_first(Queue)   List_last(Queue)

int main(int argc, char **argv){
    
    struct Queue *queue = newQueue();

    assert(Queue_isEmpty(queue));

    for (int i = 1;  i < 10;  ++i) {
	Queue_add(queue, i*i);
	assert(!Queue_isEmpty(queue));
	assert(Queue_first(queue) == i*i);
    }

    for (int i = 1;  i < 10;  ++i) {
	assert(!Queue_isEmpty(queue));
	int j = Queue_remove(queue);
	assert(j == i*i);
    }

    assert(Queue_isEmpty(queue));

    printf("all tests passed\n");

    return 0;
}
