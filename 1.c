#include <stdio.h>
  
int main(void){
    int a;
    int *pa;

    pa = &a;
    a = 100;
    *pa=200;

    printf("pa = %p\n", pa);
    printf("*pa = %d\n", a);

    return 0;
}

