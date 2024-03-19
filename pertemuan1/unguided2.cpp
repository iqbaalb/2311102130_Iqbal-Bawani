
//IQBALBAWANI-2311102130

#include <iostream>
using namespace std;

// Deklarasi struct
struct NilaiPelajaran {
    int mtk_130;
    int bing_130;
};

// Deklarasi class
class Mahasiswa {
public:
    string nama;
    NilaiPelajaran nilai; // Objek struct sebagai anggota class

    void display() {
        cout << "Nama: " << nama << endl;
        cout << "Nilai Matematika: " << nilai.mtk_130 << endl;
        cout << "Nilai Bahasa Inggris: " << nilai.bing_130 << endl;
    }
};

int main() {
    // Membuat objek John Doe menggunakan struct
    NilaiPelajaran nilaimhs;
    nilaimhs.mtk_130 = 90;
    nilaimhs.bing_130 = 85;

    // Membuat objek Mahasiswa menggunakan class
    Mahasiswa _130;
    _130.nama = "Mario Teguh";
    _130.nilai = nilaimhs;

    // Menampilkan informasi mahasiswa
    _130.display();

    return 0;
}
