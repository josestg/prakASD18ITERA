/**
	Jose Sitanggang (14116125)
	PRAKTIKUM LISTLINEAR
	DEFENISI
	1. List Kosong <-> First(L) bernilai Nil
	2. P merupakan pointer ke ElementList
	3. Dikatakan Element terakhir apabila Next(P) bernilai Nil
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype 	info;
	address 	next;
} ElmtList;

typedef struct {
	address		first;
} List;


//SELEKTOR 
#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info

//KONSTANTA
#define Nil NULL
#define Infinity 99999

 

bool isListEmpty (List L){
	/* Mengirim true jika list kosong */
	return First(L) == Nil;
}

void createList (List *L){
	/*	I.S. sembarang
		F.S. Terbentuk list kosong 
	*/
	First(*L)=Nil;

}

address alokasi (infotype X){
	/*	Mengirimkan address hasil alokasi sebuah elemen
		Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
		Info(P) = X, Next(P) = Nil
		Jika alokasi gagal, mengirimkan Nil
	*/
	address P = address(malloc(sizeof(ElmtList)));
	if(P==Nil)
		return Nil;

	Info(P) = X;
	Next(P) = Nil;
	return P;
	
}

void dealokasi (address *P){
	/*	I.S. P terdefinisi
		F.S. P dikembalikan ke sistem
		Melakukan dealokasi/pengembalian address P
	*/
	free(*P);
}

void insertFirst (List *L, infotype X){
	/*	I.S. L mungkin kosong
		F.S. X ditambahkan sebagai elemen pertama L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
		nilai X jika alokasi berhasil.
		Jika alokasi gagal: I.S.= F.S.
	*/
	address P = alokasi(X);
	if(P!=Nil){
		Next(P)=First(*L);
		First(*L) = P;
	}
}

void insertAfter (List *L, address P, address Prec){
	/*	I.S. Prec pastilah elemen list dan bukan elemen terakhir,
		P sudah dialokasi
		F.S. Insert P sebagai elemen sesudah elemen beralamat Prec
	*/
	Next(P)=Next(Prec);
	Next(Prec)=P;
}

address getLast(List L){
	/*	I.S. List munking kosong,
		F.S. Menjelajah List hingga ke Last, kemudian mengembalikan
	*/
	address last = First(L);
	while(Next(last)!=Nil)
		last = Next(last);
	return last;
}

void insertLast (List *L, infotype X){
	/*	I.S. L mungkin kosong
		F.S. X ditambahkan sebagai elemen terakhir L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
		elemen terakhir yang baru bernilai X jika alokasi berhasil.
		Jika alokasi gagal: I.S.= F.S.
	*/
	address P = alokasi(X);
	if(isListEmpty(*L))
		insertFirst(L,X);
	else{
		address last = getLast(*L);
		insertAfter(L,P,last);
	}
}


/*
* Fungsi Overloading => merupakan fungsi yang memiliki nama sama
* namum memiliki parameter dan iplementasi yang berbeda.
* contoh : 
* insertFirst(List *L,address P) dan insertFirst (List *L, infotype X)
* Beberda di parameter kedua, fungsi tersebut akan otomatis memilih fungsi yang akan
* di jalankan , sesuai dengan parameter pembedanya( kedua ).
*/
void insertFirst(List *L,address P){
	/*	I.S. L mungkin kosong
		F.S. P ditambahkan sebagai elemen pertama L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
		P hasil Alokasi X.
		Jika alokasi gagal: I.S.= F.S.
	*/
	Next(P)=First(*L);
	First(*L) = P;
}

void insertLast(List *L,address P){
	/*	I.S. L mungkin kosong
		F.S. P ditambahkan sebagai elemen terakhir L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
		elemen terakhir yang baru bernilai P hasil alokasi X.
		Jika alokasi gagal: I.S.= F.S.
	*/
	if(isListEmpty(*L))
		insertFirst(L,P);
	else{
		address last = getLast(*L);
		insertAfter(L,P,last);
	}
}

void deleteFirst (List *L, infotype *X){
	/*	I.S. List L tidak kosong
		F.S. Elemen pertama list dihapus : nilai info disimpan pada X
		dan alamat elemen pertama di-dealokasi
	*/
    address P = First(*L);
    *X = Info(P);
    if (Next(P) == Nil)    // 1 element only
        createList(L);
    else{
        First(*L) = Next(P);
        Next(P) = Nil;
        dealokasi(&P);
    }

}

void deleteAfter (List *L, address *Pdel, address Prec){
	/*	I.S. List tidak kosong. Prec adalah anggota list L.
		F.S. Menghapus Next(Prec) : Pdel adalah alamat elemen list yang dihapus
	*/
	*Pdel = Next(Prec);
	if(*Pdel!=Nil) 
		Next(Prec)=Next(*Pdel);
	dealokasi(Pdel);
}

