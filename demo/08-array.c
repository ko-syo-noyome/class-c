#include <stdlib.h>
#include <stdio.h>

#ifndef  ELT_T
# define ELT_T int
#endif

struct Array
{
    ELT_T *elements;	// memory containing
    size_t size;	// this many elements
};

/* make a new Array and pre-allocate enough space for size elements
 */
struct Array *newArray(size_t size)
{
    struct Array *array = malloc(sizeof(struct Array));
    array->elements = calloc(size, sizeof(ELT_T));
    array->size     = size;
    return array;
}

size_t Array_size(struct Array *array)
{
    return array->size;
}

/* print a message and exit if index is not within the bounds of the array
 */
void Array__boundsCheck(struct Array *array, size_t index)
{
    if (index >= array->size) {
	fprintf(stderr, "index %zi is out of bounds for array of size %zi\n", index, array->size);
	exit(1);
    }
}

/* return the element of the array at the given index
 */
ELT_T Array_get(struct Array *array, size_t index)
{
    Array__boundsCheck(array, index);
    return array->elements[index];
}

/* store the element into the array at the given index
 */
void Array_put(struct Array *array, size_t index, ELT_T element)
{
    Array__boundsCheck(array, index);
    array->elements[index] = element;
}

/* store the element into the array at the given index
 */
void Array_append(struct Array *array, ELT_T element)
{
    array->size += 1;
    array->elements = realloc(array->elements, sizeof(ELT_T) * array->size);
    array->elements[array->size-1] = element;
}

// linsearch(array,target){
//     for(i=0;i<array->size;++i)
//         if()
// }

// ssize_t linearSearch(int array[], size_t size, int target)
// {
//     for (size_t i = 0; i < size; ++i) // check each index in the array
//         if (array[i] == target) // if the element matches
//             return i; // return index where it was found
//     return -1; // not found => negative result
// }



ssize_t binsearch(struct Array *Array,int target){

    size_t left=0,right=array->size-1;

    while(left<=right){
        size_t mid=(left+right)/2;
        int elt=array->elements[mid];
        if(target<elt)right=mid-1;
        else if(target>elt)right=mid+1;
        else return mid;
        
    }
    return -1; // not found => negative result
}

ssize_t Array_linSearch(struct Array *Array,int target)
{
    for (size_t i = 0; i < Array->size; ++i) // check each index in the array
        if (Array->elements[i] == target) // if the element matches
            return i; // return index where it was found
    return -1; // not found => negative result
}

void insert(struct Array *array,int element){
    append(array,element);
    size_t index=array->size-1;
    while(index > 0 && array->elements[index-1]>array->elements[index]){

        swap(rray->elements[index-1],array->elements[index]);
        --index;
    }
}

printIn(struct Array *array){
    for(int i=0;i<array->size;++i)
        printf("%i",array->elements[i]);
    
    printf('\n');
}

int main(){
    struct Array *array=newArray();

    // for (int=0;i<array->size;++i){
    //     append(array,rand()&63);
    //     printIn(array);
    // }

    for(int i=0;i<10;++i)
        printf("%i %zi\n",Array_linSearch(array),i);
    

        for(int i=0;i<10;++i)
        printf("%i %zi\n",binsearch(array),i);

        int count=0;
        for(int i=0;i<10;++i)
        ssize_t index=linsearch(array,i);
        if (index=>0) count=count+1;
        //printf("%i %zi\n",binsearch(Array),i);
        printf("%d\n",count);


    
    return 0;
}
