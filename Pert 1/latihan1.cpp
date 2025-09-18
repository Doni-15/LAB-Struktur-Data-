#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;


// Push values ke array
void push(int value){
    if(top == MAX){
        cout << "Stack Penuh!\n";
    }
    else{
        top++;
        stack[top] = value;
        cout << value << " ditambahkan dalam stack\n";
    }
}

// Delete value dari array
void pop(){
    if(top == -1){
        cout << "Stack kosong!\n";
    }
    else{
        cout << "\n" << stack[top] << " dihapus dari stack.\n";
        top--;
    }
}

// tampilkan isi stack
void display(){
    if(top == -1){
        cout << "Stack Kosong !\n";
    }
    else{
        cout << "\nIsi stack : \n";
        for (int i = top; i > 0; i--) {
            cout << stack[i] << " ";
        }     
    }
}

int main(){
    system("cls");
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();

    while (top >= 0){
        pop();
        display();
    }
    
    return 0;
}