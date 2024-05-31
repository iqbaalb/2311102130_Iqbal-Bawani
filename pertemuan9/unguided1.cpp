
// IQBAL BAWANI
// 2311102130

#include <iostream>
#include <vector> // Pustaka untuk penggunaan kontainer vector
#include <string> // Pustaka untuk penggunaan tipe data string

using namespace std;

int main()
{
    int banyaksimpul_2311102130; // Deklarasi variabel untuk menyimpan jumlah simpul

    cout << "\n------- Menghitung Jarak Antar kota -------" << endl;

    cout << "\nSilakan masukan jumlah simpul : "; // Meminta pengguna memasukkan jumlah simpul
    cin >> banyaksimpul_2311102130;

    // Mendeklarasikan vektor untuk menyimpan nama-nama simpul
    vector<string> namasimpul(banyaksimpul_2311102130);
    // Mendeklarasikan matriks untuk menyimpan bobot (jarak) antar simpul
    vector<vector<int>> bobot(banyaksimpul_2311102130, vector<int>(banyaksimpul_2311102130));

    // Meminta pengguna memasukkan nama-nama simpul
    cout << "Silakan masukan nama simpul" << endl;
    for (int i = 0; i < banyaksimpul_2311102130; ++i)
    {
        // Meminta input nama simpul dari pengguna
        cout << "Simpul " << i + 1 << " : ";
        cin >> namasimpul[i]; // Membaca input nama simpul dan menyimpannya ke dalam vektor
    }

    // Meminta pengguna memasukkan bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < banyaksimpul_2311102130; ++i)
    {
        for (int j = 0; j < banyaksimpul_2311102130; ++j)
        {
            // Meminta input bobot (jarak) dari simpul i ke simpul j
            cout << namasimpul[i] << "--> " << namasimpul[j] << " = ";
            cin >> bobot[i][j]; // Membaca input bobot dan menyimpannya ke dalam matriks
        }
    }

    cout << endl; // Menambahkan baris baru untuk tampilan yang lebih rapi

    // Menampilkan tabel jarak antar simpul
    cout << "     "; 
    for (const string &Nama_2311102138 : namasimpul)
    {
        cout << Nama_2311102138 << "  "; // Menampilkan nama-nama simpul sebagai header kolom
    }
    cout << endl;

    for (int i = 0; i < banyaksimpul_2311102130; ++i)
    {
        cout << namasimpul[i] << "     "; // Menampilkan nama simpul sebagai header baris
        for (int j = 0; j < banyaksimpul_2311102130; ++j)
        {
            cout << bobot[i][j] << "  "; // Menampilkan bobot (jarak) antar simpul
        }
        cout << endl;
    }

    return 0; // Mengembalikan nilai 0 untuk menandakan program berakhir dengan sukses
}
