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

<details>
  <summary>
    <b>Soal-2</b>
  </summary>
  <p align="center">
    Time Limit = 1s
  </p>
  
  <p align="center">
    Memory Limit = 32MB
  </p>
  
2. Buatlah sebuah program yang dapat menghitung mundur dari bilangan n sampai 0 dengan menggunakan rekursif.
  
  #### Sampel output
|           Input        |          Ouput         |
| :--------------------: | :--------------------: |
| 5                      |  5 4 3 2 1             |
  
</details>

<details>
  <summary>
    <b>Soal-3</b>
  </summary>
  <p align="center">
    Time Limit = 1s
  </p>
  
  <p align="center">
    Memory Limit = 32MB
  </p>
  
3. Buatlah sebuah program yang dapat menghitung bilangan dari 0 sampai dengan n dengan menggunakan rekursif.
  
  #### Sampel output
|           Input        |          Ouput         |
| :--------------------: | :--------------------: |
| 5                      |  0 1 2 3 4 5           |
  
</details>

<details>
  <summary>
    <b>Soal-4</b>
  </summary>
  <p align="center">
    Time Limit = 1s
  </p>
  
  <p align="center">
    Memory Limit = 32MB
  </p>
  
4. Lengkapi kode program berikut sehingga didapat output yang diinginkan.

```c++
#include<iostream>
  using namespace std;
  void Persegi (int x, int y, int z){
    if(..(c)..){
      if(..(d)..){
        cout << ..(e)..;
        Persegi(z,y-1,z);
      }
    else{
        cout << "*";
        Persegi(..(f)..);
      }
    }
  }
  int main(){
    int p, l;
    cin >> p >> ..(a)..;
    Persegi(..(b)..);
    return 0;
}
```
  
  #### Sampel output
| Input  |          Ouput         | Input |          Ouput         |
| :----: | :--------------------: | :--------------------: | :--------------------: |
| 6  4    |  ****** <br> ****** <br> ****** <br> ****** | 7  3    |  ******* <br> ******* <br> *******|
  
</details>

<details>
  <summary>
    <b>Soal-5</b>
  </summary>
  <p align="center">
    Time Limit = 1s
  </p>
  
  <p align="center">
    Memory Limit = 32MB
  </p>
  
5. Perkalian merupakan penjumlahan berulang sebuah bilangan sebanyak pengalinya (2 × 3 ⇔ 2 + 2 + 2) Buatlah sebuah program yang menampilkan proses penjumlahan dari suatu perkalian
  
  #### Sampel output
|           Input        |          Ouput         |
| :--------------------: | :--------------------: |
| 2  3                   |  2 + 2 + 2 = 6           |
  
</details>




