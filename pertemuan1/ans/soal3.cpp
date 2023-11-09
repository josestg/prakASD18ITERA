/**
 * by Jose Sitanggang
 * 14116125
*/
#include<iostream>
using namespace std;

int mundur(int a){
    // a >= 0
    if(a>=0)
        mundur(a-1);
    else 
        return 0;
    cout<<a<<endl;
    
}

int main(){
    int x;
    cin>>x;
    mundur(x);
}