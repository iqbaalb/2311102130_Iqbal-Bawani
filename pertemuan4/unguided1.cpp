#include <iostream>
using namespace std;

// Struktur untuk node dalam linked list
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Class untuk mengelola linked list
class LinkedList {
private:
    Node* head; // Pointer ke head dari linked list

public:
    // Constructor untuk menginisialisasi linked list
    LinkedList() : head(nullptr) {}

    // Fungsi untuk menambahkan data di depan linked list
    void tambahDepan(string nama, string nim) {
        Node* newNode = new Node(); // Membuat node baru
        newNode->nama = nama; // Menetapkan nilai nama untuk node baru
        newNode->nim = nim; // Menetapkan nilai nim untuk node baru
        newNode->next = head; // Menunjukkan pointer next node baru ke head
        head = newNode; // Mengatur head baru menjadi node baru
        cout << "Data telah ditambahkan" << endl; // Memberi pesan bahwa data telah ditambahkan
    }
    // Fungsi untuk menambahkan data ke belakang linked list
    void tambahBelakang(string nama, string nim) {
        Node* newNode = new Node(); // Membuat node baru
        newNode->nama = nama; // Menetapkan nilai nama untuk node baru
        newNode->nim = nim; // Menetapkan nilai nim untuk node baru
        newNode->next = nullptr; // Menunjukkan bahwa node baru adalah node terakhir
        if (head == nullptr) { // Jika linked list masih kosong
            head = newNode; // Atur head baru menjadi node baru
            return; // Keluar dari fungsi
        }
        Node* temp = head;
        while (temp->next != nullptr) { // Melakukan iterasi sampai menemukan node terakhir
            temp = temp->next;
        }
        temp->next = newNode; // Menghubungkan node terakhir dengan node baru
        cout << "Data telah ditambahkan" << endl; // Memberi pesan bahwa data telah ditambahkan
    }

    // Fungsi untuk menambahkan data di tengah linked list
    void tambahTengah(string nama, string nim, int posisi) {
        Node* newNode = new Node(); // Membuat node baru
        newNode->nama = nama; // Menetapkan nilai nama untuk node baru
        newNode->nim = nim; // Menetapkan nilai nim untuk node baru

        if (posisi == 1) { // Jika posisi yang diminta adalah posisi pertama
            tambahDepan(nama, nim); // Panggil fungsi tambahDepan untuk menambahkan di depan
            return; // Keluar dari fungsi
        }

        Node* temp = head;
        for (int i = 1; i < posisi - 1 && temp != nullptr; i++) { // Melakukan iterasi untuk mencari node sebelum posisi yang diminta
            temp = temp->next;
        }

        if (temp == nullptr) { // Jika posisi yang diminta melebihi panjang linked list
            cout << "Posisi diluar jangkauan" << endl; // Memberi pesan bahwa posisi diluar jangkauan
            return; // Keluar dari fungsi
        }

        newNode->next = temp->next; // Menghubungkan node baru dengan node setelahnya
        temp->next = newNode; // Menghubungkan node sebelumnya dengan node baru
        cout << "Data telah ditambahkan" << endl; // Memberi pesan bahwa data telah ditambahkan
    }
    // Fungsi untuk mengubah data di depan linked list
    void ubahDepan(string namaBaru, string nimBaru) {
        if (head == nullptr) { // Jika linked list kosong
            cout << "Linked list kosong." << endl; // Menampilkan pesan bahwa linked list kosong
            return; // Keluar dari fungsi
        }

        head->nama = namaBaru; // Mengubah nilai nama pada node pertama
        head->nim = nimBaru; // Mengubah nilai nim pada node pertama
        cout << "Data telah diubah" << endl; // Menampilkan pesan bahwa data telah diubah
    }

    // Fungsi untuk mengubah data di belakang linked list
    void ubahBelakang(string namaBaru, string nimBaru) {
        if (head == nullptr) { // Jika linked list kosong
            cout << "Linked list kosong." << endl; // Menampilkan pesan bahwa linked list kosong
            return; // Keluar dari fungsi
        }

        Node* temp = head;
        while (temp->next != nullptr) { // Melakukan iterasi untuk mencari node terakhir
            temp = temp->next;
        }

        temp->nama = namaBaru; // Mengubah nilai nama pada node terakhir
        temp->nim = nimBaru; // Mengubah nilai nim pada node terakhir
        cout << "Data telah diubah" << endl; // Menampilkan pesan bahwa data telah diubah
    }

