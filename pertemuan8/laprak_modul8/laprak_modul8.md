# <h1 align="center">Laporan Praktikum 8  Modul Agoritma Searching</h1>
<p align="center">Iqbal bawani - 2311102130 </p>
 
#### Dasar Teori

Pencarian (Searching) yaitu proses menemukan suatu nilai tertentu pada kumpulan data. Hasil pencarian adalah salah satu dari tiga keadaan ini: data ditemukan, data ditemukan lebih dari satu, atau data tidak ditemukan. Searching juga dapat dianggap sebagai proses pencarian suatu data di dalam sebuah array dengan cara mengecek satu persatu pada setiap index baris atau setiap index kolomnya dengan
menggunakan teknik perulangan untuk melakukan pencarian data.

## Sequential Search
Sequential search adalah metode pencarian paling sederhana. Proses pencarian sequential yaitu dengan membandingkan setiap elemen array satu per satu secara beruntun, dimulai dengan elemen pertama, sampai elemen yang dicari ditemukan atau sampai elemen terakhir dari array. Pencarian sekuensial dapat dilakukan pada elemen array yang tidak diurutkan atau pada elemen array yang diurutkan. Perbedaan  antara keduanya terletak pada efisiensi operasi perbandingan yang dilakukan. Dengan begitu, proses pencarian sequential akan singkat  jika data yang diolah sedikit, dan jika data yang diolah banyak, prosesnya akan lama. Maka, metode ini direkomendasikan  untuk  data  yang sedikit.Konsep Sequential Search yaitu:</br>
● Membandingkan setiap elemen pada array satu per satu secara berurut.</br>
● Proses pencarian dimulai dari indeks pertama hingga indeks terakhir.</br>
● Proses pencarian akan berhenti apabila data ditemukan. Jika hingga akhir array data masih juga tidak ditemukan, maka proses pencarian tetap akan dihentikan.</br>
● Proses perulangan pada pencarian akan terjadi sebanyak jumlah N elemen pada array.<br>
Algoritma pencarian berurutan dapat dituliskan sebagai berikut :</br>
1) i ← 0</br>
2) ketemu ← false</br>
3) Selama (tidak ketemu) dan (i <= N) kerjakan baris 4</br>
4) Jika (Data[i] = x) maka ketemu ← true, jika tidak i ← i + 1></br>
5) Jika (ketemu) maka i adalah indeks dari data yang dicari, jika tidak data tidak
ditemukan</br>

Contoh dari Sequential Search, yaitu: Int A[8] = {9,1,5,2,7,6,11,3}
![contohsequential](zsequentialcontoh.png)
Misalkan, dari data di atas angka yang akan dicari adalah angka 7 dalam array A, maka proses yang akan terjadi yaitu:</br>
● Pencarian dimulai pada index ke-0 yaitu angka 9, kemudian dicocokkan dengan angka yang akan dicari, jika tidak sama maka pencarian akan dilanjutkan ke index selanjutnya.</br>
● Pada index ke-1, yaitu angka 1, juga bukan angka yang dicari, maka pencarian akan dilanjutkan pada index selanjutnya.</br>
● Pada index ke-2 dan index ke-3 yaitu angka 5 dan 2, juga bukan angka yang dicari, sehingga pencarian dilanjutkan pada index selanjutnya.</br>
● Pada index ke-4 yaitu angka 7 dan ternyata angka 7 merupakan angka yang dicari, sehingga pencarian akan dihentikan dan proses selesai.</br>

## Binay search
[1]Pencarian Bagi dua (Binary Search)</br>
Pencarian bagidua (binary search) adalah prosespencarian dengan membagi dua bagian data kemudian
membandingkan isi data bagian pertama atau bagian kedua dengan data yang akan dicari. Pada metode ini
membutuhkan nilai indeks terkecil dan terbesar untuk dijumlahkan kemudian dibagi dua. Pencarian bagi dua
(binary search) hanya bisa dilakukan pada data yang sudah urut. Metode ini lebih efisien dibandingkan dengan
metode pencarian sequential search atau pencarian beruntun.</br>


[2]Algoritma Pecarian Bagidua data ascending</br>
Step 1: Tentukan Nilai tengah, nilai tengah didapatkan dengan cara sebagi berikut:</br>
Misal index awal =awal dan index akhir =akhir maka,</br>
c = (awal+akhir) div 2 </br>
Step 2: Bandingkan data, apakah data[c] = d ?</br>
d adalah data yang sedang dicari.</br>
apabila data[c] = d, data ditemukan, selesai.</br>
apabila data[c] > d, pencarian berpindah ke bagian kiri</br>
dengan cara mengubah nilai c menjadi: akhir = c-1
apabila data[c] < d, pencarian berpindah ke bagian kanan dengan cara mengubah nilai c menjadi awal = c + 1</br>
step 3 : Kembali ke step 1 hingga d (data yang dicari) ditemukan
atau hingga nilai awal > akhir</br>

