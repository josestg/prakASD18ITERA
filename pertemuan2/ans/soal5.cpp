#include <iostream>
using namespace std;
void balik (int *A){
  if(*A<10){
    *A = *A * 10;
  } else {
     *A= (*A%10) * 10 + *A/10;
  }
}
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

void Urut (int a[], int N){
/*gunakan algoritma sorting*/
  int i, j, min_id; 

  for (i = 0; i < N-1; i++) 
  { 
      min_id = i; 
      for (j = i+1; j < N; j++) 
        if (a[j] < a[min_id]) 
          min_id = j; 

      swap(&a[min_id], &a[i]); 
  } 

}

int main (){
  int N;
  cin >> N;
  int X[N], i=0;
  while (i < N){
    cin >> X[i];
    balik(&X[i]);
    i++;
  }

  Urut(X, N);
  i=0;
  while (i < N){
    balik(&X[i]);
    cout << X[i] <<" ";
    i++;
  }
  return 0;
}