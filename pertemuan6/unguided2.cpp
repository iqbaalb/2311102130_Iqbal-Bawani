//Iqbal Bawani
//2311102130
//S1-IF-11D


#include <iostream>// library standart
#include <stack>//Library stack ,(Charstack)

using namespace std;

// Prosedur untuk membalikkan kalimat menggunakan stack
void palindrom_130(stack<char>& CharStack, const string& Kalimat) {  // Mengisi stack dengan setiap karakter dari string
    for (char c : Kalimat) {
        CharStack.push(c);
    }

    while (!CharStack.empty()) {  // Mengeluarkan karakter dari stack dan mencetaknya untuk membalikkan kalimat
        cout << CharStack.top();  // Mencetak karakter teratas dari stack
        CharStack.pop(); // Menghapus karakter teratas dari stack
    }
}

int main() {
    stack<char> CharStack; // Mendeklarasikan stack yang akan digunakan untuk membalikkan karakter-karakter dari kalimat
    char ulangi; // Variabel untuk menyimpan pilihan pengguna untuk mengulangi program atau tidak

    cout << "\n------- PROGRAM PALINDROM ------" << endl; // Menampilkan pesan pembuka program

    do {
        string Kalimat; // Variabel untuk menyimpan kalimat yang dimasukkan oleh pengguna
        cout << " Masukkan kalimat 3 kata : "; // Meminta pengguna untuk memasukkan kalimat
        getline(cin, Kalimat); // Membaca kalimat yang dimasukkan oleh pengguna

        cout << "Hasil kalimat yang dibalikkan : "; // Menampilkan pesan sebelum mencetak hasil pembalikan kalimat
        palindrom_130(CharStack, Kalimat); // Memanggil fungsi untuk membalikkan kalimat dan mencetak hasilnya
        cout << endl; // Menampilkan baris baru setelah hasil pembalikan kalimat

        cout << "Ketik y untuk ulangi program, atau n untuk menghentikan program : "; // Meminta pengguna untuk memilih apakah akan mengulangi program atau tidak
        cin >> ulangi; // Membaca pilihan pengguna
        cin.ignore(); // Mengabaikan karakter newline ('\n') yang tersisa di buffer input
    } while (ulangi == 'y'); // Melakukan loop selama pengguna ingin mengulangi program

    return 0; // Mengakhiri program dengan nilai kembali 0
}




