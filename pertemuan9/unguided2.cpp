#include<iostream>
#include <iomanip>
#include <queue>
using namespace std;

// Struktur Pohon
struct Pohon {
    char data;
    Pohon *Kiri, *Kanan, *Parent_2311102130;
};
Pohon *Root, *Baru;

// Inisialisasi Root
void init_2311102130() {
    Root = NULL;
}

// Cek apakah tree kosong
bool isEmpty() {
    return Root == NULL;
}

// buatNode Baru sebagai Root
void buatNode_130(char data) {
    if (isEmpty()) {
        Root = new Pohon();
        Root->data = data;
        Root->Kiri = NULL;
        Root->Kanan = NULL;
        Root->Parent_2311102130 = NULL;
        cout << "\n[] Node " << data << " berhasil dibuat sebagai root." << endl;
    } else {
        cout << "\n[] Tree sudah ada!" << endl;
    }
}

// Insert Node ke kiri
Pohon *insertKiri(char data, Pohon *Node) {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (Node->Kiri != NULL) {
            cout << "\n[] Node " << Node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *Baru = new Pohon();
            Baru->data = data;
            Baru->Kiri = NULL;
            Baru->Kanan = NULL;
            Baru->Parent_2311102130 = Node;
            Node->Kiri = Baru;
            cout << "\n[] Node " << data << " berhasil ditambahkan ke child kiri " << Baru->Parent_2311102130->data << endl;
            return Baru;
        }
    }
}

// Insert Node ke kanan
Pohon *insertKanan(char data, Pohon *Node) {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (Node->Kanan != NULL) {
            cout << "\n[] Node " << Node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *Baru = new Pohon();
            Baru->data = data;
            Baru->Kanan = NULL;
            Baru->Parent_2311102130 = Node;
            Node->Kanan = Baru;
            cout << "\n[] Node " << data << " berhasil ditambahkan ke child kanan " << Baru->Parent_2311102130->data << endl;
            return Baru;
        }
    }
}

// Update Data
void update(char data, Pohon *Node) {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
    } else {
        if (!Node) {
            cout << "\n[] Node yang ingin diganti tidak ada!" << endl;
        } else {
            char temp = Node->data;
            Node->data = data;
            cout << "\n[] Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Retrieve 
void retrieve(Pohon *Node) {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
    } else {
        if (!Node) {
            cout << "\n[] Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n[] Data Node : " << Node->data << endl;
        }
    }
}

// Find Node dan menampilkan informasi lengkap
void find(Pohon *Node) {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
    } else {
        if (!Node) {
            cout << "\n[] Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n[] Data Node : " << Node->data << endl;
            cout << "[] Root : " << Root->data << endl;
            if (!Node->Parent_2311102130)
                cout << "[] Parent : (tidak punya parent)" << endl;
            else
                cout << "[] Parent : " << Node->Parent_2311102130->data << endl;
            if (Node->Parent_2311102130 != NULL && Node->Parent_2311102130->Kiri != Node && Node->Parent_2311102130->Kanan == Node)
                cout << "[] Sibling : " << Node->Parent_2311102130->Kiri->data << endl;
            else if (Node->Parent_2311102130 != NULL && Node->Parent_2311102130->Kanan != Node && Node->Parent_2311102130->Kiri == Node)
                cout << "[] Sibling : " << Node->Parent_2311102130->Kanan->data << endl;
            else
                cout << "[] Sibling : (tidak punya sibling)" << endl;
            if (!Node->Kiri)
                cout << "[] Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "[] Child Kiri : " << Node->Kiri->data << endl;
            if (!Node->Kanan)
                cout << "[] Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "[] Child Kanan : " << Node->Kanan->data << endl;
        }
    }
}

// Pre-order traversal
void preOrder(Pohon *Node = Root) {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
    } else {
        if (Node != NULL) {
            cout << " " << Node->data << ", ";
            preOrder(Node->Kiri);
            preOrder(Node->Kanan);
        }
    }
}

// In-order traversal
void inOrder(Pohon *Node = Root) {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
    } else {
        if (Node != NULL) {
            inOrder(Node->Kiri);
            cout << " " << Node->data << ", ";
            inOrder(Node->Kanan);
        }
    }
}

// Post-order traversal
void postOrder(Pohon *Node = Root) {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
    } else {
        if (Node != NULL) {
            postOrder(Node->Kiri);
            postOrder(Node->Kanan);
            cout << " " << Node->data << ", ";
        }
    }
}

// Hapus tree secara rekursif
void deleteTree(Pohon *Node) {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
    } else {
        if (Node != NULL) {
            if (Node != Root) {
                Node->Parent_2311102130->Kiri = NULL;
                Node->Parent_2311102130->Kanan = NULL;
            }
            deleteTree(Node->Kiri);
            deleteTree(Node->Kanan);
            if (Node == Root) {
                delete Root;
                Root = NULL;
            } else {
                delete Node;
            }
        }
    }
}

