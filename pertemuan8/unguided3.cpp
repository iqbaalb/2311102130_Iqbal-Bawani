//Iqbal Bawani
//2311102130
// S1IF11D
#include <iostream> 
using namespace std; 

// Fungsi sequentialSearch_130 untuk mencari jumlah kemunculan target dalam array data
int sequentialSearch_130(int data[], int n, int target) {
    int hitung = 0; // Inisialisasi variabel count untuk menghitung jumlah kemunculan target
    for (int i = 0; i < n; i++) { // Loop untuk setiap elemen dalam array data
        if (data[i] == target) { // Jika elemen saat ini sama dengan target
            hitung++; // Increment count
        }
    }
    return hitung; // Mengembalikan jumlah kemunculan target dalam array data
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Deklarasi dan inisialisasi array data
    int a = sizeof(data) / sizeof(data[0]); // Hitung jumlah elemen dalam array data
    int target = 4; // Target yang akan dicari dalam array data

    // Panggil fungsi sequentialSearch untuk mencari jumlah kemunculan target dalam array data
    int hitung = sequentialSearch_130(data, a, target);

    // Cetak hasil pencarian
    cout << "Pada data: 9, 4, 1, 4, 7, 10, 5, 4, 12, 4" << endl;
    cout << "Banyak angka 4 di dalam data adalah: " << hitung << endl;

    return 0; // Kembalikan 0 untuk menandakan program selesai dengan sukses
}
