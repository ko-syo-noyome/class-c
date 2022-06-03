#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define ELEMENT_T int

struct Link{
    ELEMENT_T data;
    struct Link *next;
    struct *last;

};

struct Link *newLink(data,next){
    struct Link *link=malloc(sizeof( *Link));
    link->data=data;
    link->next=next;
    return link;
};

void List_addFirst(struct Link *link,ELEMENT_T data){
    struct link *l=newLink(data,list->first);
    list->first=link;
}

struct List newList(void){
    struct List *list=malloc(sizeof(*list));

    list->first=0;
    return list;
};

int enmpy_chec(){//未完成
    if(list->first==0){
        fprintf(stderr,'this list enputy');
        exit(1);
    }

}

ELEMENT_T List_remoceFirst(struct List *list){

    
    struct Link *link=lisst->first;
    ELEMENT_T data =list->first->data;
    list->first=link->data;
    free(link);

    return data;

}

int main(){
    //struct Link *link=newLink(42,0);

    struct List *list=newList();
    List_addFirst(link,1);
    List_addFirst(link,42);
    List_addFirst(link,100);
    List_addFirst(link,4200);


    List_remoceFirst(list)
    List_remoceFirst()
    List_remoceFirst()
    List_remoceFirst()

    for (struct Link *link=list->first;link!=0;link=link->next){
        printf("%i\n",link->data);

    }



    // while(link){
    //     printf("%i\n",link->data);
    //     link=link->data;
    // }
    // printf("%i\n",link->data);
    // printf("%i\n",link->next->data);
    // printf("%i\n",link->next->next->data);
    // printf("%i\n",link->next->next->next->data);
    // printf("%i\n",link->next->next->next->next->data);
    //printf("%i\n",link->next->next->next->next->data);



    return 0;
}