// Hapus subtree dari Node tertentu
void deleteSub(Pohon *Node) {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(Node->Kiri);
        deleteTree(Node->Kanan);
        cout << "\n[] Node subtree " << Node->data << " berhasil dihapus." << endl;
    }
}

// Hapus seluruh tree
void clear() {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(Root);
        cout << "\n[] Pohon berhasil dihapus." << endl;
    }
}

// Hitung size tree
int size(Pohon *Node = Root) {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!Node) {
            return 0;
        } else {
            return 1 + size(Node->Kiri) + size(Node->Kanan);
        }
    }
}

// Hitung height tree
int height(Pohon *Node = Root) {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!Node) {
            return 0;
        } else {
            int heightKiri = height(Node->Kiri);
            int heightKanan = height(Node->Kanan);
            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }
}

// Tampilkan karakteristik tree
void characteristic() {
    cout << "\n>> Ukuran Tree : " << size() << endl;
    cout << ">> Tinggi Tree : " << height() << endl;
    cout << ">> Rata-rata Node di Tree : " << size() / height() << endl;
}

// Tampilkan child dan descendant dari Node tertentu
void showChildAndDescendant(Pohon *Node) {
    if (isEmpty()) {
        cout << "\n[] Buat tree terlebih dahulu!" << endl;
    } else if (!Node) {
        cout << "\n[] Node yang ditunjuk tidak ada!" << endl;
    } else {
        // Tampilkan child
        cout << "\n[] Node : " << Node->data << endl;
        if (Node->Kiri != NULL) {
            cout << "Child Kiri : " << Node->Kiri->data << endl;
        } else {
            cout << "Child Kiri : NULL" << endl;
        }
        if (Node->Kanan != NULL) {
            cout << "Child Kanan : " << Node->Kanan->data << endl;
        } else {
            cout << "Child Kanan : NULL" << endl;
        }
        // Tampilkan descendant
        cout << "Descendant : ";
        queue<Pohon *> q;
        if (Node->Kiri != NULL) {
            q.push(Node->Kiri);
        }
        if (Node->Kanan != NULL) {
            q.push(Node->Kanan);
        }
        while (!q.empty()) {
            Pohon *current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->Kiri != NULL) {
                q.push(current->Kiri);
            }
            if (current->Kanan != NULL) {
                q.push(current->Kanan);
            }
        }
        cout << endl;
    }
}

