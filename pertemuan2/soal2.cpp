#include <iostream>
using namespace std;


int pangkat(int *x,int *y){
	if(*y==0){
		return 1;
	}else{
		*y-=1;
		return (*x)*pangkat(x,y);
	}
}

int main(){
	int x,y;
	cin>>x>>y;
	cout<<pangkat(&x,&y)<<endl;
}