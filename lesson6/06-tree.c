#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifdef TEST_TREE // defined if we are compiling the unit tests
# define ELEMENT_T int
#endif

#ifndef ELEMENT_T // the client program forgot to say what the element type is
# error "Tree: ELEMENT_T is not defined"
#endif

struct Tree {
    ELEMENT_T    data;   // the element stored in this node
    struct Tree *left;   // pointer to left sub-tree, or 0 if none
    struct Tree *right;  // pointer to right sub-tree, or 0 if none
};

struct Tree *newTree(ELEMENT_T e, struct Tree *left, struct Tree *right)
{
    struct Tree *tree = malloc(sizeof(struct Tree));
    tree->data  = e;
    tree->left  = left;
    tree->right = right;
    return tree;
}

void Tree_applyPreOrder(struct Tree *tree, void (*fn)(ELEMENT_T e))
{
    if (0 == tree) return;
    fn(tree->data);
    Tree_applyPreOrder(tree->left,  fn);
    Tree_applyPreOrder(tree->right, fn);
}

void Tree_applyPostOrder(struct Tree *tree, void (*fn)(ELEMENT_T e))
{
    if (0 == tree) return;
    
    Tree_applyPostOrder(tree->left, fn);
    Tree_applyPostOrder(tree->right, fn);
    fn(tree->data);
    
}

void Tree_applyInOrder(struct Tree *tree,void (*fn)(ELEMENT_T e))
{
    if (0 == tree) return;
    Tree_applyInOrder(tree->left, fn);
    fn(tree->data);
    Tree_applyInOrder(tree->right, fn); 
    
}


struct Tree *Tree_search(struct Tree *root, ELEMENT_T e){
    if (root==0) return 0;
    if(e==root->data) return root;

    if(e< root->data)
        return Tree_search(root->left ,e);
    
    return Tree_search(root->right,e);
}


// struct Tree *Tree_insert(struct Tree **rootp, ELEMENT_T e){
//     struct Tree *root=*rootp;
//     if (root==0){
        
//         return *rootp=newTree(e,0,0);
//     }
//     if(e==root->data) 
//     return (e < root->data)
//         ?Tree_insert(root->left,e)
//         :Tree_insert(root->right,e)

struct Tree *Tree_insert(struct Tree **treep, ELEMENT_T e){
    struct Tree *tree = *treep;
    if (tree==0) return 0;
    if(e==tree->data) return tree;

    if(e< tree->data)
        return Tree_insert(tree->left ,e);
    
    return Tree_insert(tree->right,e);
}

#ifdef TEST_TREE

void printInt(int i)
{
    printf(" %i", i);
}

int main(int argc, char **argv)
{
    struct Tree *t = newTree(4,
			     newTree(2, newTree(1,0,0), newTree(3,0,0)),
			     newTree(6, newTree(5,0,0), newTree(7,0,0)));

    //Tree_applyPreOrder(t,printInt);
    //Tree_applyPostOrder(t,printInt);
    //Tree_applyInOrder(t, printInt);
    

    // assert(Tree_search(t,4)==t);
    // assert(Tree_search(t,6)==t->right);
    // assert(Tree_search(t,0)==0);
    // assert(Tree_search(t,10)==0);

    assert(Tree_insert(&t, 4) == t);
    assert(Tree_insert(&t, 6) == t->right);
    assert(Tree_insert(&t, 0) == 0);
    assert(Tree_insert(&t, 10) == 0);



    // putchar('\n');
    
    // assert(t != 0);
    // assert(t->data == 4);
    // assert(t->left != 0);
    // assert(t->left->data == 2);
    // assert(t->right != 0);
    // assert(t->right->data == 6);
    // assert(t->left->left != 0);
    // assert(t->left->left -> data == 1);
    // assert(t->left->right != 0);
    // assert(t->left->right -> data == 3);
    // assert(t->right->left != 0);
    // assert(t->right->left->data == 5);
    // assert(t->right->right != 0);
    // assert(t->right->right->data == 7);
    
    // assert(t->left->left->left == 0);
    // assert(t->left->left->right == 0);
    // assert(t->left->right->right == 0);
    // assert(t->left->right->left == 0);

    // assert(t->right->right->right == 0);
    // assert(t->right->right->left == 0);
    // assert(t->right->left->right == 0);
    // assert(t->right->left->left == 0);




    return 0;
}

#endif
















