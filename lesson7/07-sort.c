#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define swap(A,B) {int tmp=A;A=B;B=tmp;} while (0)

void bubbleSort(int array[], int left, int right)
{
    while(left<right){
        int i=left;
        while(i<right){
            if(!(array[i]<=array[i+1]))
                swap(array[i],array[i+1]);
            
            ++i;
        }
        --right;
    }


    //printf("%d\n",u);
}

void selectionSort(int array[], int left, int right)
{
    while(left<right){
        int min=0;
        for(int i=left;i<right;++i){
            if(!(array[min] < array[i+1])){

                min=i+1;
            }
         
        }
        if(min!=left) swap(array[min],array[left]);
        ++left;
    }
}

void insertionSort(int array[], int left, int right)
{
 for(int i=left+1;i<=right;++i){
        for(int j=i;j>left;--j){
            if(!(array[j-1]<array[j])){
                swap(array[j-1],array[j]);
                
            }
            else break;
            
        }
        
    }
}

void quickSort(int array[], int left, int right)
{
    if (right <= left) return;
    
    int pivot = array[(left + right) / 2];
    int l = left-1;
    int r = right+1;
    for (;;) {
    while (array[++l] < pivot);
    while (array[--r] > pivot); 
    if (l >= r) break; 
    int temp = array[l]; 
    array[l] = array[r]; 
    array[r] = temp;
    }
    quickSort(array, left, r);
    quickSort(array, r + 1, right); 
}

// void quickSortStrings(char *array[], int left, int right){
//     if (right <= left) return;
//     int pivot = *array[(left + right) / 2];
//     int l = left-1;
//     int r = right+1;
//     for (;;) {
//     while (*array[++l] < pivot);
//     while (*array[--r] > pivot); 
//     if (l >= r) break; 
//     int temp = *array[l]; 
//     *array[l] = *array[r]; 
//     *array[r] = temp;
//     }
//     quickSort(array, left, r);
//     quickSort(array, r + 1, right); 


// }




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

#define NMAX 40000// increase to maximum required number of elements in the array

int array[NMAX];

int main(int argc, char **argv)
{
    // fill array with NMAX random numbers
    fill(array, 0, NMAX - 1);
    //insertionSort(array, 0, NMAX - 1);
    //selectionSort(array, 0, NMAX - 1);
    //quickSort(array, 0, NMAX - 1);

    printf("%s , %s , %s, %s\n","bubbleSort","selectionSort","insertionSort","quickSort");
    for (int j=0;j<=NMAX;j=j+2000){
    int start,stop;
    fill(array, 0, j - 1);
    start=millis();
    bubbleSort(array, 0, j - 1);
    stop=millis();
    printf("%d ,",stop-start);

    fill(array, 0, j - 1);
    start=millis();
    selectionSort(array, 0, j - 1);
    stop=millis();
    printf("%d ,",stop-start);

    fill(array, 0, j - 1);
    start=millis();
    insertionSort(array, 0, j - 1);
    stop=millis();
    printf("%d ,",stop-start);

    fill(array, 0, j - 1);
    start=millis();
    quickSort(array, 0, j - 1);
    stop=millis();
    printf("%d\n",stop-start);

    }


    

    // verify the contents are sorted
    //for (int i = 1;  i < NMAX;  ++i)
    //printf("%d\n",array[i]);
    //assert(array[i-1] <= array[i]);

    // puts("all tests passed");


    // char *strings[] = {"the", "quick", "brown", "fox","jumps", "over", "the", "lazy", "dog",};

    // quickSortStrings(strings, 0, sizeof(strings) / sizeof(*strings) - 1);
    // for (int i = 0; i < sizeof(strings) / sizeof(*strings); ++i)
    //     printf("%s\n", strings[i]);

    return 0;
}
