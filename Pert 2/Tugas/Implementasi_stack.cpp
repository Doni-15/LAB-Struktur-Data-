#include <iostream>
using namespace std;

struct NODE{
    int nilai;
    NODE *prev;
};

// Inisialisai awal
NODE *head = NULL;
NODE *tail = NULL;

/*Stack = LIFO*/
void MasukkanNilai(int inputan);
void HapusDariStack();
void TampilkanStack();


#define MAX_INPUTAN 3

int main(){
    system("cls");
    int input, i = 0;

    // Perintah 1 : Push 3 angka
    while (i < MAX_INPUTAN){
        cout << "Masukkan nilai ke - " << i + 1 << " : "; cin >> input;
        MasukkanNilai(input);
        i++;
    }

    TampilkanStack();
    
    // Perintah 2 : Pop 1 angka
    cout << "\nHapus Nilai Belakang Stack ";
    HapusDariStack();
    TampilkanStack();
}

void MasukkanNilai(int inputan){
    NODE *node_inputan = new NODE;
    node_inputan -> nilai = inputan;
    node_inputan -> prev = head;
    head = node_inputan;
}

void HapusDariStack(){
    if(head == NULL){
        cout << "[EROR]: Isi stack masih kosong\n";
        return;
    }

    // Merujuk node yang sama
    if(head == tail){
        delete head;
        head = tail = NULL;
        return;
    }
    
    NODE *temp = head; // Hapus paling atas
    head = head -> prev;
    delete temp;
}

void TampilkanStack(){
    NODE *temp = head;
    cout << "\nIsi Stack : \n\t";
    while (temp != NULL){
        cout << temp -> nilai << " -> ";
        temp = temp -> prev;
    }
    cout << "NULL\n";
}