    // Fungsi untuk mengubah data di tengah linked list berdasarkan posisi
    void ubahTengah(string namaBaru, string nimBaru, int posisi) {
        if (head == nullptr) { // Jika linked list kosong
            cout << "Linked list kosong." << endl; // Menampilkan pesan bahwa linked list kosong
            return; // Keluar dari fungsi
        }

        Node* temp = head;
        int counter = 1;
        while (temp != nullptr && counter != posisi) { // Melakukan iterasi untuk mencari node pada posisi yang diminta
            temp = temp->next;
            counter++;
        }

        if (temp == nullptr) { // Jika posisi melebihi panjang linked list
            cout << "Posisi diluar jangkauan" << endl; // Menampilkan pesan bahwa posisi diluar jangkauan
            return; // Keluar dari fungsi
        }

        temp->nama = namaBaru; // Mengubah nilai nama pada node yang ditemukan
        temp->nim = nimBaru; // Mengubah nilai nim pada node yang ditemukan
        cout << "Data telah diubah" << endl; // Menampilkan pesan bahwa data telah diubah
    }


        // Fungsi untuk menghapus data dari depan linked list
    void hapusDepan() {
        if (head == nullptr) { // Jika linked list kosong
            cout << "Linked list kosong." << endl; // Menampilkan pesan bahwa linked list kosong
            return; // Keluar dari fungsi
        }

        Node* temp = head; // Simpan pointer ke node pertama
        head = head->next; // Pindahkan head ke node berikutnya
        delete temp; // Hapus node pertama
        cout << "Data berhasil dihapus" << endl; // Menampilkan pesan bahwa data berhasil dihapus
    }

    // Fungsi untuk menghapus data dari belakang linked list
    void hapusBelakang() {
        if (head == nullptr) { // Jika linked list kosong
            cout << "Linked list kosong." << endl; // Menampilkan pesan bahwa linked list kosong
            return; // Keluar dari fungsi
        }

        if (head->next == nullptr) { // Jika linked list hanya memiliki satu node
            cout << "Data (" << head->nama << ") berhasil dihapus" << endl; // Menampilkan nama mahasiswa yang dihapus
            delete head; // Hapus node pertama
            head = nullptr; // Atur head menjadi nullptr
            return; // Keluar dari fungsi
        }

        Node* temp = head;
        while (temp->next->next != nullptr) { // Melakukan iterasi sampai menemukan node sebelum node terakhir
            temp = temp->next;
        }
        cout << "Data (" << temp->next->nama << ") berhasil dihapus" << endl; // Menampilkan nama mahasiswa yang dihapus
        delete temp->next; // Hapus node terakhir
        temp->next = nullptr; // Atur pointer next dari node sebelumnya menjadi nullptr
    }


    // Fungsi untuk menghapus data di tengah linked list berdasarkan posisi
    void hapusTengah(int posisi) {
        if (head == nullptr) { // Jika linked list kosong
            cout << "Linked list kosong." << endl; // Menampilkan pesan bahwa linked list kosong
            return; // Keluar dari fungsi
        }

        if (posisi == 1) { // Jika posisi yang diminta adalah posisi pertama, panggil fungsi hapusDepan
            hapusDepan();
            return; // Keluar dari fungsi
        }

        Node* temp = head;
        Node* prev = nullptr;
        int counter = 1;
        while (temp != nullptr && counter != posisi) { // Melakukan iterasi sampai menemukan node pada posisi yang diminta
            prev = temp;
            temp = temp->next;
            counter++;
        }

        if (temp == nullptr) { // Jika posisi melebihi panjang linked list
            cout << "Posisi diluar jangkauan" << endl; // Menampilkan pesan bahwa posisi diluar jangkauan
            return; // Keluar dari fungsi
        }

        if (prev != nullptr) { // Jika node sebelumnya tidak kosong (bukan node pertama)
            prev->next = temp->next; // Menghubungkan node sebelumnya dengan node setelahnya
            cout << "Data (" << temp->nama << ") berhasil dihapus" << endl; // Menampilkan nama mahasiswa yang dihapus
        } else { // Jika node sebelumnya kosong (node yang dihapus adalah node pertama)
            head = temp->next; // Atur head ke node berikutnya
            cout << "Data (" << temp->nama << ") berhasil dihapus" << endl; // Menampilkan nama mahasiswa yang dihapus
        }

        delete temp; // Hapus node pada posisi yang diminta
    }


