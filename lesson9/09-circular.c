#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ELT_T int
#define NUM_ITEMS 8
// int quene[NUM_ITEMS];



struct Queue
{
    ELT_T  *elements;
    size_t  capacity;
    size_t  index;
    size_t  outdex;
};

struct Queue *newQueue(size_t size)
{
    struct Queue *q = calloc(1, sizeof(struct Queue));
    q->elements = malloc(sizeof(ELT_T) * size);
    q->capacity = size;
    q->index    = 0;
    q->outdex   = 0;
    return q;
}

// implement the other required functions here
// void fullCheck(coid){
//     if( (in + 1 )% NUM_ITEMS==out){
//         fprintf(stderr,"this is full\n");
//         exit(1);
//     }

// }

void fullCheck(struct Queue *queue){
    if( (queue->index + 1 )% 32==queue->outdex){
        fprintf(stderr,"this is full\n");
        exit(1);
    }
}

void Queue_add(struct Queue *queue,int ele){
    fullCheck(queue);
    queue->elements[queue->index]=ele;

    queue->index=queue->index%32;
    ++queue->index;
}

int Queue_first(struct Queue *queue){
    //printf("%d\n",queue[queue->outdex]);
    return queue->elements[queue->outdex];

}

int Queue_remove(struct Queue *queue){
    //emptycheck(queue);
    int elt;
    elt=queue->elements[queue->outdex];
    queue->elements[queue->outdex]=0;
    //queue->elements[queue->outdex]=queue->elements[queue->outdex+1];
    queue->outdex=queue->outdex%32;
    ++queue->outdex;
    return elt;
}


int Queue_isFull(struct Queue *queue){

    return (queue->index+1)%queue->capacity==queue->outdex;
}



// void emptycheck(){
//     if (in==out){
//         fprintf(stderr,"this is empty\n");
//         exit(1);
//     }
// }

int Queue_isEmpty(struct Queue *queue){

    return queue->index==queue->outdex;
}


int main(int argc, char **argv)
{
    struct Queue *queue = newQueue(32);
    assert(Queue_isEmpty(queue));

    for (int i = 1;  i < 10;  ++i) {
        Queue_add(queue, i*i);
        //printf("%d\n",queue[i]);
        assert(!Queue_isEmpty(queue));
    
    }


    for (int i = 1;  i < 10;  ++i) {
	    assert(!Queue_isEmpty(queue));
        
	    assert(Queue_first(queue) == i*i);
        
	    int j = Queue_remove(queue);
	    assert(j == i*i);
    }

    assert(Queue_isEmpty(queue));

    for (int i = 1;  i < 32;  ++i) {
        //printf("%d\n",i);
        assert(!Queue_isFull(queue));
        Queue_add(queue, i*i);
    }
    assert(Queue_isFull(queue));

    for (int i = 1;  i < 32;  ++i) {
	Queue_remove(queue);
    }
    assert(Queue_isEmpty(queue));

    printf("all tests passed\n");

    return 0;
}

