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

//gunakan main berikut untuk menguji output
int main(){
	List L;
	createList(&L);

	int n,x;
	cin>>n;
	for (int i =0;i<n;i++){
		cin>>x;
		insertLast(&L,x);
	}
	reverseList(&L);
	printInfo(L);
	
}
