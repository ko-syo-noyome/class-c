#include <stdio.h>

#define size 32

size_t hash(unsigned char *string){

    size_t h =5381;
    int c;
    while ((c=*string++)){
        h=h*33+c; //0b100001(h<<5)+h+c
        


    }
    return h;


    // size_t hash = 5381;
    // int c;
    // while ((c = *string++))
    // hash = hash * 33 + c;
    // return hash;
}

struct Assoc{
    char *key;
    int   value;
    struct Assoc *next;
};

struct newAssoc *nerAssoc(char *assoc){
    struct Assoc *a
}

struct Map *newMap(size_t){
    struct Map *mcaloc(1,sizeof(struct Map));
    m->assoc=calloc(size,sizeof(strut Assoc *));
    m->size=size;
    return m;
}

struct Map *Map_find(struct Map *map,char *key){
    size_t index = hash(key) % map->size;
    struct Assoc *assoc=map->assocs[index];
    while(assoc){
        if(!strcmp(assoc->key,key))
        //return assoc;
        assoc=assoc->next;
    }
}



int main(int argc,char **argv){

    struct Assoc *a=newAssoc("hello");

    char *array[8];

    printf("%zi\n",hash("")%8);
    printf("%zi\n",hash("hullo")%8);
    printf("%zi\n",hash("left")%8);
    printf("%zi\n",hash("low")%8);

    array[hash("")%8]="full";
    array[hash("hello")%8]="gooby";
    array[hash("left")%8]="right";
    array[hash("low")%8]="high";

    for (int i=1; i<argc;++i)
        printf("%s\t %zi\t%zi\t-> %s\n",argv[i],hash[argv[i]],hash[argv[i]],array[hash(argv[i])%8]);





    return 0;

}