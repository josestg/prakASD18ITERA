#include "list.cpp"

infotype max (List L){
	/*	Mengirimkan nilai Info(P) yang maksimum */
	int max = -Infinity;
	address P = First(L);
	while(...(22)...){
		if(max<Info(P))
			...(23)...
		P=Next(P);
	}
	return max;
}

infotype min (List L){
	/*	Mengirimkan nilai Info(P) yang minimum */
	int min = Infinity;
	address P = ...(25)...
	while(P!=Nil){
		if(min>Info(P))
			...(26)...
		P=Next(P);
	}
	return min;
}

int main(){
	List L;
	createList(&L);

	//Soal C
	int n,x;
	cin>>n;
	for (int i =0;i<n;i++){
		cin>>x;
		insertLast(&L,x);
	}
	
	cout<<max(L)<<endl;
	cout<<min(L)<<endl;
}