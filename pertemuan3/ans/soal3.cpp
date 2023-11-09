#include "list.cpp"

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

int main(){
	List L;
	createList(&L);

	int n,x;
	cin>>n;
	for (int i =0;i<n;i++){
		cin>>x;
		insertLast(&L,x);
	}
	
	cout<<max(L)<<endl;
	cout<<min(L)<<endl;
}