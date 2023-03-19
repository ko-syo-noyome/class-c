#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


void copyID(void){
    int c;
    while(EOF !=(c=getchar())){
        switch(c){
            case ' ':case '/': case '?':case '(': case ')':case ':':{
                printf("%%%02X",c);
                continue;
            }
        }
    putchar(c);
    }

}

int main(int argc, char **argv){
    copyID();
    return 0;
}