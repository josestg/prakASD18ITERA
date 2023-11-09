/**
* Binary Tree
* Algoritma dan Struktur Data
* Author : Jose Alfredo Sitanggang
* Institut Teknologi Sumatera
*/

/*
* Literatur
* Tipe data buatan diawali dengan huruf kapital
* selector diawali dengan $
* nama fungsi camelCase
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int Infotype;
typedef struct tnode* Addrnode;
typedef struct tnode 
{ 
    Infotype info; 
    Addrnode left;
    Addrnode right; 
}Node;

typedef Addrnode Bintree;

//SELECTOR
#define $root(node) (node)->info
#define $right(node) (node)->right
#define $left(node) (node)->left
#define empty(node) (node==NULL)

 /**---------- Constructor ----------**/

/*  @init   : Sembarang
    @finish : Menghasilkan sebuah pohon biner dengan
        @successed :  l<-(v)->r
        @failed    :  NULL
*/  
Addrnode allocNode(Infotype val);
void makeTree(Bintree *T,Infotype val){
    *T=allocNode(val);
}
/**---------- Traversal Method ----------**/

/*  @init   : P terdefinisi
    @finish : Cetak semua node secara preorder : root,left,right
    @target : Setiap pohon ditandai dengan kurung buka dan tutup : () 
              Pohon kosong : ()
    @example: (A()()) sama dengan <-(A)-> atau pohon satu elemen dgn root=A.
              (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) atau (<-(B)->)<-(A)->(<-(C)->)

        @successed :  Memenuhi format
        @failed    :  void
*/
void printPreorder(Addrnode p);
/*  @init   : P terdefinisi
    @finish : Cetak semua node secara inorder : left,root,right
    @target : Setiap pohon ditandai dengan kurung buka dan tutup : () 
              Pohon kosong : ()
    @example: (()A()) sama dengan <-(A)-> atau pohon satu elemen dgn root=A.
              ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C())

        @successed :  Memenuhi format
        @failed    :  void
*/
void printInorder(Addrnode p);
/*  @init   : P terdefinisi
    @finish : Cetak semua node secara postorder : left,right,root
    @target : Setiap pohon ditandai dengan kurung buka dan tutup : () 
              Pohon kosong : ()
    @example: (()()A) sama dengan <-(A)-> atau pohon satu elemen dgn root=A.
              ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C)

        @successed :  Memenuhi format
        @failed    :  void
*/
void printPostorder(Addrnode p);


/**
* @start        : Menerima node p dengan value val
* @target       : Membuat Binary Search Tree (BST)
* @constraint   : value node di BST unik, left node < root < right node
*/
Addrnode insert(Addrnode p, Infotype val);
   

int main() 
{ 
    
    Bintree root;
    makeTree(&root,50);
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 40); 
    insert(root, 80); 
    insert(root, 60); 
   
    // printPreorder(root);
    //out : (50(30(20()())(40()()))(70(60()())(80()()))) 
    // printInorder(root);
    //out : (((()20())30(()40()))50((()60())70(()80())))
    printPostorder(root);
    //out : (((()()20)(()()40)30)((()()60)(()()80)70)50)
   
    return 0; 
}