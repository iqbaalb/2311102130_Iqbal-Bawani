# <h1 align="center">Laporan Praktikum Modul Linked list</h1>
<p align="center">Iqbal bawani</p>
 
## Dasar Teori

 Pengertian array
Array adalah suatu struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Elemen-elemen array tersusun secara sekuensial dalam memori komputer. Semua elemem array bertipe sama. Array cocok untuk organisasi kumpulan data homogen yang ukuran atau jumlah elemen maksimumnya telah diketahui dari awal.
Array dibagi menjadi :        
1. Array Satu Dimensi Array satu dimensi tidak lain adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda.  Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutanDeklarasi : Type_Data Nama_Variabel [index] Misalnya : int A[5];       
2. Array Dua Dimensi Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. Pendeklarasian array dua dimensi hampir sama dengan pendeklarasian array satu dimensi, kecuali bahwa array dua dimensi terdapat dua jumlah elemen array yang terdapat di dalam kurung siku dan keduanya boleh tidak sama.Deklarasi : Type_Data Nama_Variabel [Index1] [index2]; Misal : int A[3][2];        
3.  Array Tiga Dimensi           Array tiga dimensi digunakan untuk mengelola data dalam bentuk 3 dimensi atautiga sisi. Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3]; Misal : int A [3][4][2];        
4.  Array Banyak DimensiSebenarnya array banyak dimensi ini tidak terlalu sering dipakai seperti halnyaarray satu dimensi, dua dimensi, dan tiga dimensi. Array banyak dimensi ini pada dasarnya sama dengan array sebelimnya kecuali pada jumlah dimensinya.Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3] [ndex4].....;Misal : int A [3][4][2][5]

karakteristik array yaitu bersifat statis, mempunyai tipe data sama, dan dapat diakses secara acak.Penggunaan Array
Pada dasarnya penggunaan array sangat luas tidak hanya digunakan pada bahasa pemrogaman. Contoh penggunaan array sebagai berikut :

Array digunakan untuk suatu database, contoh : tabel.
Array digunakan untuk operasi matematika seperti vektor.
Digunakan dalam bentuk struktur data lain, contohnya list.


## Guided 

### 1. [Latihan single linked list]

```
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}

//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
    head = tail = baru;
    tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
}
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}

//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" <<endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
    while( nomor < posisi - 1 ){
        bantu = bantu->next;
        nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
}
    else{
            head = tail = NULL;
    }
}
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                    bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" <<
endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
    cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" <<
endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" <<
endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
    tail->data = data;
}
    else{
    cout << "List masih kosong!" << endl;
}
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
    cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    clearList();
    return 0;
}
```

kode di atas adalah suatu kode untuk mengelola single linked list. Terdapat berbagai fungsi yang digunakan untuk mengelola single linked list, termasuk fungsi untuk menambahkan node (di depan, di tengah, di belakang), menghapus node (di depan, di tengah, di belakang, semua), mengubah node (di depan, di tengah, di belakang), menghitung jumlah node/list, dan menampilkan list. Pada awal program, terdapat struktur node yang digunakan untuk mendefinisikan sebuah node. Setiap node tersebut terdiri dari dua bagian memori yang berisi nilai yang disimpan dan pointer next. Selain itu, ada juga prosedur init yang digunakan untuk menginisialisasi head dan tail dengan nilai NULL, serta ada fungsi isEmpty yang digunakan untuk memeriksa apakah linked list kosong atau tidak. Pada bagian int main(), dilakukan beberapa operasi yang terkait dengan linked list, seperti menambahkan data, mengubah data, menghapus data, dan menampilkan data.

#### Output:
![SS OUTPUT GUIDED1](Screenshot guided1.png)

## 2. [Latihan Double Lingked list]

