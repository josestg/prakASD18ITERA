/**
* Binary Tree
* Algoritma dan Struktur Data
* Author : Jose Alfredo Sitanggang
* Institut Teknologi Sumatera
*/

/** Libraries **/
#include <iostream>
#include <stdlib.h>
using namespace std;

/** Constant variable **/

/** Custum Type **/
typedef int Infotype;
typedef struct tnode *Addrnode;
typedef struct tnode{
    Infotype info;
    Addrnode left;
    Addrnode right;
}Node;

typedef Addrnode Bintree;

/** Selector **/
#define $root(node) (node)->info
#define $left(node) (node)->left
#define $right(node) (node)->right

/**---------- Constructor ----------**/

/*  @init   : Sembarang
    @finish : Menghasilkan sebuah pohon biner dengan
        @successed :  l<-(v)->r
        @failed    :  NULL
*/
Bintree tree(Infotype v,Bintree l,Bintree r){
    Bintree new_bt = (Bintree)malloc(sizeof(Bintree));
    if(new_bt==NULL) return NULL;

    $root(new_bt)=v;
    $left(new_bt)=l;
    $right(new_bt)=r;
    return new_bt;
}

/*  @init   : V, L, R terdefinisi sedangkan P Sembarang
    @finish : Membentuk pohon P
        @successed :  P = l<-(v)->r
        @failed    :  NULL
*/
void makeTree(Infotype v,Bintree l,Bintree r, Bintree *p){
    *p=tree(v,l,r);
}

/*  @init   : V terdefenisi
    @finish : Mengirimkan node baru hasil alokasi
        @successed :  (v)
        @failed    :  NULL
*/

/**---------- Memory Management ----------**/

Addrnode allocNode(Infotype v){
    Addrnode new_node = (Addrnode)malloc(sizeof(Addrnode));
    if(new_node==NULL) return NULL;

    $root(new_node)=v;
    $left(new_node)=NULL;
    $right(new_node)=NULL;
    return new_node;
}

/*  @init   : P terdefinisi
    @finish : Mengembalikan alokasi node ke memory
        @successed :  NULL
        @failed    :  (v)
*/
void dealocNode (Addrnode p){
    free(p);
}

/**---------- Predicate Functions ----------**/

/*  @init   : P sembarang
    @finish : Melihat apakah P terdafar di memory
        @successed :  true
        @failed    :  false
*/
bool isTreeEmpty (Bintree p){
    return p!=NULL;
}
/*  @init   : P sembarang
    @finish : Mengecek apakah P = (v)
        @successed :  true
        @failed    :  false
*/
bool isSingleTree(Bintree p){
    return $left(p)==NULL and $right(p)==NULL;
}
/*  @init   : P terdefinisi
    @finish : apakah P hanya memiliki sub pohon kiri. P = <-(v)
        @successed :  true
        @failed    :  false
*/
bool isUnnerLeft(Bintree p){
    return $right(p)==NULL and $left(p)!=NULL;
}
/*  @init   : P terdefinisi
    @finish : apakah P hanya memiliki sub pohon kanan. P = (v)->
        @successed :  true
        @failed    :  false
*/
bool isUnerRight(Bintree p){
    return $left(p)==NULL and $right(p)!=NULL;
}
/*  @init   : P terdefinisi
    @finish : apakah P dua memiliki sub pohon. P = <-(v)->
        @successed :  true
        @failed    :  false
*/
bool isBiner(Bintree p){
    return $left(p)!=NULL and $right(p)!=NULL;
}

/**---------- Traversal Method ----------**/

