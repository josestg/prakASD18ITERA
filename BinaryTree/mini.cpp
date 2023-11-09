#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int Infotype;
typedef struct tnode* Addrnode;
typedef struct tnode 
{ 
    Infotype info; 
    Addrnode left,right;
}Node;
typedef Addrnode Bintree;

//SELECTOR
#define $root(node) (node)->info
#define $right(node) (node)->right
#define $left(node) (node)->left
#define empty(node) (node==NULL)
   
Addrnode allocNode(Infotype val) 
{ 
    Addrnode new_node =  (Addrnode )malloc(sizeof(Node)); 
    $root(new_node)= val; 
    $left(new_node) = $right(new_node) = NULL; 
    return new_node; 
} 
void makeTree(Bintree *T,Infotype val){*T=allocNode(val);}
void printInorder(Addrnode p);
Infotype getClosestNeighbor();
Addrnode insert(Addrnode *p, Infotype val);
   
int main() 
{ 
    
    Bintree root;
    makeTree(&root,50);
    insert(&root, 30); 
    insert(&root, 20); 
    insert(&root, 40); 
    insert(&root, 70); 
    insert(&root, 60); 
    insert(&root, 40); 
    insert(&root, 80); 
    insert(&root, 60); 

    printInorder(root);
    return 0; 
}