```C++
#include<iostream>

using namespace std;

//deklarasi class node
class node{
    public:
    //node berisi data, pointer prev, dan pointer next
    int data;
    node* prev;
    node* next;
};

//deklarasi class doublelinkedist
class doublelinkedlist{
    public:
    node* head;
    node* tail;

    //inisialisasi head dan tail
    doublelinkedlist(){
        head == nullptr;
        tail = nullptr;
    }

    //prosedur menambah node
    void push(int data){
        node* newnode = new node;
        newnode->data = data;
        newnode->prev = nullptr;
        newnode->next = head;
        if(head != nullptr){
            head->prev = newnode;
        } else {
            tail = newnode;
        }
        head = newnode;
    }

    //prosedur menghapus node
    void pop(){
        if(head == nullptr){
            return;
        }
        node* temp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    //prosedur mengupdate atau mengubah data suatu node
    bool update(int olddata, int newdata){
        node* current = head;
        while(current != nullptr){
            if(current->data == olddata){
                current->data = newdata;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    //prosedur menghapus semua node
    void deleteall(){
        node* current = head;
        while (current != nullptr) {
            node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    //prosedur menampilkan list
    void display(){
        node* current = head;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
};

int main(){
    doublelinkedlist list;
    while(true){
        //menu manipulasi double linked list
        cout << "1. add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1 : { //jika menginput 1, maka tambah node didepan
                int data;
                cout << "enter data to add : ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2 : { //jika menginput 2, maka hapus node didepan
                list.pop();
                break;
            }
            case 3 : { //jika menginput 3, maka ubah node didepan
                int olddata, newdata;
                cout << "enter old data : ";
                cin >> olddata;
                cout << "enter new data : ";
                cin >> newdata;
                bool update = list.update(olddata, newdata);
                if(!update){
                    cout << "data not found" << endl;
                }
                break;
            }
            case 4 : { //jika memilih 4, maka hapus semua node
                list.deleteall();
                break;
            }
            case 5 : { //jika memilih 5, maka tampilkan list
                list.display();
                break;
            }
            case 6 : { //jika memilih 6, maka keluar dari program
                return 0;
            }
            default : { //output jika menginput selain 1-6
                cout << "invalid choice" << endl;
                break;
            }
        }
    }

    return 0;
}
```
Kode diatas adalah implementasi sederhana dari double linked list dalam bahasa C++. Dalam program tersebut, terdapat definisi dari kelas Node yang memiliki atribut data, pointer ke node sebelumnya (`prev`), dan pointer ke node berikutnya (`next`). Kelas DoubleLinkedList memiliki pointer `head` dan `tail` yang menunjukkan awal dan akhir dari linked list. Program ini juga menyediakan fungsi untuk menambah node di depan, menghapus node dari depan, mengubah data node, menghapus semua node, dan menampilkan isi dari linked list. Fungsi main digunakan untuk memberikan menu kepada pengguna untuk memilih operasi yang ingin dilakukan pada linked list, seperti menambah, menghapus, mengubah, menghapus semua, atau menampilkan isi linked list, dan terus berjalan sampai pengguna memilih untuk keluar dari program.

#### Output:
![SS OUTPUT GUIDED1](Screenshot guided2.png)

## Unguided 

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!] (screeshot soal unguided1.png)

```C++
#include <iostream>
using namespace std;

struct Node {
    string nama;
    int usia;
    Node* next;
};

Node* head = NULL;

void insertDepan() {
    string iqbal_130; // Mengubah nama variabel "nama" menjadi "iqbal_130"
    int usia;
    cout << "Masukkan nama: ";
    cin >> iqbal_130; // Mengubah input ke variabel "iqbal_130"
    cout << "Masukkan usia: ";
    cin >> usia;

    Node* baru = new Node;
    baru->nama = iqbal_130; // Mengubah nama variabel "nama" menjadi "iqbal_130"
    baru->usia = usia;
    baru->next = head;
    head = baru;
}

void insertBelakang(string iqbal_130, int usia) { // Mengubah parameter nama menjadi "iqbal_130"
    Node* baru = new Node;
    baru->nama = iqbal_130; // Mengubah nama variabel "nama" menjadi "iqbal_130"
    baru->usia = usia;
    baru->next = NULL;
    if (head == NULL) {
        head = baru;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void insertTengah(string iqbal_130, int usia, string posisi_nama) { // Mengubah parameter nama menjadi "iqbal_130"
    Node* baru = new Node;
    baru->nama = iqbal_130; // Mengubah nama variabel "nama" menjadi "iqbal_130"
    baru->usia = usia;

    Node* temp = head;
    while (temp != NULL && temp->nama != posisi_nama) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Posisi tidak ditemukan!" << endl;
        return;
    }

    baru->next = temp->next;
    temp->next = baru;
}

void hapusData(string iqbal_130) { // Mengubah parameter nama menjadi "iqbal_130"
    Node* hapus = head;
    Node* prev = NULL;
    while (hapus != NULL && hapus->nama != iqbal_130) { // Mengubah nama variabel "nama" menjadi "iqbal_130"
        prev = hapus;
        hapus = hapus->next;
    }
    if (hapus == NULL) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }
    if (prev == NULL) {
        head = hapus->next;
    }
    else {
        prev->next = hapus->next;
    }
    delete hapus;
}

void ubahData(string iqbal_130, string newNama, int newUsia) { // Mengubah parameter nama menjadi "iqbal_130"
    Node* temp = head;
    while (temp != NULL && temp->nama != iqbal_130) { // Mengubah nama variabel "nama" menjadi "iqbal_130"
        temp = temp->next;
    }
    if (temp != NULL) {
        temp->nama = newNama;
        temp->usia = newUsia;
    }
}

void tampilkanData() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nama << " " << temp->usia << endl;
        temp = temp->next;
    }
}

int main() {
    insertBelakang("Igor", 20); // Menambahkan "Igor" 
    insertDepan(); // Menggunakan cin untuk memasukkan nama dan usia.
    insertBelakang("John", 19);
    insertTengah("Futaba", 18, "John");
    insertBelakang("Jane", 20);
    insertBelakang("Michael", 18);
    insertBelakang("Yusuke", 19);
    insertBelakang("Akechi", 20);
    insertBelakang("Hoshino", 18);
    insertBelakang("Karin", 18);

    hapusData("Akechi");
    ubahData("Michael", "Reyn", 18);
    tampilkanData();

    return 0;
}

```
#### Output:
![screenshot output unguided1](Screenshot unguided1.png)

