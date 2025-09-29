#include <iostream>
using namespace std;

// deklarasi sebuah struktur node
struct Node{
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// Insert di depan
void insertFirst(int n){
    Node *new_node = new Node; // buat node baru
    new_node -> value = n;
    new_node -> next = NULL;

    if(head == NULL){
        head = new_node;
        tail = head;
    }
    else{
        new_node -> next = head;
        head = new_node;
    }
}

// Insert di belakang
void insertLast(int n){
    Node *new_node = new Node; // buat node baru
    new_node -> value = n;
    new_node -> next = NULL;

    if(head == NULL){
        head = new_node;
        tail = head;
    }
    else{
        tail -> next = new_node;
        tail = new_node;
    }
}

// Insert dengan nilai tertentu
void insertAfter(int n, int check){
    if(head == NULL){
        cout << "List kosong";
        return;
    }

    Node *new_node = new Node; // buat node baru
    new_node -> value = n;
    new_node -> next = NULL;

    Node *p = head;
    while ((p != NULL) && (p -> value != check)){
        p = p -> next;
    }

    if (p == NULL){
        cout << "Node dengan nilai " << check << " tidak ditemukan\n";
        delete new_node;
    }
    else{
        new_node -> next = p -> next;
        p -> next = new_node;

        if (p == tail){
            tail = new_node;
        }
        
    }
}

// Cetak linked list 
void printList(){
    Node *temp = head;
    cout << "Isi dari linked list : ";
    while (temp != NULL){
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL";
    
}

int main(){
    system("cls");

    insertFirst(10);
    insertLast(20);
    insertLast(30);
    insertAfter(25, 20);
    insertFirst(5);

    printList();
    return 0;
}