Contoh dari Binary Search, yaitu:
![contohbinarysearch](zbinarysearchcontoh.png)
● Terdapat sebuah array yang menampung 7 elemen seperti ilustrasi di atas. Nilai yang akan dicari pada array tersebut adalah 13.</br>
● Jadi karena konsep dari binary search ini adalah membagi array menjadi dua bagian, maka pertama tama kita cari nilai tengahnya dulu, total elemen dibagi 2 yaitu 7/2 = 4.5 dan kita bulatkan jadi 4.</br>
● Maka elemen ke empat pada array adalah nilai tengahnya, yaitu angka 9 pada indeks ke 3.</br>
● Kemudian kita cek apakah 13 > 9 atau 13 < 9?</br>
● 13 lebih besar dari 9, maka kemungkinan besar angka 13 berada setelah 9 atau di sebelah kanan. Selanjutnya kita cari ke kanan dan kita dapat mengabaikan elemen yang ada di kiri.</br>
● Setelah itu kita cari lagi nilai tengahnya, didapatlah angka 14 sebagai nilai tengah. Lalu, kita bandingkan apakah 13 > 14 atau 13 < 14?</br>
● Ternyata 13 lebih kecil dari 14, maka selanjutnya kita cari ke kiri.</br>
● Karna tersisa 1 elemen saja, maka elemen tersebut adalah nilai tengahnya. Setelah dicek ternyata elemen pada indeks ke-4 adalah elemen yang dicari, maka telah selesai proses pencariannya</br>

## Guided 
### 1. [Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.]
```C++
#include<iostream>

using namespace std ;

int main (){
    int n=10;
    int data[n]={9,4,1,7,5,12,4,13,4,10};
    int cari =10;
    bool ketemu =false ;
    int i;

    for (i=0; i< n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }


cout << "Program Sequential Search" << endl;
cout << " data : {9,4,1,7,5,12,4,13,4,10}" << endl;

if (ketemu)
{
    cout <<"\n angka" << cari << "ditemukan pada indeks ke " << i << endl; 
}else {
    cout << "data tidak ditemukan " << endl;
}
 return 0;

}
```
## output 
![ss_guided](outputguided1.png)

Kode Program di atas menggunakan metode pencarian (sequential search) untuk mencari nilai tertentu dalam array. Pertama, program mendefinisikan array `data` dengan 10 elemen dan variabel `cari` yang berisi nilai yang ingin dicari, yaitu 10. Variabel `ketemu` diinisialisasi dengan nilai `false` untuk menandakan apakah nilai yang dicari ditemukan atau tidak. Selanjutnya, program menggunakan loop `for` untuk memeriksa setiap elemen dalam array. Jika elemen yang diperiksa sama dengan nilai yang dicari, program mengubah nilai `ketemu` menjadi `true` dan keluar dari loop menggunakan `break`. Setelah loop selesai, program mencetak pesan yang sesuai: jika nilai ditemukan, program mencetak indeks di mana nilai tersebut ditemukan; jika tidak, program mencetak bahwa nilai tersebut tidak ditemukan.

## Guided 
### 2. [Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.]
```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int dataarray[7] = {1,8,2,5,4,9,7};
int cari;

void selection_short(){
    int temp, min, i, j;
    for (int i =0 ;i< 7; i++)
    {
        min = i;
        for (j = i; j<7 ;j++)
        {
            if (dataarray[j] < dataarray[min])
            {
                min =j;
            }
        }
        temp = dataarray[i];
        dataarray[i] = dataarray[min];
        dataarray[min] = temp;
    }
}

void binarysearch(){
    int awal, akhir, tengah;
    bool b_flag = false ;
    awal =0;
    akhir = 0;
    while (!b_flag && awal <= akhir)
    {
        tengah =(awal+akhir)/2;
        if (dataarray[tengah]== cari)
        {
            b_flag=true;
        }else if (dataarray[tengah]< cari)
        {
            awal=tengah +1;
        }else {
            akhir = tengah;
        }
    }
}



int main(){
    cout << "binary search "<< endl;
    cout << "\bdata:" << endl;

    for (int x= 0; x< 7; x++)
    {
        cout << setw(3)<< dataarray[x];
    }
    cout << endl;
    binarysearch();
    _getche();
    return 0;
}
```
## output 
![ss_guided](outputguided2.png)

