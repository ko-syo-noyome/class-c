#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


// void copyI0(void){
//     int c;
//     while(EOF != getchar()){
//         swhitch(c){
//             case ' ':{
//                 printf("%%%02X",c);
//                 continue;
//             }
//         }
//         putchar(c);
//     }
// }



// void copyID(void){
//     int c;
//     while(EOF !=(c=getchar())){
//         if (c != '%'){
//             putchar(c);
//             continue;
//         }
//         int d=getchar();
//         if (!(isxdigit(d))) continue;
//         int e=getchar();
//         if (!(isxdigit(e))) continue;
//         if (d> '9') d-= 7;
//         if (e> '0') e-=7;
//         c=(d-'0')*16+(e-'0');
//         putchar(c);
//     }
// }

// int buffer=0;
// int count=0;


// void recvByte(int c){
//     for(int n=8; --n>=0;){
//         buffer <<= 1;
//         buffer |= (c>> n) & 1;
//         count++;

//         if (count==8){
//             print2(buffer);
//             printf("\n");
//             buffer==count=0;
//         }
//     }
    
// }


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