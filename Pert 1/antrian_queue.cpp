#include <iostream>
using namespace std;

#define MAX 6
int queue[MAX];
int front = -1, rear = -1; //Asumsi awal dia nol

// enqueue (masukkan ke antrian)
void enqueue(int value){
    if(rear == MAX - 1){
        cout << "Antrian penuh !\n";
    }
    else{
        if(front == -1) front = 0;
        rear++;

        queue[rear] = value;
        cout << value << " masuk ke antrian(queue).\n";
    }
    
}

// dequeue (menghapus dari antrian)
void dequeue(){
    if(front == -1 || front > rear){
        cout << "Antrian kosong!\n";
    }
    else{
        cout << queue[front] << " keluar dari antrian.\n";
        front++;
    }
}

// tampilkan isi stack
void display(){
    if(front == -1 || front > rear){
        cout << "Stack Kosong !\n";
    }
    else{
        cout << "\nIsi stack : \n";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }  
        cout << endl;   
    }
}

int main(){
    system("cls");

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    
    enqueue(6);
    display();

    while (front < MAX){
        dequeue();
        display();
    }
    

    return 0;
}