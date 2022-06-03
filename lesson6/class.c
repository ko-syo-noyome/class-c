#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Tree {
    ELEMENT_T data;
    struct Tree *left;
    struct Tree *right;
}

struct Tree *newTree(ELEMENT_T e)



void visit(struct Tree *tree){

    if (tree == 0) return;
    printf("(");
    print(tree->data); // operator name <- before children
    visit(tree->left); // first operand
    visit(tree->right); // second operand
    printf(")");
}

void Tree_applyPreOrder(struct Tree *tree, void (*fn)(ELEMENT_T e))
{
    if (0 == tree) return;
    fn(tree->data);
    Tree_applyPreOrder(tree->left, fn);
    Tree_applyPreOrder(tree->right, fn);
}



Tree_applyinOrder(struct Tree *tree ,coid (*fn)(ELEMENT_T e)){
    if (0==tree)return;
    Tree_applyinOrder(tree->left,fn);
    fn(tree->data);
    Tree_applyinOrder(tree->right,fn);

}






void printInt(int i){
    printf("%i",i);
}

int main(int argc,int argv){

    struct Tree *t=newTree(4,newTree(1,0,0),newTree(3,0,0));

    Tree_applyPreOrder(t,printInt);
    putchar('\n');

    //printf("%d\n",1);
    return 0;
}