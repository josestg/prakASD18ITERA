
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*** Definisi Type Pohon Biner ***/
typedef struct tNode *paddress;
typedef struct tNode {
	infotype Info;
	paddress Left;
	paddress Right;
} node;
typedef paddress BinTree;

/*** Definisi Type List of Node ***/
typedef List ListOfNode;

/*** Selektor ***/
#define Akar(P) (P)->Info
//Mengirimkan nilai Akar pohon biner P
#define Left(P) (P)->Left
//Mengirimkan Anak Kiri pohon biner P
#define Right(P) (P)->Right
//Mengirimkan Anak Kanan pohon biner P

/***********************ADT POHON BINER********************************/
/*** Konstruktor ***/
void Allocate (paddress *P)
{
	//Kamus Lokal
	
	//Algoritma
	*P =(paddress) malloc(sizeof(node));
}

BinTree Tree (infotype A, BinTree L, BinTree R)
//Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil
//Menghasilkan pohon kosong (Nil) jika alokasi gagal
{
	//Kamus Lokal
	paddress P;
	//Algoritma
	Allocate (&P);
	if (P!=Nil) {
		Akar(P) = A;
		Left(P) = L;
		Right(P) = R;
	}
	return P;
}
void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P)
//I.S. Sembarang 
//F.S. Menghasilkan sebuah pohon P 
//Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil 
//Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal 
{
	//Kamus Lokal
	
	//Algoritma
	Allocate(P);
	if (*P!=Nil) {
		Akar(*P)=Akar;
		Left(*P) = L;
		Right(*P) = R;
	} 
}


/*** Predikat-Predikat Penting ***/
bool IsTreeEmpty (BinTree P)
//Mengirimkan true jika P adalah pohon biner kosong
{
	//Kamus Lokal
	
	//Algoritma
	return (P==Nil);
}
bool IsOneElmt (BinTree P)
//Mengirimkan true jika P adalah pohon biner tidak kosong dan
//hanya memiliki 1 elemen
{
	//Kamus Lokal
	
	//Algoritma
	return ((!IsTreeEmpty(P))&&(IsTreeEmpty(Left(P)))&&(IsTreeEmpty(Left(P))));
}
bool IsUnerLeft (BinTree P)
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon unerleft: hanya mempunyai subpohon kiri
{
	//Kamus Lokal
	
	//Algoritma
	return ((Right(P) == Nil) && (Left(P) != Nil));
}
bool IsUnerRight (BinTree P)
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon unerright: hanya mempunyai subpohon kanan
{
	//Kamus Lokal
	
	//Algoritma
	return ((Right(P) != Nil) && (Left(P) == Nil));
}
bool IsBiner (BinTree P)
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon biner: mempunyai subpohon kiri dan subpohon kanan
{
	//Kamus Lokal
	
	//Algoritma
	return ((Right(P) != Nil) && (Left(P) != Nil));
}

