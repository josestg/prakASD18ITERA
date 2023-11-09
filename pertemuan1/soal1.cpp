/**
 * by Jose Sitanggang
 * 14116125
*/

#include<iostream>
using namespace std;

void pemnjumlahanSubset(int arr[],int l,int r, int sum){
    if(l>r){
        cout<<sum<<" ";
        return;
    }
    pemnjumlahanSubset(arr,l+1,r,sum+arr[l]);
    pemnjumlahanSubset(arr,l+1,r,sum);        
    cout<<" bawah"<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for( int i =0 ;i<n;i++){
        cin>>arr[i];
    }
    pemnjumlahanSubset(arr,0,n-1,0);
    return 0;
}
