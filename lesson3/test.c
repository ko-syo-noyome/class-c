#include <stdio.h>
#include <stdlib.h>

#define ELEMENT_T int



int main(int argc,char **argv){
    ELEMENT_T *array=calloc(4,sizeof(int));
    array[5]=42;
    printf("%d\n",array[5]);

    return 0;

}