    // Fungsi untuk menampilkan seluruh data dalam linked list
    void tampilkanData() {
        if (head == nullptr) { // Jika linked list kosong
            cout << "Linked list kosong." << endl; // Menampilkan pesan bahwa linked list kosong
            return; // Keluar dari fungsi
        }

        cout << "DATA MAHASISWA" << endl; // Menampilkan label data
        cout << "NAMA\tNIM" << endl; // Menampilkan header
        Node* temp = head;
        while (temp != nullptr) { // Melakukan iterasi untuk menampilkan setiap node dalam linked list
            cout << temp->nama << "\t" << temp->nim << endl; // Menampilkan data node
            temp = temp->next; // Beralih ke node berikutnya
        }
    }

    // Fungsi untuk menghapus seluruh data dalam linked list
    void hapusList() {
        while (head != nullptr) { // Melakukan iterasi sampai linked list kosong
            Node* temp = head; // Simpan pointer ke node pertama
            head = head->next; // Pindahkan head ke node berikutnya
            delete temp; // Hapus node yang disimpan
        }
        cout << "Seluruh data telah dihapus" << endl; // Menampilkan pesan bahwa seluruh data telah dihapus
    }

};

int main() {
    LinkedList linkedList;
    int choice;
    string nama, nim;
    int posisi;

    do {
        cout << "\n------- PROGRAM SINGLE LINKED LIST -------" << endl;
        cout << "-------------- NON-CIRCULAR --------------" << endl; 
        cout << " 1. TAMBAH DEPAN                        " << endl;
        cout << " 2. TAMBAH BELAKANG                     " << endl;
        cout << " 3. TAMBAH TENGAH                       " << endl;
        cout << " 4. UBAH DEPAN                          " << endl;
        cout << " 5. UBAH BELAKANG                       " << endl;
        cout << " 6. UBAH TENGAH                         " << endl;
        cout << " 7. HAPUS DEPAN                         " << endl;
        cout << " 8. HAPUS BELAKANG                      " << endl;
        cout << " 9. HAPUS TENGAH                        " << endl;
        cout << " 10. HAPUS LIST                         " << endl;
        cout << " 11. TAMPILKAN                          " << endl;
        cout << " 0. KELUAR                              " << endl;
        cout << " Keluar dari program                    " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Pilih Operasi : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n-------------- TAMBAH DEPAN --------------\n" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                linkedList.tambahDepan(nama, nim);
                break;
            case 2:
                cout << "\n-------------- TAMBAH BELAKANG --------------\n" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                linkedList.tambahBelakang(nama, nim);
                break;
            case 3:
                cout << "\n-------------- TAMBAH TENGAH --------------\n" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                linkedList.tambahTengah(nama, nim, posisi);
                break;
            case 4:
                cout << "\n-------------- UBAH DEPAN --------------\n" << endl;
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                linkedList.ubahDepan(nama, nim);
                break;
            case 5:
                cout << "\n-------------- UBAH BELAKANG --------------\n" << endl;
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                linkedList.ubahBelakang(nama, nim);
                break;
            case 6:
                cout << "\n-------------- UBAH TENGAH --------------\n" << endl;
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                linkedList.ubahTengah(nama, nim, posisi);
                break;
            case 7:
                linkedList.hapusDepan();
                break;
            case 8:
                linkedList.hapusBelakang();
                break;
            case 9:
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                linkedList.hapusTengah(posisi);
                break;
            case 10:

                linkedList.hapusList();
                break;
            case 11:

                linkedList.tampilkanData();
                break;
            case 0:

                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 0);

    return 0;
}
