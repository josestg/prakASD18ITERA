#include "list.cpp"

/* Gunakan Fungsi pada list.cpp tambahkan fungsi dibawah ini dan int main 
dibawah ini */
void reverseList (List *L){
	/*	I.S. L terdefinisi, boleh kosong
		F.S. Elemen list L dibalik :
		Elemen terakhir menjadi elemen pertama, dan seterusnya.
		Membalik elemen list, tanpa melakukan alokasi/dealokasi.
	*/
	address next,curr,prev;

}

//gunakan main berikut untuk menguji output
int main(){
	List L;
	createList(&L);

	//Soal V
	int n,x;
	cin>>n;
	for (int i =0;i<n;i++){
		cin>>x;
		insertLast(&L,x);
	}
	reverseList(&L);
	printInfo(L);
	
}