int main() {
    int Pilihan;
    char data, dataUpdate;
    Pohon *Node = NULL;
    init_2311102130();

    do {
        cout << "\n------ Menu Binary Tree -------\n";
        cout << "[1] Buat Root\n";
        cout << "[2] Tambah Child Kiri\n";
        cout << "[3] Tambah Child Kanan\n";
        cout << "[4] Update Node\n";
        cout << "[5] Retrieve Node\n";
        cout << "[6] Find Node\n";
        cout << "[7] Pre-order Traversal\n";
        cout << "[8] In-order Traversal\n";
        cout << "[9] Post-order Traversal\n";
        cout << "[10] Hapus Tree\n";
        cout << "[11] Hapus Subtree\n";
        cout << "[12] Tampilkan Karakteristik Tree\n";
        cout << "[13] Tampilkan Child dan Descendant\n";
        cout << "[0] Keluar\n";
        cout << "Pilih menu: ";
        cin >> Pilihan;

        switch (Pilihan) {
        case 1:
            cout << "\n[1] Buat Root" << endl;
            if (isEmpty()) {
                cout << "Masukkan data: ";
                cin >> data;
                buatNode_130(data);
            } else {
                cout << "\n[] Root sudah ada!" << endl;
            }
            break;
        case 2:
            cout << "\n[2] Tambah Child Kiri" << endl;
            if (isEmpty()) {
                cout << "\n[] Buat tree terlebih dahulu!" << endl;
            } else {
                cout << "Masukkan data parent: ";
                cin >> data;
                queue<Pohon *> q;
                q.push(Root);
                while (!q.empty()) {
                    Pohon *current = q.front();
                    q.pop();
                    if (current->data == data) {
                        Node = current;
                        break;
                    }
                    if (current->Kiri)
                        q.push(current->Kiri);
                    if (current->Kanan)
                        q.push(current->Kanan);
                }
                if (Node) {
                    cout << "Masukkan data child kiri: ";
                    cin >> data;
                    insertKiri(data, Node);
                } else {
                    cout << "\n[] Parent tidak ditemukan!" << endl;
                }
            }
            break;
        case 3:
            cout << "\n[3] Tambah Child Kanan" << endl;
            if (isEmpty()) {
                cout << "\n[] Buat tree terlebih dahulu!" << endl;
            } else {
                cout << "Masukkan data parent: ";
                cin >> data;
                queue<Pohon *> q;
                q.push(Root);
                while (!q.empty()) {
                    Pohon *current = q.front();
                    q.pop();
                    if (current->data == data) {
                        Node = current;
                        break;
                    }
                    if (current->Kiri)
                        q.push(current->Kiri);
                    if (current->Kanan)
                        q.push(current->Kanan);
                }
                if (Node) {
                    cout << "Masukkan data child kanan: ";
                    cin >> data;
                    insertKanan(data, Node);
                } else {
                    cout << "\n[] Parent tidak ditemukan!" << endl;
                }
            }
            break;
        case 4:
            cout << "\n[4] Update Node" << endl;
            if (isEmpty()) {
                cout << "\n[] Buat tree terlebih dahulu!" << endl;
            } else {
                cout << "Masukkan data node yang akan diupdate: ";
                cin >> data;
                cout << "Masukkan data baru: ";
                cin >> dataUpdate;
                queue<Pohon *> q;
                q.push(Root);
                while (!q.empty()) {
                    Pohon *current = q.front();
                    q.pop();
                    if (current->data == data) {
                        Node = current;
                        break;
                    }
                    if (current->Kiri)
                        q.push(current->Kiri);
                    if (current->Kanan)
                        q.push(current->Kanan);
                }
                if (Node) {
                    update(dataUpdate, Node);
                } else {
                    cout << "\n[] Node tidak ditemukan!" << endl;
                }
            }
            break;
        case 5:
            cout << "\n[5] Retrieve Node" << endl;
            if (isEmpty()) {
                cout << "\n[] Buat tree terlebih dahulu!" << endl;
            } else {
                cout << "Masukkan data node yang akan ditampilkan: ";
                cin >> data;
                queue<Pohon *> q;
                q.push(Root);
                while (!q.empty()) {
                    Pohon *current = q.front();
                    q.pop();
                    if (current->data == data) {
                        Node = current;
                        break;
                    }
                    if (current->Kiri)
                        q.push(current->Kiri);
                    if (current->Kanan)
                        q.push(current->Kanan);
                }
                if (Node) {
                    retrieve(Node);
                } else {
                    cout << "\n[] Node tidak ditemukan!" << endl;
                }
            }
            break;
        case 6:
            cout << "\n[6] Find Node" << endl;
            if (isEmpty()) {
                cout << "\n[] Buat tree terlebih dahulu!" << endl;
            } else {
                cout << "Masukkan data node yang akan dicari: ";
                cin >> data;
                queue<Pohon *> q;
                q.push(Root);
                while (!q.empty()) {
                    Pohon *current = q.front();
                    q.pop();
                    if (current->data == data) {
                        Node = current;
                        break;
                    }
                    if (current->Kiri)
                        q.push(current->Kiri);
                    if (current->Kanan)
                        q.push(current->Kanan);
                }
                if (Node) {
                    find(Node);
                } else {
                    cout << "\n[] Node tidak ditemukan!" << endl;
                }
            }
            break;
        case 7:
            cout << "\n[7] Pre-order Traversal" << endl;
            preOrder();
            break;
        case 8:
            cout << "\n[8] In-order Traversal" << endl;
            inOrder();
            break;
        case 9:
            cout << "\n[9] Post-order Traversal" << endl;
            postOrder();
            break;
        case 10:
            cout << "\n[10] Hapus Tree" << endl;
            clear();
            break;
        case 11:
            cout << "\n[11] Hapus Subtree" << endl;
            if (isEmpty()) {
                cout << "\n[] Buat tree terlebih dahulu!" << endl;
            } else {
                cout << "Masukkan data node untuk subtree yang akan dihapus: ";
                cin >> data;
                queue<Pohon *> q;
                q.push(Root);
                while (!q.empty()) {
                    Pohon *current = q.front();
                    q.pop();
                    if (current->data == data) {
                        Node = current;
                        break;
                    }
                    if (current->Kiri)
                        q.push(current->Kiri);
                    if (current->Kanan)
                        q.push(current->Kanan);
                }
                if (Node) {
                    deleteSub(Node);
                } else {
                    cout << "\n[] Node tidak ditemukan!" << endl;
                }
            }
            break;
        case 12:
            cout << "\n[12] Tampilkan Karakteristik Tree" << endl;
            characteristic();
            break;
        case 13:
            cout << "\n[13] Tampilkan Child dan Descendant" << endl;
            if (isEmpty()) {
                cout << "\n[] Buat tree terlebih dahulu!" << endl;
            } else {
                cout << "Masukkan data node untuk menampilkan Child dan Descendant: ";
                cin >> data;
                queue<Pohon *> q;
                q.push(Root);
                while (!q.empty()) {
                    Pohon *current = q.front();
                    q.pop();
                    if (current->data == data) {
                        Node = current;
                        break;
                    }
                    if (current->Kiri)
                        q.push(current->Kiri);
                    if (current->Kanan)
                        q.push(current->Kanan);
                }
                if (Node) {
                    showChildAndDescendant(Node);
                } else {
                    cout << "\n[] Node tidak ditemukan!" << endl;
                }
            }
            break;
        case 0:
            cout << "\n[0] Keluar" << endl;
            break;
        default:
            cout << "\n[] Pilihan tidak valid!" << endl;
            break;
        }
    } while (Pilihan != 0);

    return 0;
}
