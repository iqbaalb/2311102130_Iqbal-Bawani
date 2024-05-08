
// Iqbal Bawani
// 2311102138
// S1 IF-11-D

#include <iostream>//library standart
#include <stack>// linbrary stack

using namespace std;

// Fungsi untuk mengecek apakah sebuah string merupakan palindrom atau bukan
bool Palindrom(string Kata) { // Mendefinisikan fungsi Palindrom dengan parameter string Kata
    stack<char> StackKata; // Membuat objek stack untuk menyimpan karakter-karakter dari string Kata
    int Length = Kata.length(); // Menghitung panjang string Kata

    // Menyimpan setengah pertama kata dalam tumpukan
    for (int i = 0; i < Length / 2; i++) { // Melakukan iterasi untuk setengah pertama dari panjang kata
        StackKata.push(Kata[i]); // Menyimpan karakter ke dalam tumpukan
    }
    
    int Mulai = Length / 2; // Inisialisasi variabel Mulai dengan setengah panjang kata.
    if (Length % 2 != 0) { // Jika panjang kata ganjil, tambahkan 1 ke nilai Mulai.
        Mulai++;
    }


    // Membandingkan setengah kedua kata dengan isi tumpukan
    for (int i = Mulai; i < Length; i++) {
        if (StackKata.empty() || Kata[i] != StackKata.top()) {
            return false; // Jika terdapat perbedaan, bukan palindrom
        }
        StackKata.pop(); // Lanjut ke karakter berikutnya
    }

    return true; // Jika berhasil melewati semua pengecekan, kata merupakan palindrom
}

int main() {
    char ulangi;
    cout << "\n------- PROGRAM PALINDROM ------" << endl;
    // Memulai perulangan untuk menginput dan mengecek kalimat palindrom
    do {
        string Kata;
        cout << "\nMasukkan kalimat : ";
        getline(cin, Kata); // Meminta pengguna untuk memasukkan sebuah kalimat

        // Memanggil fungsi Palindrom() untuk mengecek apakah kalimat tersebut adalah palindrom atau bukan
        if (Palindrom(Kata)) {
            cout << "Kalimat tersebut adalah : Palindrom" << endl;
        } else {
            cout << "Kalimat tersebut adalah : Bukan Palindrom" << endl;
        }
        // ulangi program
        cout << "Ketik y untuk ulangi pprogram, atau n untuk menghentikan program : ";
        cin >> ulangi;
        cin.ignore(); // Membersihkan newline character dari input buffer
    } while (ulangi == 'y' ); // Melakukan perulangan selama pengguna ingin mencoba kalimat lain

    return 0; // Mengakhiri program
}
