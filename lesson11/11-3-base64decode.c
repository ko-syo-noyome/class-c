#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
    
int decode(int c){

  if (c >= 'A' && c <= 'Z') {
    return c - 'A';
  } else if (c >= 'a' && c <= 'z') {
    return c - 'a' + 26;
  } else if (c >= '0' && c <= '9') {
    return c - '0' + 52;
  } else if (c == '+') {
    return 62;
  } else if (c == '/') {
    return 63;
  } 
  else return '\0';
  

}

void decode_base(char *dst, char *src)
{
  unsigned int o[4];
  char *p = dst;
  size_t i;
    
  for (i = 0; src[i]; i += 4) {
    if(src[i]=='\0') break;
    o[0] = decode(src[i]);
    o[1] = decode(src[i + 1]);
    o[2] = decode(src[i + 2]);
    o[3] = decode(src[i + 3]);

    *p++ = (o[0] << 2) | ((o[1] & 0x30) >> 4);
    *p++ = ((o[1] & 0xf) << 4) | ((o[2] & 0x3c) >> 2);
    *p++ = ((o[2] & 0x3) << 6) | (o[3] & 0x3f);
  }

  *p = '\0';
}

    


int main(int argc, char **argv){    
    int c;
    char enc[1024];
    char dec[1024];
    int i=0;
    while(EOF !=(c=getchar())){
        enc[i]=c;
        ++i;
    }    
    decode_base(dec, enc);
    printf("%s\n",dec);

    return 0;
}


// void copyID(void){
//     int c;
//     char enc[1024];
//     char dec[1024];
    
//     int i=0;
//     while(EOF !=(c=getchar())){
//         //if (i<4) break;
//         enc[i]=c;
//         ++i;
//     }
//     printf("%d\n",i);
//     //printf("%s\n",enc);
//     //decode_base(dec, enc);
// //    printf("%s\n", dec);

    // for (int u=0;dec[u]!='\0';u++){
    //     putchar(dec[u]);
    // }
    // putchar('\n');  


//}

//------------------------------------------------------------------------
/*
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>




int buffer=0;
int count=0;
char table[64]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
void print2(unsigned long n){
    putchar(n);
    //if (n>=2)print2(n/2);
    //putchar('0'+n%2);
    //putchar('a'+30);

    //printf("%%%02X",n);
}

// void recvByte(int c){
//     for(int n=8; --n >=0;){
//         buffer <<= 1;
//         buffer |= (c>> n) & 1;
//         count++;

//         if (count==8){
//             //print2(buffer);
//             print2(buffer);
//             printf("\n");
//             //printf("%%%02X",c);
//             buffer=count=0;
//         }
//     }
    
    
// }
// #define BUFSIZE 128

// int decode_base64_to_6bit(int c)
// {
//   if (c >= 'A' && c <= 'Z') {
//     return c - 'A';
//   } else if (c >= 'a' && c <= 'z') {
//     return c - 'a' + 26;
//   } else if (c >= '0' && c <= '9') {
//     return c - '0' + 52;
//   } else if (c == '+') {
//     return 62;
//   } else if (c == '/') {
//     return 63;
//   } else if (c == '=') {
//     return 0;
//   } else {
//     fprintf(stderr, "Error: unknown data %d\n", c);
//     exit(1);
//   }
// }

// void decode_base64(char *dst, char *src)
// {
//   unsigned int o[4];
//   char *p = dst;
//   size_t i;

//   for (i = 0; src[i]; i += 4) {
//     o[0] = decode_base64_to_6bit(src[i]);
//     o[1] = decode_base64_to_6bit(src[i + 1]);
//     o[2] = decode_base64_to_6bit(src[i + 2]);
//     o[3] = decode_base64_to_6bit(src[i + 3]);

//     *p++ = (o[0] << 2) | ((o[1] & 0x30) >> 4);
//     *p++ = ((o[1] & 0xf) << 4) | ((o[2] & 0x3c) >> 2);
//     *p++ = ((o[2] & 0x3) << 6) | (o[3] & 0x3f);
//   }

//   *p = '\0';
// }

// void copyID(void){
//     int c;
//     char table[64]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
//     char a[1024];
//     int b=0;
//     while(EOF !=(c=getchar())){
//         int i=0;
        
//         //printf("%d\n",c);
        
//         if (c >= 'A' && c <= 'Z') {
//             b=c - 'A';
//         } else if (c >= 'a' && c <= 'z') {
//                 b=c - 'a' + 26;
//         } else if (c >= '0' && c <= '9') {
//             b= c - '0' + 52;
//         } else if (c == '+') {
//             b= 62;
//         } else if (c == '/') {
//             b= 63;
//         } else if (c == '=') {
//             b= 0;
//         }
//         //a[i]=table[b];
//         ++i;
//         printf("%s\n",table[1]);
//         //putchar(table[26]);
        
//         //decode_base64(c);
//     }
//     //printf("%s\n",a);
//     printf("\n");

// }





int main(int argc, char **argv){
    copyID();
    
    return 0;
}
*/