#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

void selectionsort_130(char dataarray[], int size) {
    int temp, min, i, j;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (dataarray[j] < dataarray[min]) {
                min = j;
            }
        }
        // Tukar elemen
        temp = dataarray[i];
        dataarray[i] = dataarray[min];
        dataarray[min] = temp;
    }
}

bool binarysearch_130(char dataarray[], int size, char cari) {
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = size - 1;

    while (!b_flag && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (dataarray[tengah] == cari) {
            b_flag = true;
        } else if (dataarray[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    return b_flag;
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