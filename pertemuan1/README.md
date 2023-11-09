## TUGAS PRAKTIKUM

<details>
  <summary>
    <b>Soal-1</b>
  </summary>
  <p align="center">
    Time Limit = 1s
  </p>
  
  <p align="center">
    Memory Limit = 32MB
  </p>
  
1. Lengkapilah kode program berikut untuk menentukan penjumlahan antar bilangan dari setiap kemungkinan
   bilangan yang terdapat didalam array of integer arr[]. Panjang array adalah sebanyak integer n.
  
  ```c++
  #include<iostream>
  using namespace std;
  void penjumlahanSubset(int arr[], ..(a).., int r, ..(b)..){
    if (l > r) {
      cout << sum << " ";
      return;
    }
      penjumlahanSubset(arr, l+1, ..(c).., ..(d)..);
      penjumlahanSubset(arr, ..(e).., r, sum);
  }
  int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin >> arr[i];
    }
    penjumlahanSubset(arr, 0, n-1, 0);
    return 0;
  }
  ```
  #### Sampel output
|           Input        |          Ouput         |
| :--------------------: | :--------------------: |
| 3 <br> 5 4 3           |  12 9 8 5 7 4 3 0 <br> |
| 4 <br> 1 23 54 1000    | 1078 78 1024 24 1055 55 1001 1 1077 77 1023 23 1054 54 1000 0 <br> |
| 2 <br> 1 3             |  4 1 3 0<br>           |
| 3 <br> 5 4 3           |  12 9 8 5 7 4 3 0 <br> |

  ##### **Nb. 0 walaupun tidak tertulis tetap merupakan bagian dari bilangan.**
  
</details>




