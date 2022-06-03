#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ELEMENT_T int

struct Tree *Tree_search(struct Tree *root, ELEMENT_T e){
    if (root==0) return 0;
    if(e==root->data) return root;

    if(e< root->data)
        return Tree_search(root->left ,e);
    
    return Tree_search(root->right,e);


    //
    if (root==0) return 0;
    if(e==root->data) 
    return (e < root->data)
        ?Tree_search(root->left,e);
        :Tree_search(root->right,e);
    
    

}


struct Tree *Tree_insert(struct Tree **rootp, ELEMENT_T e){
    struct Tree *root=*rootp;
    if (root==0){
        
        return *rootp=newTree(e,0,0);
    }
    if(e==root->data) 
    return (e < root->data)
        ?Tree_insert(root->left,e);
        :Tree_insert(root->right,e);

    //
    struct Tree *root=*rootp;
    if (root==0){    
        return *rootp=newTree(e,0,0);
    }
    if(e==root->data) return Tree_insert(root->left,e);
    if (e < root->data)
        return Tree_insert(root->right,e);
}


int main(){


    printf("%p %p",t,Tree_search(t,2));
    printf("%d",);
    return 0;
}


