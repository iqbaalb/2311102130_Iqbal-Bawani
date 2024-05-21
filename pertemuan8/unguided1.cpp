//Iqbal Bawani
//2311102130
//S1IF11D

#include <iostream>
#include <conio.h>// UNTUK FUNGSI _getch()
#include <iomanip>

using namespace std;

// Fungsi untuk melakukan selection sort pada array karakter
void selectionsort_130(char dataarray[], int size) {
    int temp, min, i, j; // Deklarasi variabel
    for (i = 0; i < size - 1; i++) { // Loop untuk setiap elemen array
        min = i; // Set elemen pertama sebagai minimum
        for (j = i + 1; j < size; j++) { // Loop untuk elemen-elemen berikutnya
            if (dataarray[j] < dataarray[min]) { // Jika elemen j lebih kecil dari elemen min
                min = j; // Set elemen j sebagai minimum
            }
        }
        // Tukar elemen minimum dengan elemen pertama dari bagian yang belum terurut
        temp = dataarray[i]; // Simpan nilai elemen i di temp
        dataarray[i] = dataarray[min]; // Pindahkan elemen min ke posisi i
        dataarray[min] = temp; // Pindahkan nilai temp ke posisi min
    }
}

bool binarysearch_130(char dataarray[], int size, char cari) {
    int awal, akhir, tengah; // Deklarasi variabel untuk awal, akhir, dan tengah array
    bool b_flag = false; // Flag untuk menandai apakah elemen ditemukan
    awal = 0; // Inisialisasi awal array
    akhir = size - 1; // Inisialisasi akhir array

    while (!b_flag && awal <= akhir) { // Loop selama elemen belum ditemukan dan bagian array yang diperiksa valid
        tengah = (awal + akhir) / 2; // Hitung posisi tengah
        if (dataarray[tengah] == cari) { // Jika elemen di tengah adalah elemen yang dicari
            b_flag = true; // Set flag menjadi true untuk menunjukkan elemen ditemukan
        } else if (dataarray[tengah] < cari) { // Jika elemen di tengah lebih kecil dari elemen yang dicari
            awal = tengah + 1; // Pindahkan awal ke sebelah kanan tengah karena elemen yang dicari pasti ada di sebelah kanan
        } else { // Jika elemen di tengah lebih besar dari elemen yang dicari
            akhir = tengah - 1; // Pindahkan akhir ke sebelah kiri tengah karena elemen yang dicari pasti ada di sebelah kiri
        }
    }
    return b_flag; // Kembalikan hasil pencarian (true jika ditemukan, false jika tidak)
}


int main() {
    string kalimat;
    char dataarray[100]; // Array untuk menyimpan karakter dari kalimat
    char cari;
    int size; // Ukuran array

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Konversi kalimat menjadi array karakter dan tentukan ukurannya
    size = kalimat.length();
    for (int i = 0; i < size; i++) {
        dataarray[i] = kalimat[i];
    }

    // Urutkan array karakter
    selectionsort_130(dataarray, size);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> cari;

    // Cari huruf di dalam array
    if (binarysearch_130(dataarray, size, cari)) {
        cout << "Huruf '" << cari << "' ditemukan." << endl;
    } else {
        cout << "Huruf '" << cari << "' tidak ditemukan." << endl;
    }

    getch();
    return 0;
}