#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define swap(A,B) {int tmp=A,A=B,B=temp;} while (0)

void bubbleSort(int array[], int left, int right)
{
    while(left<right){
        int i=left;

        while(i<right){
            if(!(array[i]<= array[i+1]))
                swap(array[i],array[i+1]);
            
            ++i;
        }
        for(int j=left ; j<=right ; ++j)
            printf("%i",array[j]);
        putchar('/');
        --right;

    }
}

void selectionSort(int array[], int left, int right)
{
    while(left<right){
        int minIndex=left;
        for (int i=left+1;i<=right;++i){
            if(!(array[minIndex]<= array[i])){
                minIndex=i;

            }
            swap(array[left],array[minIndex]);
            left=left+1;

        }
    }
}

void insertionSort(int array[], int left, int right)
{
    
}

void quickSort(int array[], int left, int right)
{
}

#include <sys/time.h>

unsigned long millis(void)
{
    struct timeval tv;
    static unsigned long epoch = 0;
    gettimeofday(&tv, 0);
    if (!epoch) epoch = tv.tv_sec * 1000L + tv.tv_usec / 1000;
    return tv.tv_sec * 1000L + tv.tv_usec / 1000 - epoch;
}

void fill(int array[], int left, int right)
{
    for (int i = left;  i <= right;  ++i)
	array[i] = rand() & 4095; // random number in the range [0..4095]
}

#define NMAX 20 // increase to maximum required number of elements in the array

int array[NMAX];

int main(int argc, char **argv)
{
    // fill array with NMAX random numbers
    fill(array, 0, NMAX - 1);

    // sort the contents
    selectionSort(array, 0, NMAX - 1);

    // verify the contents are sorted
    for (int i = 1;  i < NMAX;  ++i)
	assert(array[i-1] <= array[i]);

    puts("all tests passed");

    return 0;
}
