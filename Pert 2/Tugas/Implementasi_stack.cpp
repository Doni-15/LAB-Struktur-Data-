#include <iostream>
using namespace std;

struct NODE{
    int nilai;
    NODE *next;
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
    node_inputan -> next = NULL;

    if (head == NULL){
        head = node_inputan;
        tail = head;
    }
    else{
        tail -> next = node_inputan;
        tail = node_inputan;
    }
    
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
    
    NODE *temp = head; // Hapus belakang
    while (temp -> next != tail){
        temp = temp -> next;
    }

    delete tail;
    tail = temp;
    tail -> next = NULL;
}

void TampilkanStack(){
    NODE *temp = head;
    cout << "\nIsi Stack : \n\t";
    while (temp != NULL){
        cout << temp -> nilai << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}