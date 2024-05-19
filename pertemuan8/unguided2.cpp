#include<iostream>
#include<string>

using namespace std;

int main() {
    string kalimat;
    int jumlahVocal = 0;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    for (int i = 0; i < kalimat.length(); i++) {
        char huruf = tolower(kalimat[i]); // convert to lowercase

        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
            jumlahVocal++;
        }
    }

    cout << "Jumlah huruf vocal dalam kalimat: " << jumlahVocal << endl;

    return 0;
}
