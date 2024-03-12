
//IQBALBAWANI-2311102130

#include <iostream>
#include <map>

using namespace std;

// Struktur data untuk menyimpan informasi calon DPR
struct CalonDPR {
    string nama;
    string partai;
};

int main() {
    // Deklarasi map dengan key int dan value berupa objek CalonDPR
    map<int, CalonDPR> calonDPR_2130;

    // Menambahkan data calon DPR ke dalam map
    calonDPR_2130[1] = {"Justin Bieber", "Partai Harapan Bangsa"};
    calonDPR_2130[2] = {"Neymar Junior", "Partai Kemajuan Bersama"};
    calonDPR_2130[3] = {"Zilong Tzy", "Partai Merpati"};
    calonDPR_2130[4] = {"Jaka Widada", "Partai Durian Runtuh"};
    calonDPR_2130[5] = {"Patrick", "Partai Bumi Sejahtera"};

    cout << "-=-= Calon DPR Terpilih =-=-" << endl;
    // perulangan for untuk menampilkan MAP//
    for (int i = 1; i <= calonDPR_2130.size(); ++i) {
        cout << "Nomor " << i << "  Atas Nama: " << calonDPR_2130[i].nama << ",  Dari: " << calonDPR_2130[i].partai << endl;
    }

    return 0;
}