koe di atas sebuah program C++ yang meminta pengguna untuk memasukkan sejumlah bilangan, menyimpannya dalam sebuah array, dan kemudian memisahkan bilangan ganjil dan genap ke dalam dua array terpisah.Pertama-tama, program meminta pengguna untuk memasukkan jumlah bilangan yang akan dimasukkan. Kemudian, program menggunakan array `bilangan` untuk menyimpan bilangan yang dimasukkan pengguna. Setelah itu, program memasukkan bilangan-bilangan tersebut ke dalam array menggunakan loop. Kemudian, program memisahkan bilangan ganjil dan genap ke dalam dua array terpisah, yaitu `ganjil` dan `genap`. Untuk melakukannya, program menggunakan loop untuk memeriksa setiap bilangan dalam array `bilangan`. Jika bilangan tersebut genap, maka bilangan tersebut disimpan dalam array `genap`, dan jika bilangan tersebut ganjil, maka bilangan tersebut disimpan dalam array `ganjil`.  Terakhir, program menampilkan hasilnya.

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!!]

```
// UNGUIDED 2
// Iqbal Bawani
// S1 IF-11-D
// 2311102130

#include <iostream>
#include <iomanip> 
using namespace std;

// Deklarasi Struct Node
class Node {
public:
    string produk_130; // Deklarasi string untuk nama produk
    int harga; // Deklarasi integer untuk harga produk
    Node* prev; // Pointer ke node sebelumnya dalam linked list
    Node* next; // Pointer ke node selanjutnya dalam linked list
};
// Deklarasi Class DoublyLinkedList
class DoublyLinkedList {
public:
    Node* head; // Pointer ke node pertama dalam linked list
    Node* tail; // Pointer ke node terakhir dalam linked list

    // Constructor untuk inisialisasi head dan tail
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

      void Push(int harga, string produk_130) {
        Node* newNode = new Node; // Pembuatan node baru
        newNode->harga = harga; // Penetapan harga untuk node baru
        newNode->produk_130 = produk_130; // Penetapan nama produk untuk node baru
        newNode->prev = nullptr; // Penetapan pointer prev ke nullptr
        newNode->next = head; // Penetapan pointer next ke node head

        // Penanganan kasus jika linked list tidak kosong
        if (head != nullptr) {
            head->prev = newNode;
        }
        // Penanganan kasus jika linked list kosong
        else {
            tail = newNode;
        }

        head = newNode; // Penetapan node baru sebagai node head
    }
    
    // Prosedur untuk menambahkan data pada posisi tertentu dalam linked list
void PushPosition(int posisi, int harga, string produk_130) {
    // Memeriksa apakah posisi yang dimasukkan valid (tidak kurang dari 1)
    if (posisi < 1) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // Pembuatan node baru untuk data yang akan dimasukkan
    Node* newNode = new Node;
    newNode->harga = harga;
    newNode->produk_130 = produk_130;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    // Kasus khusus jika posisi yang dimasukkan adalah posisi pertama
    if (posisi == 1) {
        newNode->next = head; // Penunjuk next node baru menunjuk ke head
        // Penanganan kasus jika linked list tidak kosong
        if (head != nullptr)
            head->prev = newNode; // Penunjuk prev head menunjuk ke node baru
        else
            tail = newNode; // Jika linked list kosong, tail menunjuk ke node baru
        head = newNode; // Node baru menjadi head
        return;
    }

    // Iterasi untuk menemukan posisi sebelum posisi yang dimasukkan
    Node* current = head;
    for (int i = 1; i < posisi - 1 && current != nullptr; ++i)
        current = current->next;

    // Penanganan jika posisi tidak valid
    if (current == nullptr) {
        cout << "Posisi tidak valid!" << endl;
        delete newNode; // Hapus node baru yang sudah dibuat
        return;
    }

    // Penyesuaian pointer next dan prev untuk node baru dan node sebelumnya
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != nullptr)
        current->next->prev = newNode; // Jika node setelahnya tidak kosong, pointer prevnya diarahkan ke node baru
    else
        tail = newNode; // Jika node setelahnya kosong, tail menunjuk ke node baru
    current->next = newNode; // Pointer next node sebelumnya menunjuk ke node baru
}

    // Prosedur untuk menghapus data di depan dari linked list
void Pop() {
    // Memeriksa apakah linked list kosong
    if (head == nullptr) {
        cout << "Tidak ada data yang bisa dihapus!" << endl;
        return;
    }

    // Menyimpan node yang akan dihapus ke dalam variabel sementara
    Node* temp = head;
    // Menggeser head ke node berikutnya
    head = head->next;

    // Memeriksa apakah setelah menghapus, linked list masih memiliki node lain
    if (head != nullptr) {
        head->prev = nullptr; // Menyetel pointer prev dari head menjadi nullptr
    } else {
        tail = nullptr; // Jika linked list menjadi kosong, setel tail menjadi nullptr
    }

    delete temp; // Menghapus node yang disimpan dalam variabel sementara
    }
    
// Prosedur untuk menghapus data pada posisi tertentu dalam linked list
void PopPosition(int posisi) {
    // Memeriksa apakah linked list kosong
    if (head == nullptr) {
        cout << "Tidak ada data yang bisa dihapus!" << endl;
        return;
    }

    // Mencari node yang akan dihapus berdasarkan posisinya
    Node* current = head;
    for (int i = 1; i < posisi && current != nullptr; ++i) {
        current = current->next;
    }

    // Memeriksa apakah posisi yang dimasukkan valid
    if (current == nullptr) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // Menghubungkan node sebelum dan sesudah node yang akan dihapus
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next; // Jika node yang dihapus adalah head, geser head ke node berikutnya
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev; // Jika node yang dihapus adalah tail, setel tail ke node sebelumnya
    }

    delete current; // Menghapus node yang sudah tidak diperlukan
    }

   // Fungsi untuk mengupdate data pada linked list
bool Update(string oldProduk, string newProduk, int newharga) {
    Node* current = head;

    // Mencari node dengan produk yang sesuai dengan produk lama yang akan diubah
    while (current != nullptr) {
        if (current->produk_130 == oldProduk) {
            current->produk_130 = newProduk; // Mengubah nama produk
            current->harga = newharga; // Mengubah harga produk
            return true; // Mengembalikan true karena data berhasil diupdate
        }
        current = current->next;
    }

    return false; // Mengembalikan false jika data yang akan diupdate tidak ditemukan
}

// Prosedur untuk menghapus semua data dalam linked list
void DeleteAll() {
    Node* current = head;

    // Melakukan iterasi untuk menghapus satu per satu node sampai tidak ada node lagi
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp; // Menghapus node yang tidak diperlukan
    }

    head = nullptr; // Setel head menjadi nullptr karena tidak ada node lagi dalam linked list
    tail = nullptr; // Setel tail menjadi nullptr karena tidak ada node lagi dalam linked list
}

// Prosedur untuk menampilkan semua data dalam linked list
void Display() {
    Node* current = head;

    // Menampilkan judul kolom untuk data produk dan harga
    cout << left << setw(20) << "[ Nama Produk ]" << setw(10) << "[ Harga ]" << endl;

    // Melakukan iterasi untuk menampilkan data produk dan harganya
    while (current != nullptr) {
        cout << setw(20) << current->produk_130 << setw(10) << current->harga << endl;
        current = current->next;
    }

    cout << endl; // Memberikan baris kosong setelah menampilkan semua data
}
};

int main() 
{
    DoublyLinkedList list;

    cout << "\n== MENU TOKO SKINCARE PURWOKERTO BY RICO ADE PRATAMA ==" << endl;

    // Inisialisasi data awal
    list.Push(30000, "Hanasui");
    list.Push(50000, "Wardah");
    list.Push(100000, "Skintific");
    list.Push(150000, "Somethinc");
    list.Push(60000, "Originote");
    list.Display(); 

    // Loop untuk menu interaktif
    while (true) {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "   1. Tambah Data" << endl;
        cout << "   2. Hapus Data" << endl;
        cout << "   3. Update Data" << endl;
        cout << "   4. Tambah Data pada Posisi Tertentu" << endl;
        cout << "   5. Hapus Data pada Posisi Tertentu" << endl;
        cout << "   6. Hapus Semua Data" << endl;
        cout << "   7. Tampilkan Data" << endl;
        cout << "   8. Exit" << endl;

        int pilihan;
        cout << "Pilih Nomor: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int harga;
                string produk;

                cout << "TAMBAH PRODUK SKINCARE" << endl;
                cout << "Nama produk: ";
                cin.ignore();
                getline(cin, produk);
                cout << "Harga : ";
                cin >> harga;
                list.Push(harga, produk);
                cout << "Produk berhasil ditambahkan!" << endl;
                list.Display(); 
                break;
            }

            case 2: {
                list.Pop();
                cout << "PRODUK PALING ATAS BERHASIL DIHAPUS!" << endl;
                list.Display(); 
                break;
            }
            case 3: {
                string oldProduk, newProduk;
                int newharga;

                cout << "UPDATE DATA PRODUK SKINCARE" << endl;
                cout << "Nama produk lama : ";
                cin.ignore();
                getline(cin, oldProduk);
                cout << "Masukkan nama produk baru: ";
                getline(cin, newProduk);
                cout << "Masukkan harga baru: ";
                cin >> newharga;

                bool update = list.Update(oldProduk, newProduk, newharga);
                if (update) {
                    cout << "Data diperbarui!" << endl;
                } else {
                    cout << "Data tidak ditemukan!" << endl;
                }
                list.Display(); 
                break;
            }

            case 4: {
                int posisi, harga;
                string produk;

                cout << "TAMBAH DATA PRODUK PADA URUTAN TERTENTU " << endl;
                cout << "Nomor produk yang ditambahkan: ";
                cin >> posisi;
                cout << "Nama produk: ";
                cin.ignore();
                getline(cin, produk);
                cout << "Harga : ";
                cin >> harga;
                list.PushPosition(posisi, harga, produk);
                cout << "Produk berhasil ditambahkan pada posisi ke-" << posisi << "!" << endl;
                list.Display(); 
                break;
            }

            case 5: {
                int posisi;

                cout << "HAPUS DATA PRODUK PADA URUTAN TERTENTU " << endl;
                cout << "Nomor produk yang di hapus : ";
                cin >> posisi;
                list.PopPosition(posisi);
                cout << "Data berhasil dihapus pada posisi ke-" << posisi << "!" << endl;
                list.Display(); 
                break;
            }

            case 6: {
                list.DeleteAll();
                cout << "SEMUA DATA BERHASIL DI HAPUS!" << endl;
                list.Display(); 
                break;
            }

            case 7: {
                cout << "1TAMPILAN DATA PRODUK TOKO SKINCARE PURWOKERTO SEKARANG" << endl;
                list.Display(); 
                break;
            }

            case 8: {
                cout << "Terimakasih telah menggunakan program ini!" << endl;
                return 0;
            }

            default: {
                cout << "Pilihan anda tidak valid!" << endl;
                break;
            }
        }
    }
    return 0;
    }
```
#### Output:
![screenshot output unguided 2](Screenshot unguided2.png)

