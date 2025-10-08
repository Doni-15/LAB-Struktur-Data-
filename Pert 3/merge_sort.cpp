#include <iostream>
#include <vector>
using namespace std;

/*
Merge Sort adalah algoritma pengurutan (sorting algorithm) yang menggunakan prinsip Divide and 
Conquer (bagi dan taklukkan) untuk mengurutkan data
*/


// Fungsi ini menggabungkan dua bagian array yang sudah terurut menjadi satu bagian yang juga terurut
void merge(vector<int>& arr, int left, int mid, int right) {
   
    // Menghitung panjang dua bagian array: kiri (L) dan kanan (R)
    int n1 = mid - left + 1;  
    int n2 = right - mid;    

    // Membuat dua array sementara (L dan R) untuk menampung data dari masing-masing bagian
    vector<int> L(n1), R(n2);

    // Looping berguna unutk menyalin data dari arr ke L dan R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Inisialisasi awal
    int i = 0;   
    int j = 0;      
    int k = left;

    // Looping untuk bandingkan elemen dari L dan R satu per satu, dan masukkan elemen terkecil ke arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Menyalin sisa elemen jika ada (karena mungkin salah satu array sudah habis duluan)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sama sepert looping di atas 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi utama merge sort => implementasi dari algoritma rekursif Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
   
    // Basis rekursi: jika hanya ada satu elemen atau tidak ada, tidak perlu diurutkan
    if (left >= right)
        return;

    // Menghindari overflow saat mencari nilai tengah
    int mid = left + (right - left) / 2;

    // Pecah array menjadi dua bagian, urutkan masing-masing secara rekursif
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
   
    // Gabungkan dua bagian yang sudah terurut
    merge(arr, left, mid, right);
}

// Menampilkan isi array ke terminal
void printArray(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    // Input jumlah elemen array
    cout << "Masukkan jumlah elemen data: "; cin >> n;
   
    // Looping untuk input setiap elemen array
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cout << "Masukkan elemen-elemen data ke-" << i + 1 << " : "; cin >> data[i];
    }
   
    // Tampilkan array sebelum diurutkan
    cout << "Array sebelum diurutkan: ";
    printArray(data);
   

    // Jalankan proses Merge Sort.
    mergeSort(data, 0, n - 1);
   
    // Tampilkan array setelah diurutkan
    cout << "Array setelah diurutkan: ";
    printArray(data);
   
    return 0;
}