/*  @init   : P terdefinisi
    @finish : Cetak semua node secara preorder : root,left,right
    @format : Setiap pohon ditandai dengan kurung buka dan tutup : () 
              Pohon kosong : ()
    @example: (A()()) sama dengan <-(A)-> atau pohon satu elemen dgn root=A.
              (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) atau (<-(B)->)<-(A)->(<-(C)->)

        @successed :  Memenuhi format
        @failed    :  void
*/
void printPreorder (Bintree p){
    cout<<"(";
    if(p!=NULL){
        cout<<$root(p);
        printPreorder($left(p));
        printPreorder($right(p));
    }
    cout<<")";
}
/*  @init   : P terdefinisi
    @finish : Cetak semua node secara inorder : left,root,right
    @format : Setiap pohon ditandai dengan kurung buka dan tutup : () 
              Pohon kosong : ()
    @example: (()A()) sama dengan <-(A)-> atau pohon satu elemen dgn root=A.
              ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C())

        @successed :  Memenuhi format
        @failed    :  void
*/
void printInorder(Bintree p);
/*  @init   : P terdefinisi
    @finish : Cetak semua node secara postorder : left,right,root
    @format : Setiap pohon ditandai dengan kurung buka dan tutup : () 
              Pohon kosong : ()
    @example: (()()A) sama dengan <-(A)-> atau pohon satu elemen dgn root=A.
              ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C)

        @successed :  Memenuhi format
        @failed    :  void
*/
void printPostorder(Bintree p);
/*  @init   : P terdefinisi, h jarak indentasi (spasi)
    @finish : Cetak semua node secra dengan indentasi
    @format : Penulisan akar selalu pada baris baru (diakhiri newline)
    @example: h=2, print = preorder
            1) Pohon preorder: (A()()) akan ditulis sbb:
                A
            2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
                A
                    B
                    C
            3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
            A
                B
                    D
                C
                    E

        @successed :  Memenuhi format
        @failed    :  void
*/
void printTree(Bintree p,int h);

/**---------- Searching Method ----------**/

/*  @init   : P terdefinisi
    @finish : Apakah ada x di pohon. P = <-(is v = x?)->
        @successed :  true
        @failed    :  false
*/
bool searchTree (Bintree p, Infotype x){
    if(isTreeEmpty(p)) return false;
    if($root(p)==x) return true;
    return searchTree($left(p),x) ||searchTree($right(p),x);
}

/**---------- Utility Method ----------**/

/*  @init   : P terdefinisi
    @finish : Total node yang ada di pohon. P = (1),(2),..,(n)
        @successed :  >=1
        @failed    :  0
*/
int nbNode (Bintree p){
    if(isTreeEmpty(p)) return 0;
    return 1 + nbNode($left(p)) + nbNode($right(p));
}
/*  @init   : P terdefinisi
    @finish : Total node paling bawah dari pohon.
        @successed :  >=1
        @failed    :  0
*/
int nbLeaft (Bintree p){
    if(isTreeEmpty(p)) return 0;
    if(isSingleTree(p)) return 1;
    return  nbLeaft($left(p)) + nbLeaft($right(p));
}
/*  @init   : P terdefinisi
    @finish : Apakan phon condong ke kiri P = ()<-...<-()<-()<-()
        @successed :  true
        @failed    :  false
*/
bool isSkewLeft (Bintree p){
    if(isTreeEmpty(p)) return true;
    else if(isSingleTree(p)) return true;
    else $right(p)==NULL && isSkewLeft($left(p));
}
/*  @init   : P terdefinisi
    @finish : Apakan pohon condong ke kanan P = ()->()->()->...->()
        @successed :  true
        @failed    :  false
*/
bool isSkewRight (Bintree p){
    if(isTreeEmpty(p)) return true;
    else if(isSingleTree(p)) return true;
    else $left(p)==NULL && isSkewRight($right(p));
}
/*  @init   : P terdefinisi dan tidak kosong
    @finish : Mengirim posisi level dari x
        @successed :  >=1
        @failed    :  0
*/
int level (Bintree p,Infotype x);
/*  @init   : P terdefinisi dan tidak kosong
    @finish : Mengirim tinggi  dari pohon
        @successed :  >=1
        @failed    :  0
*/
int height (Bintree p){
    if(isTreeEmpty(p)) return 0;
    else{
        int hl = height($left(p));
        int hr = height($right(p));
        return (hl>hr) ? hl+=1 : hr+=1;
    }
}
