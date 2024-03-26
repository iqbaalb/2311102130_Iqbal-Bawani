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
