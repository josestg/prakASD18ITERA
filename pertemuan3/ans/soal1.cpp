#include "list.cpp"

/* Pakai Fungsi-Fungsi yang ada di list.cpp 
dan tambahkan int main dibawah */
int main(){
	List L;
	createList(&L);

	//Soal A
	int n,x;
	cin>>n;
	for (int i =0;i<n;i++){
		cin>>x;	
		insertFirst(&L,x);
		insertLast(&L,x);
	}
	printInfo(L);
	
	return 0;
}
