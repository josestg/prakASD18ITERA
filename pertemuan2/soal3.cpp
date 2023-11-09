#include <iostream>
using namespace std;

void deretGanjil(int *x,int *i){

	if(*x-*i<=0){
		cout<<*x;
		if(*x-*i<0) cout<< " => irrasional"<<endl;
		else cout<<" = "<<(*i+2)/2<<"^2"<<endl;

	}else{
		*x-=*i;
		cout<<*i<<" + ";
		*i+=2;
		deretGanjil(x,i);
		
	}
}

int main(){
	int x,i = 1;
	cin>>x;
	deretGanjil(&x,&i);
}