#include <stdio.h>
#include <stdlib.h>

#define ELEMENT_T int

struct Array{
    size_t size;
    elt_t *elements;
}

Array_size(a){
    return a->number0fElements;
}

int main(int argc,char **argv){
    Array *a = ...;
    if (Array_size(a)==0){
        ...
    }
    printf("%d\n",1);
    return 0;

}