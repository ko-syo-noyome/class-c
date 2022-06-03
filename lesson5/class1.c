#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define ELEMENT_T int

struct Link{
    ELEMENT_T data;
    struct Link *next;
};

struct Link *newLink(data,next){
    struct Link *link=malloc(sizeof( *Link));
    link->data=data;
    link->next=next;
    return link;
};

int main(){
    struct Link *link=newLink(42,0);

    link=newLink(123,link);
    link=newLink(456,link);
    link=newLink(777,link);
    link=newLink(1001,link);
    link=newLink(101010,link);
    //link=newLink(123,link);

    while(link){
        printf("%i\n",link->data);
        link=link->data;
    }
    // printf("%i\n",link->data);
    // printf("%i\n",link->next->data);
    // printf("%i\n",link->next->next->data);
    // printf("%i\n",link->next->next->next->data);
    // printf("%i\n",link->next->next->next->next->data);
    //printf("%i\n",link->next->next->next->next->data);



    return 0;
}