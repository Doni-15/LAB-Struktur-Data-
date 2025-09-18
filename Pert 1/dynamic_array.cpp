#include <iostream>
using namespace std;

int main(){
    system("cls");

    int n;
    cout << "Masukkan jumlah elemen array : "; cin >> n;
    if(n <= 0) return -1;

    int* arr = new int[n];
    cout << "Masukkan  " << n << " angka : \n";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Isi array : \n";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}