void deleteLast(List *L, infotype *X){
	/*	I.S. list tidak kosong
		F.S. Elemen terakhir list dihapus : nilai info disimpan pada X
		dan alamat elemen terakhir di-dealokasi
	*/
	
	if(Next(First(*L))==Nil){
		//one element only
		*X = Info(First(*L));
		createList(L);
	}else{
		address prev = First(*L);
		while(Next(Next(prev))!=Nil){
			prev = Next(prev);
		}
		address last =Next(prev);
		*X = Info(last);
		deleteAfter(L,&last,prev);
	}
	
}

void delAll (List *L){
/* Delete semua elemen list dan alamat elemen di-dealokasi */
	infotype temp;

	while(!isListEmpty (*L)){
		deleteFirst(L,&temp);
	}
	createList(L);
}

address search (List L, infotype X){
	/*	Mencari apakah ada elemen list dengan Info(P) = X
		Jika ada, mengirimkan address elemen tersebut
		Jika tidak ada, mengirimkan Nil
	*/
	address P = First(L);
	while(P!=Nil){
		if(Info(P)==X)
			return P;
		P = Next(P);
	}
	return Nil;
			
}

bool searchAddress (List L, address P){
	/*	Mencari apakah ada elemen list yang beralamat P
		Mengirimkan true jika ada, false jika tidak ada
	*/
	address CP = First(L);
	while(CP!=Nil){
		if(CP==P) return true;
		CP=Next(CP);
	}

}


void printInfo (List L){
	/*	I.S. List mungkin kosong
		F.S. Jika list tidak kosong,
		Semua info yg disimpan pada elemen list diprint dengan format [elemen-1, elemen-2, elemen-3, ...]
		Jika list kosong, hanya menuliskan "[]"
	*/
	cout<<"[";
	if(!isListEmpty(L)){
		address P = First(L);
		while(Next(P)!=Nil){
			cout<<Info(P)<<", ";
			P = Next(P);
		}
		cout<<Info(P);
	}
	cout<<"]"<<endl;
}

int nbElmt (List L){
	/*	Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
	int count = 0;
	address P = First(L);
	while(P!=Nil){
		count++;
		P=Next(P);
	}
	return count;
		
}

// Prekondisi untuk Max/Min/rata-rata : List tidak kosong 
infotype max (List L){
	/*	Mengirimkan nilai Info(P) yang maksimum */
	int max = -Infinity;
	address P = First(L);
	while(P!=Nil){
		if(max<Info(P))
			max = Info(P);
		P=Next(P);
	}
	return max;
}


address adrMax (List L){
	/*	Mengirimkan address P, dengan Info(P) yang bernilai maksimum */
	return search(L,max(L));
}

infotype min (List L){
	/*	Mengirimkan nilai Info(P) yang minimum */
	int min = Infinity;
	address P = First(L);
	while(P!=Nil){
		if(min>Info(P))
			min = Info(P);
		P=Next(P);
	}
	return min;
}

address adrMin (List L){
	/*	Mengirimkan address P, dengan Info(P) yang bernilai minimum */
	return search(L,min(L));
}

void reverseList (List *L){
	/*	I.S. L terdefinisi, boleh kosong
		F.S. Elemen list L dibalik :
		Elemen terakhir menjadi elemen pertama, dan seterusnya.
		Membalik elemen list, tanpa melakukan alokasi/dealokasi.
	*/
	address next,curr,prev;
	curr = First(*L);
	prev = Nil;
	while(curr!=Nil){
		next = Next(curr);
		Next(curr)=prev;
		prev = curr;
		curr = next;
	}
	First(*L) = prev;
}

void copyList (List *L1, List *L2){
	/*	I.S. L1 terdefinisi, L2 sembarang. F.S. L2 = L1
		L1 dan L2 "menunjuk" kepada list yang sama.
		Tidak ada alokasi/dealokasi elemen baru.
	*/
	First(*L2)=First(*L1);
}

List makeCopyList(List L){
	/*	I.S. L1 terdefinisi, L2 sembarang. F.S. L2 = L1
		L1 dan L2 "tidak menunjuk" kepada list yang sama.
		Ada alokasi/dealokasi elemen baru.
	*/
	List Lcopy;
	createList(&Lcopy);

	address curr = First(L);
	address curr_cp;


	while(curr!=Nil){
		curr_cp = alokasi(Info(curr));
		if(curr_cp==Nil){
			delAll(&Lcopy);
			break;
		}
		insertLast(&Lcopy,curr_cp);
		curr = Next(curr);
	}
	return Lcopy;
}


int main(){
	List L;
	createList(&L);

	//Soal 4
	int n,x;
	cin>>n;
	for (int i =0;i<n;i++){
		insertLast(&L,i);
	}
	printInfo(L);
	cout<<"REVERSE LIST"<<endl;
	reverseList(&L);
	printInfo(L);
	while(!isListEmpty(L)){
		deleteLast(&L,&x);
	}

	
}

