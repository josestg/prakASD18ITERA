#include <iostream>
using namespace std;

bool isPrima(int x,int i = 2){
	if(x<=2) return x==2;
	if(x%i==0) return false;
	if (i*i>x) return true;

	return isPrima(x,i+1);
}

void whatIs(int *arr,int *l){
	*l-=1;
	if(*l>=0)
		(isPrima(arr[*l])) ? cout<<"Prima": cout<<"Komposit";
	else
		return;

	cout<<endl;
	whatIs(arr,l);
}

int main(){
	int arr[5] = {3,4,7,12,23};
	int l=5;
	whatIs(arr,&l);
}