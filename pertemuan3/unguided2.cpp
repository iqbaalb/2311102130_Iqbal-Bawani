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

    cout << "\n== MENU TOKO SKINCARE PURWOKERTO  ==" << endl;

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
                cout << "TAMPILAN DATA PRODUK TOKO SKINCARE PURWOKERTO SEKARANG" << endl;
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