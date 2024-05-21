//Iqbal Bawani
//2311102130
//S1IFF11D
#include<iostream>    
using namespace std;  

int main() {
    string kalimat;            // Deklarasi string untuk menyimpan kalimat yang diinput
    int banyakvokal_130 = 0;       // Deklarasi dan inisialisasi variabel untuk menghitung jumlah huruf vokal

    cout << "Masukkan kalimat: "; // Minta user untuk memasukkan kalimat
    getline(cin, kalimat);        // Baca seluruh kalimat yang diinput user

    for (int i = 0; i < kalimat.length(); i++) { // Loop untuk setiap karakter dalam kalimat
        char huruf = tolower(kalimat[i]);        // Konversi karakter ke huruf kecil

        // Cek apakah karakter adalah salah satu huruf vokal (a, i, u, e, o)
        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
            banyakvokal_130++;        // Jika ya, increment jumlah vokal
        }
    }

    // Cetak jumlah huruf vokal yang ditemukan dalam kalimat
    cout << "Jumlah huruf vokal dalam kalimat: " << banyakvokal_130 << endl;

    return 0; // Kembalikan 0 untuk menandakan program selesai dengan sukses
}