kode diatass sebuah program C++ yang mengizinkan pengguna untuk memasukkan ukuran tiga dimensi untuk sebuah array. Setelah itu, program meminta pengguna untuk memasukkan elemen-elemen untuk setiap indeks dalam array tiga dimensi tersebut. Program meminta pengguna untuk memasukkan ukuran lapisan, baris, dan kolom untuk array tiga dimensi. Kemudian, program mendeklarasikan array `arr` dengan ukuran yang sesuai dengan input yang diberikan oleh pengguna. Setelah nya, program menggunakan tiga loop bersarang (nested loop) untuk memungkinkan pengguna memasukkan nilai untuk setiap elemen array. Loop pertama digunakan untuk mengakses setiap lapisan (indeks x), loop kedua untuk mengakses setiap baris (indeks y) dalam setiap lapisan, dan loop ketiga untuk mengakses setiap kolom (indeks z) dalam setiap baris.

### 3. [ Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!!]

```C++
#include <iostream>
using namespace std;

// Fungsi untuk mencari nilai maksimum
int max(int array[], int size, int& lokasi) {
    int maks = array[0];
    lokasi = 0;
    for (int i = 1; i < size; ++i) {
        if (array[i] > maks) {
            maks = array[i];
            lokasi = i;
        }
    }
    return maks;
}

// Fungsi untuk mencari nilai minimum
int minimum(int array[], int size, int& lokasi) {
    int min = array[0];
    lokasi = 0;
    for (int i = 1; i < size; ++i) {
        if (array[i] < min) {
            min = array[i];
            lokasi = i;
        }
    }
    return min;
}

// Fungsi untuk mencari nilai rata-rata atau Average
double rata2(int array[], int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += array[i];
    }
    return static_cast<double>(total) / size;
}

int main() {
    int iqbal;
    cout << "Masukkan jumlah bilangan: ";
    cin >> iqbal;
    
    int array[iqbal];
    for (int i = 0; i < iqbal; ++i) {
        cout << "Angka ke-" << i + 1 << ": ";
        cin >> array[i];
    }

    int pilihan;
    int lokasi;
    do {
        cout << "1. Mencari nilai maksimum"<< endl;;
        cout << "2. Mencari nilai minimum" << endl ;
        cout << "3. Mencari nilai rata-rata" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih Nomor: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Nilai maksimum adalah: " << max(array, iqbal, lokasi)  << endl;
                break;
            case 2:
                cout << "Nilai minimum adalah: " << minimum(array, iqbal, lokasi) <<  endl;
                break;
            case 3:
                cout << "Nilai rata-rata adalah: " << rata2(array, iqbal) << endl;
                break;
            case 4:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Masukkan pilihan angka yang tersedia." << endl;
        }
    } while (pilihan != 4);

    return 0;
}

```
#### Output:
![screenshot output unguided 3](Screenshot unguided3.png)