/*** Traversal ***/
void PrintPreorder (BinTree P)
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon
//kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
{
	//Kamus Lokal
	
	//Algoritma
	if (P!=Nil)  {
		printf("%d\n", Akar(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
	}
}
void PrintInorder (BinTree P)
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon
//kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
{
	//Kamus Lokal
	
	//Algoritma
	if (P!=Nil)  {
		PrintInorder(Left(P));
		printf("%d\n", Akar(P));
		PrintInorder(Right(P));
	}
}
void PrintPostorder (BinTree P)
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan
//akar. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
{
	//Kamus Lokal
	
	//Algoritma
	if (P!=Nil)  {
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("%d\n", Akar(P));
	}
}
void PrintSpasi(int h) 
{
	//Kamus Lokal
	int i;
	//Algoritma
	for (i=1; i<=h; i++) {
		printf(" ");
	}
}
void PrintTree (BinTree P, int h, int hc)
//I.S. P terdefinisi, h adalah jarak indentasi
//F.S. Semua simpul P sudah ditulis dengan indentasi
{
	//Kamus Lokal
	
	//Algoritma
	if (!IsTreeEmpty(P)) {
		printf("%d", Akar(P));
		if (!IsTreeEmpty(Left(P))) {
			PrintSpasi(hc+h);
			PrintTree(Left(P), h, hc+h);
		}
		if (!IsTreeEmpty(Right(P))) {
			PrintSpasi(hc+h);
			PrintTree(Right(P), h, hc);
		}
	}
}
/*** Searching ***/
bool SearchPB (BinTree P, infotype X)
//Mengirimkan true jika ada node dari P yang bernilai X
{
	//Kamus Lokal
	
	//Algoritma
	if (IsTreeEmpty(P)) {
		return false;
	}
		if (X==Akar(P)) {
			return true;
		}
		else {
			return (SearchPB(Left(P), X) || SearchPB(Right(P), X));
		}
}
/*** Fungsi-Fungsi Lain ***/
int NbElmtPB (BinTree P)
//Mengirimkan banyaknya elemen (node) pohon biner P
{
	//Kamus Lokal
	
	//Algoritma
	if (IsTreeEmpty(P)) {
		return 0;
	}
	else {
		return 1+NbElmtPB(Left(P))+NbElmtPB(Right(P));
	}
}
int NbDaun (BinTree P)
//Mengirimkan banyaknya daun (node) pohon biner P
{
	//Kamus Lokal
	
	//Algoritma
	if ((Left(P)==Nil)&&(Right(P)==Nil)) {
		return 1;
	}
	else {
		if ((Left(P)!=Nil)&&(Right(P)==Nil)) {
			return NbDaun(Left(P));
		}
		else if ((Left(P)==Nil)&&(Right(P)!=Nil)) {
			return NbDaun(Right(P));
		}
		else if ((Left(P)!=Nil)&&(Right(P)!=Nil)) {
			return NbDaun(Left(P))+NbDaun(Right(P));
		}
	}
}
bool IsSkewLeft (BinTree P)
//Mengirimkan true jika P adalah pohon condong kiri 
{
	//Kamus Lokal
	
	//Algoritma
	if (IsTreeEmpty(P))
		return false;
	else {
		if (IsOneElmt(P)) {
			return true;
		}
		else 
			if (IsUnerLeft(P)) {
				return IsSkewLeft(Left(P));
			}
			else {
				return false;
			}
		}
}
bool IsSkewRight (BinTree P)
//Mengirimkan true jika P adalah pohon condong kiri
{
	//Kamus Lokal
	
	//Algoritma
	if (IsTreeEmpty(P))
		return false;
	else {
		if (IsOneElmt(P)) {
			return true;
		}
		else 
			if (IsUnerRight(P)) {
				return IsSkewRight(Right(P));
			}
			else {
				return false;
			}
		}
}
int Level (BinTree P, infotype X)
//Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner
//P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }
{
	//Kamus Lokal
	
	//Algoritma
	if (X==Akar(P)){
		return 1;
	}
	else 
		if (SearchPB(Left(P), X)) {
			return 1+Level(Left(P), X);
		}
		else {
			return 1+Level(Right(P), X);
		}
}
/*** Operasi lain ***/
void AddDaunTerkiri (BinTree *P, infotype X)
//I.S. P boleh kosong 
//F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri
{
	//Kamus Lokal
	paddress Pk;
	//Algoritma
	if (IsTreeEmpty(*P)) {
		printf("kosong\n");
		Allocate(P);
		if(P == Nil) printf("kosong\n");
		Akar (*P) = X;
	}
	else {
		if (IsTreeEmpty(Left(*P))) {
			Allocate(&Pk);
			Left(*P) = Pk;
			Akar (Pk) = X;
		}
		else {
			AddDaunTerkiri(&Left(*P), X);
		}
	}
}
void AddDaun (BinTree *P, infotype X, infotype Y, bool Kiri)
//I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P 
//F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
//sebagai anak Kanan X (jika Kiri = false) 
{
	//Kamus Lokal
	paddress Pk;
	//Algoritma
	if (X==Akar(*P)) {
		Allocate(&Pk);
		Akar(Pk) = Y;
		if (Kiri) {
			Left(*P) = Pk;
		}
		else {
			Right(*P) = Pk;
		}
	}
	else {
		if (SearchPB(Left(*P), X)) {
			AddDaun(&Left(*P), X, Y, Kiri);
		}
		else {
			AddDaun(&Right(*P),X,Y,Kiri);
		}
	}
}
void DelDaunTerkiri (BinTree *P, infotype *X)
//I.S. P tidak kosong 
//F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
//disimpan pada daun terkiri yang dihapus 
{
	//Kamus Lokal
	
	//Algoritma
	if (Left(*P)==Nil) {
		if (Right(*P)==Nil) {
			(*X) = Akar(*P);
			(*P) = Nil;
			free(*P);
		}
		else {
			DelDaunTerkiri(&Right(*P), X);
		}
	}
	else {
		DelDaunTerkiri(&Left(*P), X);
	}
}
void DelDaun (BinTree *P, infotype X)
//I.S. P tidak kosong, X adalah salah satu daun 
//F.S. Semua daun bernilai X dihapus dari P 
{
	//Kamus Lokal
	
	//Algoritma
	if ((X==Akar(*P))&&(IsOneElmt(*P))) {
		free(*P);
	}
	else {
		if (SearchPB(Left(*P), X)) {
			DelDaun(&Left(*P), X);
		}
		if (SearchPB(Right(*P), X)) {
			DelDaun(&Right(*P), X);
		}
	}
}

/*** Balanced tree ***/
BinTree BuildBalanceTree (int n)
//Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca
{
	//Kamus Lokal
	paddress P;
	int nL, nR;
	infotype X;
	BinTree R, L;
	//Algoritma
	if (n==0) {
		return Nil;
	}
	else {
		scanf("%d", &X);
		Allocate(&P);
		if (P!=Nil) {
			Akar(P) = X;
			nL = n/2; nR = n-nL-1;
			L = BuildBalanceTree(nL);
			R = BuildBalanceTree(nR);
			Left(P) = L; 
			Right(P) = R;
		}
		return P;
	}
}
/*** Binary Search Tree ***/
bool BSearch (BinTree P, infotype X);
//Mengirimkan true jika ada node dari P yang bernilai X

BinTree InsSearch (BinTree P, infotype X)
//Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. 
//Belum ada simpul P yang bernilai X.
{
	//Kamus Lokal
	BinTree Pout;
	
	//Algoritma
	if (IsTreeEmpty(P)) {
		MakeTree(X, Nil, Nil, &Pout);
	}
	else {
		if (X>Akar(P)) {
			Pout = InsSearch(Right(P), X);
		}
		else if (X<Akar(P)) {
			Pout = InsSearch(Left(P),X);
		}
	}
	return Pout;
}
void DelBtree (BinTree *P, infotype X)
//I.S. Pohon P tidak kosong 
//F.S. Nilai X yang dihapus pasti ada 
//Sebuah node dengan nilai X dihapus 
{
	//Kamus Lokal
	paddress q;
	//Algoritma
	if (X<Akar(*P)) {
		DelBtree(&Left(*P), X);
	}
	else if (X>Akar(*P)) {
		DelBtree(&Right(*P),X);
	}
	else if (X==Akar(*P)) {
		q = Tree(Akar(*P), Left(*P), Right(*P));
		if (Right(q) == Nil) {
			(*P) = Left(q);
		}
		else if (Left(q)==Nil) {
			(*P) = Right(q);
		}
		else {
			DelNode(&Left(q));
			free(&q);
		}
	}
}


void DelNode (BinTree *P) {
	//Kamus Lokal
	paddress q;
	//Algoritma
	if (Right(*P)!=Nil) {
		DelNode(&Right(*P));
	}
	else {
		q = *P;
		*P = Left(*P);
	}
}
