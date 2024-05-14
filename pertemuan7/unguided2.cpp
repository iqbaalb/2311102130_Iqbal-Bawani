//IQBAL BAWANI
// 2311102130
// S1 IF-11-D

#include <iostream>
using namespace std;

const int maksimalQueue = 5;  // Maksimal antrian adalah 5

struct Node { // Node untuk menyimpan data dan pointer ke node berikutnya
    string Nama; // Menyimpan nama mahasiswa
    string NIM; // Menyimpan NIM mahasiswa
    Node* next; // Pointer ke node berikutnya
};

class Queue {
private:
    Node* front; // Node depan 
    Node* rear;  // Node belakang 

public: 
    Queue() { // Konstruktor untuk menginisialisasi antrian kosong
        front = nullptr; // Inisialisasi front dengan nullptr
        rear = nullptr; // Inisialisasi rear dengan nullptr
    }

    void enqueue_130(const string& Nama, const string& NIM) {
        Node* newNode = new Node; // Buat node baru
        newNode->Nama = Nama; // Isi data Nama pada node baru
        newNode->NIM = NIM; // Isi data NIM pada node baru
        newNode->next = nullptr; // Atur pointer next node baru menjadi nullptr
        
        // Jika antrian kosong
        if (isEmpty()) { // Jika antrian kosong maka front dan rear menunjuk ke newNode yang baru dibuat 
            front = rear = newNode;
        } else { // Jika antrian tidak kosong maka rear menunjuk ke newNode yang baru dibuat
            rear->next = newNode;
            rear = newNode;
        }
        
        cout << "Mahasiswa dengan Nama : " << newNode->Nama << "\ndengan NIM : " << newNode->NIM << " ditambahkan ke dalam antrian." << endl;
    }

    //menghapus data dari antrian
    void dequeue() {
        if (isEmpty()) { // Jika antrian kosong 
            cout << "Antrian kosong." << endl;
            return;
        }

        Node* temp = front; // Simpan node front ke dalam variabel temp untuk dihapus nantinya 
        front = front->next; // Geser front ke node selanjutnya 

        cout << "Mahasiswa dengan Nama : " << temp->Nama << "\ndengan NIM : " << temp->NIM << " dihapus dari antrian." << endl; // Tampilkan data mahasiswa yang dihapus dari antrian 
        delete temp; // Hapus node yang disimpan di variabel temp

        // Jika setelah penghapusan antrian menjadi kosong
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    //menampilkan seluruh antrian
    void displayQueue() {
        if (isEmpty()) { // Jika antrian kosong 
            cout << "\nData Antrian :" << endl;
            for (int i = 0; i < maksimalQueue; i++) {
                cout << i + 1 << ". (kosong)" << endl;
            }
        } else { // Jika antrian tidak kosong 
            cout << "\nData Antrian :" << endl;
            Node* current = front;
            int i = 1;
            while (current != nullptr) { // Selama current tidak menunjuk ke nullptr maka tampilkan data antrian yang ada 
                cout << i << ". " << "Nama : " << current->Nama << "\ndengan NIM : " << current->NIM << endl;
                current = current->next;
                i++;
            }
            for (; i <= maksimalQueue; i++) { // Tampilkan pesan "(kosong)" untuk antrian yang kosong 
                cout << i << ". (kosong)" << endl;
            }
        }
    }

    //memeriksa apakah antrian kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // mengembalikan jumlah elemen dalam antrian
    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) { 
            count++;
            current = current->next;
        }
        return count; // Kembalikan jumlah elemen dalam antrian
    }

    //menghapus semua elemen dalam antrian
    void clearQueue() {
        while (!isEmpty()) { // Selama antrian tidak kosong 
            dequeue(); // Hapus elemen dalam antrian 
        } 
        cout << "Antrian telah dibersihkan." << endl;
    }
};

int main() {
    Queue queue; // Buat objek queue dari class Queue
    queue.enqueue_130("Andi Maya", "2011102130");
    queue.enqueue_130("Iqbal bawani", "2311102130");
    queue.displayQueue();
    cout << "Jumlah Antrian = " << queue.countQueue() << endl;
    queue.dequeue();
    queue.displayQueue();
    cout << "Jumlah Antrian = " << queue.countQueue() << endl;
    queue.dequeue();
    queue.displayQueue();
    cout << "Jumlah Antrian = " << queue.countQueue() << endl;

    return 0;
}
