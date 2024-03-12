#include <iostream>

using namespace std;

float angkaalas_130, angkabulat_130, angkapanjang_130;
char hurufkoma_130;

// Fungsi untuk menampilkan menu perhitungan
void tampilanmenu_130() {
    cout << "-----Menu Perhitungan-----" << endl;
    cout << "a. Hitung Luas Segitiga" << endl;
    cout << "b. Hitung Luas Persegi" << endl;
    cout << "Silahkan pilih (a/b): ";
    cin >> hurufkoma_130;
}

// Fungsi untuk menghitung luas segitiga
float hitungluassegitiga_130() {
    cout << "Masukkan alas: ";
    cin >> angkaalas_130;
    cout << "Masukkan tinggi: ";
    cin >> angkabulat_130;
    cout << "Hasil menghitung luas segitiga: ";
    return 0.5 * angkaalas_130 * angkabulat_130;
}

// Fungsi untuk menghitung luas persegi
float hitungluaspersegi_130() {
    cout << "Masukkan panjang sisi: ";
    cin >> angkapanjang_130;
    cout << "Hasil menghitung luas persegi: ";
    return angkapanjang_130 * angkapanjang_130;
}

int main() {
    // Memanggil fungsi tampilanmenu_130 untuk menampilkan pilihan menu
    tampilanmenu_130();

    // Melakukan seleksi berdasarkan pilihan menu yang dimasukkan pengguna
    switch (hurufkoma_130) {
    case 'a':
        // Memanggil fungsi hitungluassegitiga_130 jika pilihan menu adalah 'a'
        cout << "Perhitungan luas segitiga:\n" << hitungluassegitiga_130() << endl;
        break;
    case 'b':
        // Memanggil fungsi hitungluaspersegi_130 jika pilihan menu adalah 'b'
        cout << "Perhitungan luas persegi:\n" << hitungluaspersegi_130() << endl;
        break;
    default:
        // Menampilkan pesan jika pilihan menu tidak valid
        cout << "Menu tidak valid." << endl;
        break;
    }

    return 0;
}



