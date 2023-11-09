/**
 * by Jose Sitanggang
 * 14116125
*/

#include <iostream>
using namespace std;

int kali(int x,int n,int sum = 0 ){
    
    if(n<1) return 0;

    cout<<x;
    if(n==1) cout<<" = "<<sum+x;
    else{
        cout<<" + ";
        kali(x,n-1,sum+=x);
    }
}

int main(){
    int n,x;
    cin>>x;
    cin>>n;
    kali(x,n);
    return 0;
}