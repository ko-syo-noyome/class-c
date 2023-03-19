#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int buffer=0;
int count=0;
char table[64]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void recvByte(int c){
    for(int n=8; --n >=0;){
        buffer <<= 1;
        buffer |= (c>> n) & 1;
        count++;

        if (count==6){
            putchar(table[buffer]);
            buffer=count=0;
        }
    }
}

void copyID(void){
    int c;
    while(EOF !=(c=getchar())){
        recvByte(c);
    }
    printf("\n");
}

int main(int argc, char **argv){
    copyID();
    return 0;
}