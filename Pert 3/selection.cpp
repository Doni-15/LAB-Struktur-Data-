// Program Selection Sort
#include <iostream>
using namespace std;

int main() {
    system("cls");
    int n;
    cout << "Masukkan jumlah elemen data: "; cin >> n;

    int data[n];
    for (int i = 0; i < n; i++) {
        cout << "Masukkan elemen-elemen data: " << i + 1 << " : "; cin >> data[i];
    }

    // Selection Sort dari terbesar hingga terkecil
    for (int i = 0; i < n - 1; i++){
        int max_indeks = i;

        for (int j = i + 1; j < n; j++){
            if(data[j] > data[max_indeks]){
                max_indeks = j;
            }
        }
        
        int temp = data[i];
        data[i] = data[max_indeks];
        data[max_indeks] = temp;
    }
    

    cout << "Data setelah diurutkan dari terbesar hingga terkecil:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}