Kode Program ini mengimplementasikan pencarian biner (binary search) untuk menemukan nilai tertentu dalam array yang telah diurutkan. Pertama, array diurutkan menggunakan selection sort. Kemudian, binary search dimulai dengan menentukan indeks awal dan akhir dari array. Nilai tengah dihitung dan dibandingkan dengan nilai yang dicari. Jika nilai yang dicari ditemukan di tengah, pencarian selesai. Jika tidak, pencarian dilanjutkan di sub-array yang sesuai: kiri jika nilai lebih kecil dari tengah, atau kanan jika lebih besar. Proses ini berulang sampai nilai ditemukan atau seluruh array sudah diperiksa. 



## Unguided 1
### 1.  [Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!]

```C++


```
## output :

![ss_unguided1](outputunguided1.png)

Program kode mengimplementasikan sebuah antrian dalam bentuk linked list, Berbeda dengan guided yang menggunakan arrray yang artinya setiap elemen di representasikansebagai simpul node yang terhubung satu sama lain. Setiap simpul (node) dalam linked list memiliki dua bagian data (dalam hal ini, string) dan pointer ke simpul berikutnya. Ketika elemen baru ditambahkan ke antrian (enqueue), simpul baru dibuat dan ditambahkan di belakang antrian. Ketika elemen dihapus dari antrian (dequeue), simpul di depan antrian dihapus. Fungsi enqueue(const string& data)untuk Menambahkan elemen baru ke dalam antrian, dequeue() untuk Menghapus elemen dari depan antrian.
displayQueue()untuk Menampilkan seluruh elemen yang ada dalam antrian,  isEmpty() untuk Memeriksa apakah antrian kosong.
countQueue()untuk Mengembalikan jumlah elemen dalam antrian, clearQueue() untuk Menghapus semua elemen dari antrian, sehingga membersihkannya.



## Unguided 2
### 2.  [Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!]

```C++


```
## Output:

![ss_ungided2](outputunguided2.png)

 kode diatas adalaha kode program implementasi queue pada c++. Pada dasarnya kode unguided 2 merupakan kode unguided 1 dengan sedikit perubahan dan perbedaan. misalnya kode unguided ke 1 , setiap simpul (node) dalam linked list hanya menyimpan satu data, yaitu string.
Pada unguided kedua, setiap simpul (node) menyimpan dua data, yaitu Nama dan NIM, keduanya bertipe string. Tentunya dengan beberapa hal berbeda akan menghasilkan output yang berbeda. Kode diatas akan menghasilkan output nama dan nim. Fungsi-fungsi utama seperti enqueue, dequeue, displayQueue, isEmpty, countQueue, dan clearQueue pada dasarnya sama antara kedua program. Namun, perbedaan terletak pada cara data Nama dan NIM diakses dan ditampilkan.



## Unguided 3
### 3.  [Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!]

```C++


```
## Output:

![ss_ungided3](outputunguided3.png)

 kode diatas adalaha kode program implementasi queue pada c++. Pada dasarnya kode unguided 2 merupakan kode unguided 1 dengan sedikit perubahan dan perbedaan. misalnya kode unguided ke 1 , setiap simpul (node) dalam linked list hanya menyimpan satu data, yaitu string.
Pada unguided kedua, setiap simpul (node) menyimpan dua data, yaitu Nama dan NIM, keduanya bertipe string. Tentunya dengan beberapa hal berbeda akan menghasilkan output yang berbeda. Kode diatas akan menghasilkan output nama dan nim. Fungsi-fungsi utama seperti enqueue, dequeue, displayQueue, isEmpty, countQueue, dan clearQueue pada dasarnya sama antara kedua program. Namun, perbedaan terletak pada cara data Nama dan NIM diakses dan ditampilkan.



## Kesimpulan
Kesimpulannya, Queue memiliki karakter yang berbeda dengan stack, stack mimliki karakter last in first out sedangkan queue memiliki karakter first ini first out  yang artinya yang pertama masuk maka yang pertama juga keluarnya. Queue bisa di kombinasikan dengan array maupun linked list. Queue bersifat seperti antrian 

## Referensi
[1]RIYANTO, Joko, et al. ALGORITMA DAN PEMROGRAMAN 2. 2022..</br>
[2]PUTRA, Muhammad Taufik Dwi; MUNAWIR, Munawir; YUNIARTI, Ana Rahma. BELAJAR PEMROGRAMAN LANJUT DENGAN C++. 2023.</br>

