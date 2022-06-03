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


#define swap(A,B) {int tmp=A;A=B;B=tmp;} while (0)

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

// ssize_t Array_linSearch(struct Array *Array,ssize_t target){

//     for (size_t i = 0; i < Array->size; ++i) // check each index in the array
//         if (Array->elements[i] == target) // if the element matches
//             return i; // return index where it was found
//     return -1; // not found => negative result
// }

ssize_t Array_linSearch(struct Array *Array,char *target){
    printf("%s\n",*(Array->elements));
    
    // for (size_t i = 0; i < Array->size; ++i)
    //     if (strcmp(*(Array->elements),target)==0)
    //         return i;
    // return -1; 
}

// ssize_t Array_binSearch(struct Array *array,ssize_t target){

//     ssize_t left=0,right=array->size-1;

//     while(left<=right){
//         ssize_t mid=(left+right)/2;
//         //printf("%d\n",mid);
//         ssize_t element=array->elements[mid];
//         //printf("%d\n",elt);
//         if(target<element)right=mid-1;
//         else if(target>element)left=mid+1;
//         else if (target==element) return mid;
//     }

//     return -1; // not found => negative result
// }

void Array_insert(struct Array *array,char *element){
    Array_append(array,element);
    //printf("%d %s\n",1,*element);
    Array_linSearch(array,element);
    size_t index=array->size-1;
    while(index > 0 && strcmp(array->elements[index-1],array->elements[index])<0){
        swap(*(array->elements[index-1]),*(array->elements[index]));
        --index;
    }
}


// void insert(struct Array *array,int element){
//     append(array,element);
//     size_t index=array->size-1;
//     while(index > 0 && array->elements[index-1]>array->elements[index]){

//         swap(rray->elements[index-1],array->elements[index]);
//         --index;
//     }
// }
