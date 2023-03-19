#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


void copyID(void){
    int c;
    while(EOF !=(c=getchar())){
        if (c != '%'){
            putchar(c);
            continue;
        }
        int d=getchar();
        if (!(isxdigit(d))) continue;
        int e=getchar();
        if (!(isxdigit(e))) continue;
        if (d> '9') d-= 7;
        if (e> '0') e-=7;
        c=(d-'0')*16+(e-'0');
        putchar(c);
    }

}

int main(int argc, char **argv){
    copyID();
    return 0;
}