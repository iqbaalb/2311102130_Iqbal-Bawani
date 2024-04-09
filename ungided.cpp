#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struck untuk setiap mahasiswa
struct Mahasiswa{
    string nama;
    string nimiqbal;
    int nilai_130;
};

//struck untuk setiap node dalam hash table
struct HashNode{
    Mahasiswa data;
    HashNode* next;
    HashNode(const Mahasiswa& data) : data(data), next(nullptr){}
};

// Kelas HashTable digunakan untuk merepresentasikan hash table yang menyimpan data mahasiswa.
class HashTable{
    private:
    static const int TABLE_SIZE = 10;// Ukuran tetap dari hash table
    vector<HashNode*>table[TABLE_SIZE];   // Array dari vektor HashNode* untuk menyimpan data dalam hash table

    // Fungsi hashFunc digunakan untuk menghasilkan indeks dalam hash table berdasarkan NIM mahasiswa.
    int hashFunc(const string& nimiqbal){
       
        int hashVal = 0;  // Menginisialisasi nilai hashVal sebagai 0
        // Mengiterasi melalui setiap karakter dalam NIM mahasiswa
        for(char c : nimiqbal){
            // Menambahkan nilai ASCII dari setiap karakter ke hashVal
            hashVal += c;
        }
        // Mengembalikan hasil modulus dari hashVal dengan ukuran hash table untuk mendapatkan indeks
        return hashVal % TABLE_SIZE;
    }

    public:
    // untuk menambahkan data mahasiswa kedalam hash table
    void insert(const Mahasiswa& mahasiswa){
        int index = hashFunc(mahasiswa.nimiqbal);
        HashNode* newNode = new HashNode(mahasiswa);
        newNode->next = table[index].size() > 0 ? table[index][0] : nullptr;
        table[index].insert(table[index].begin(),newNode);
    }
    //fungsi menghapus data mahasiswa  berdasarkan NIM
    void hapus(const string& nim){
        int index = hashFunc(nim);
        for(size_t i=0; i<table[index].size(); i++){
            if(table[index][i]->data.nimiqbal== nim){
                delete table[index][i];
                table[index].erase(table[index].begin()+i);
                return;
            }
        }
        cout << " mahasiswa  NIM : " << nim << " tidak ada" <<endl;
    }

    //fungsi untuk mencari data mahasiswa berdasarkan NIM
    Mahasiswa* caridarinim (const string& nim){
        int index = hashFunc(nim);
        for(size_t i = 0; i <table[index].size(); i++){
            if(table[index][i]->data.nimiqbal == nim){
                return &(table[index][i]->data);
            }
        }
        return nullptr;
    }

    // Fungsi mencari data mahasiswa berdasarkan rentang nilai
    vector<Mahasiswa*> caridarinilai(int minNilai, int maxNilai){
        vector<Mahasiswa*> result;
        for(int i = 0; i < TABLE_SIZE; i++){
            for(size_t j = 0; j < table[i].size(); j++){
                if(table[i][j]->data.nilai_130 >= minNilai && table[i][j]->data.nilai_130 <= maxNilai){
                    result.push_back(&(table[i][j]->data));
                }
            }
        }
        return result;
    }

    //Fungsi menampilkan semua data
    void tampilkan(){
        cout << "Data Mahasiswa yang ada dalam Hash Table : "<<endl;
        for(int i = 0; i < TABLE_SIZE; i++){
            for (size_t j = 0; j < table[i].size(); j++){
                Mahasiswa* mhs = &(table[i][j]->data);
                cout << "Nama Mahasiswa: " << mhs->nama << "\tNIM: " << mhs->nimiqbal << "\tNilai: " << mhs->nilai_130 << endl;
            }
        }
    }

};

int main(){
    HashTable hashTable;
    int pilih;

    menu:
    cout << "\n------- PROGRAM HASH TABLE  -------" << endl;
    cout << "1. Tambah data Mahasiswa"<<endl;
    cout << "2. Hapus data Mahasiswa"<<endl;
    cout << "3. Cari data Mahasiswa berdasarkan NIM"<<endl;
    cout << "4. Cari data Mahasiswa berdsarkan rentang nilai"<<endl;
    cout << "5. Tampilkan semua data"<<endl;
    cout << "6. Keluar"<<endl;
    cout << "Pilih menu diatas : "; cin >> pilih;
    cout << endl;

    switch(pilih){
        case 1 :{
            // menambahkan data mahasiswa
            Mahasiswa mhs;
            cout << "-TAMBAH DATA MAHASISWA-"<<endl;
            cout << "Nama Mahasiswa : ";
            cin >> mhs.nama;
            cout << "NIM Mahasiswa : ";
            cin >> mhs.nimiqbal;
            cout << "Nilai Mahasiswa : ";
            cin >> mhs.nilai_130;
            hashTable.insert(mhs);
            goto menu;
            cout << endl;
            break;
        }
        case 2 :{
            // menghapus data mahasiswa
            string nim;
            cout << "-HAPUS DATA MAHASISWA-"<<endl;
            cout << "Masukkan NIM untuk menghapus data Mahasiswa : ";
            cin >> nim;
            hashTable.hapus(nim);
            cout << " Mahasiswa NIM : " << nim << " dihapus"<<endl;
            goto menu;
            cout << endl;
            break;
        }
        case 3 :{
            // Mencari data mahasiswa berdasarkan NIM
            string nim;
            cout << "-CARI DATA MAHASISWA BERDASARKAN NIM-"<<endl;
            cout << "Masukkan NIM untuk mencari data Mahasiswa: ";
            cin >> nim;
            Mahasiswa* result = hashTable  .caridarinim(nim);
            if(result != nullptr){
                cout << "Data ditemukan!!"<<endl;
                cout << "Nama: " << result->nama << "\nNIM: " << result->nimiqbal << "\nNilai: " << result->nilai_130 <<endl;
            }else{
                cout << "Mahasiswa NIM " << nim << "Tidak ada"<<endl;
            }
            goto menu;
            cout << endl;
            break;
        }
        case 4 :{
            // mencari data mahasiswa berdasarkan rentang nilai (rentang nilai diinputkan user)
            int minNilai , maxNilai ;
            cout << "Masukan nilai mahasiswa yang ingin dicari!"<<endl;
            cout << "Nilai minimal : "; 
            cin >> minNilai;
            cout << "Nilai maksimal : ";
            cin >> maxNilai;
            cout << "Rentang nilai  " << minNilai << " hingga " << maxNilai << endl;
            vector<Mahasiswa*> result = hashTable.caridarinilai(minNilai, maxNilai);
            if(result.size() > 0){
                cout << "Data mahasiswa nilai " << minNilai << " hingga " << maxNilai << ":\n";
                for(Mahasiswa* mhs : result){
                    cout << "Nama Mahasiswa: " << mhs->nama << "\tNIM: " << mhs->nimiqbal << "\tNilai: "<< mhs->nilai_130 <<endl;
                }
            }else{
                cout << "Tidak ada mahasiswa "<<endl;
            }
            goto menu;
            cout << endl;
            break;
        }
        case 5 :{   
            hashTable.tampilkan();
            goto menu;
            cout << endl;
            break;
        }
        case 6 :
            cout << "Anda keluar dari program!"<<endl;
            break;
        default :
            cout << "Masukan pilihan yang ada "<<endl;
            goto menu;
    }
    return 0;
}