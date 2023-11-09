## TUGAS PRAKTIKUM 1
##### ALGORITMA DAN STRUKTUR DATA 2018

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
  
1. Lengkapilah kode program penukaran dua nilai berikut.
  
  ```c++
  #include <iostream>
  using namespace std;
  void swap(int* x, int* y){
    int ..(a).. = *x;
    ..(b).. = *y;
    ..(c).. = ..(d)..;
  }
  int main(){
    int a, b;
    cin >> a >> b;
    swap(..(e)..);
    cout << ..(f)..;
  }
  ```
  #### Sampel output
|           Input        |          Ouput         |
| :--------------------: | :--------------------: |
| 45   35                |  35   45                 |

  
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
  
2. Dengan menggunakan pointer dan rekursif, buatlah sebuah program yang menerima inputdua bilangan X dan Y, dan menampilkan hasil X^Y
  
  #### Sampel output
|           Input        |          Ouput         |
| :--------------------: | :--------------------: |
| 3 3                      | 27             |
| 4 2                      | 16             |
  
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
  
3. n2 adalah hasil dari penjumlahan bilangan ganjil dari 1 sampai bilangan ke-n. Dengan menggunakan pointer dan rekusif buatlah sebuah program yang menampilkan bilangan penyusun n2
  
  #### Sampel output
|           Input        |          Ouput         |
| :--------------------: | :--------------------: |
| 64                      |  1+3+5+7+9+11+13+15 = 8^2           |
| 9                      |  1+3+5 = 3^2           |
  
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
  
4. Dengan menggunakan pointer dan rekursif, buatlah sebuah program yang menerima masukan N buah bilangan, lalu menentukan apakah bilangan tersebut apakah bilangan prima atau komposit.
  
  #### Sampel output
| Input  |          Ouput         |
| :----: | :--------------------: |
| 5 <br> 3 4 7 12 23   |  Prima <br> Komposit <br> Prima <br> Komposit <br> Prima| 
  
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
  
5. Lengkapilah kode program berikut yang melakukan pengurutan N buah bilangan seperti pada contoh kasus di bawah ini.

```c++
#include <iostream>
using namespace std;
void balik (int ..(a)..){
  if(..(b)..){
    *A = *A * 10;
  } else {
    ..(c).. = (*A%10) * 10 + *A/10;
  }
}

void Urut (int a[], int ..(d)..){
/*gunakan algoritma sorting*/
..(e)..

}
int main (){
  int N;
  cin >> N;
  int X[N], i=0;
  while (i < N){
    cin >> X[i];
    balik(..(f)..);
    i++;
  }
  Urut(X, N);
  i=0;
  while (i < N){
    balik(..(g)..);
    cout << X[i] <<" ";
    i++;
  }
  return 0;
}
```
  
  #### Sampel output
|           Input         |          Ouput         |
| :---------------------: | :--------------------: |
| 10 <br> 1 11 12 2 13 23 31 62 71 81 |  1 11 31 71 81 2 12 62 13 23  |
  
</details>




