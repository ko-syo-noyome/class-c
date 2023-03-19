#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void print2(unsigned long n){
    if (n>=2)print2(n/2);
    putchar('0'+n%2);
}

unsigned long gray2bin(unsigned long value){
    unsigned long result = 0; 
    while(value){
        result^=value;
        value >>=1;
    }
    return result;
}

unsigned long bin2gray(unsigned long value){
    return value ^ (value>>1);

}

int main(int argc, char **argv){

    assert(bin2gray(0b10001000) == 0b11001100);
    assert(gray2bin(0b11001100) == 0b10001000);
    for (unsigned long bin1 = 0; bin1 < 256; ++bin1) {
        unsigned long gray = bin2gray(bin1);
        unsigned long bin2 = gray2bin(gray);
        print2(bin1); printf(" -> ");
        print2(gray); printf(" -> ");
        print2(bin2); printf("\n");
        assert(bin1 == bin2);
    }
return 0;
}


// int main(int argc,char argv){
//     printf('kuas');
//     assert(gina2gray(0000f))
// }