kode diatas sebuah program C++ yang melakukan operasi-operasi dasar pada array, yaitu mencari nilai maksimum, minimum, dan rata-rata dari sejumlah angka yang dimasukkan pengguna.Program meminta pengguna untuk memasukkan panjang array (`iqbal`) yang akan dimasukkan. Kemudian, program akan menginisialisasi array dengan panjang yang dimasukkan pengguna dan meminta pengguna untuk memasukkan nilai-nilai array tersebut satu per satu. Program akan menampilkan menu operasi yang tersedia kepada pengguna, yaitu mencari nilai maksimum, minimum, atau rata-rata dari array yang telah dimasukkan, atau keluar dari program. Pengguna diminta untuk memilih nomor yang sesuai dengan operasi yang ingin dilakukan. Setelah pengguna memilih operasi, program akan menjalankan fungsi yang sesuai dengan pilihan pengguna. Fungsi `max()` akan mencari nilai maksimum dari array, `minimum()` akan mencari nilai minimum dari array, dan `rata2()` akan menghitung nilai rata-rata dari array. looop do while berguna agar program tak terhenti, progranm baru akan berhenti memilih pilhan 4.

## Kesimpulan
Kesimpulan menunjukkan bagaimana array dapat digunakan dalam berbagai konteks, mulai dari memisahkan elemen array berdasarkan kondisi tertentu hingga melakukan operasi-operasi matematika sederhana. Array bisa digunakan untuk menyimpan bilangan-bilangan yang dimasukkan oleh pengguna, dan kemudian dilakukan pemisahan bilangan ganjil dan genap ke dalam dua array terpisah. Array tiga dimensi digunakan untuk menyimpan data dalam bentuk matriks tiga dimensi. Array juga digunakan untuk menyimpan data bilangan yang diinput oleh pengguna, kemudian dilakukan operasi-operasi tertentu seperti pencarian nilai maksimum, minimum, atau rata-rata dari bilangan-bilangan tersebu. Array adalah bagian dari struktur data yang terdapat dalam struktur data sederhana, yang dapat didefinisikan sebagai peta memori sementara di dalam komputer. Array bisa ada banyak dimensi, dan meiliki beberapa karakteristik seperti bersifat statis, mempunyai tipe data sama, dan dapat diakses secara acak.

## Referensi
[1]PRATAMA, Muhammad Aldi. STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++. 2020.