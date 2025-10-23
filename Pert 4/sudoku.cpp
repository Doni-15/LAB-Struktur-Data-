/*
Nama : Doni Rivaldo SImamora
NIM  : 241401037
*/

#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak papan Sudoku
void printBoard(const vector<vector<int>>& board) {  // pakai referencing jadi ganti lagnsung dari dalam var
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";

            // Buat 3x3 dalam satu kolom
            if ((j + 1) % 3 == 0) {
                cout << " ";
            }
        }
        cout << endl;

        // ini untuk next baris kalau kolom dah pas 3x3
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

// Fungsi untuk memeriksa apakah sebuah angka valid di posisi tertentu
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Periksa baris dan kolom
    for (int i = 0; i < 9; i++) {
        // intinya ini sesuai syarat sudoku dalam baris atau kolom gk boleh ada angka yang sama
        if (board[row][i] == num || board[i][col] == num) {
            return false; // kalau sama kembalikan nilai false
        }
    }

    // Periksa sub-kotak 3x3
    /*
    disini intinya dapat sebuah value dari row dan col nah kita buatlah kode dibawah ini agar komputernya tau
    titik awal dari pengecekan misallah kita punya row = 5 dan col = 7

    karena pakai 9x9 dan tiap bagian itu 3x3 jadi titik awal itu
        (0,0), (0,3), (0,6)  ==> baris 0 kalau sesuai blok
        (3,0), (3,3), (3,6)  ==> baris 1 kalau sesuai blok atau baris 3 dari keseluruhan baris
        (6,0), (6,3), (6,6)  ==> baris 2 kalau sesuai blok atau baris 6 dari keseluruhan baris
    */

    // startRow = row - (row % 3)
    // startRow = 5 - (5 % 3) = 5 - 2 = 3
    int startRow = row - (row % 3); // ini aku ganti dari ==> startRow = row - row % 3 biar mudah dipahami
    
    // startCol = col - (col % 3)
    // startCol = 7 - (7 % 3) = 7 - 1 = 6
    int startCol = col - (col % 3);

    // jadi kita dapat itik awal = [3][6]
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // disini ada kondisi untuk check bahwasannya numnya gk boleh sama
            if (board[i + startRow][j + startCol] == num) {
                return false; // kalau sama nanti mengembalikan nilai false
            }

            // kalau gk ada yang sama disini kode dari titik awal [3][6] hingga [5][8] lanjut terus hinga selesai
        }
    }

    return true;
}

// Fungsi utama pemecah Sudoku menggunakan rekursif DFS
bool solveSudoku(vector<vector<int>>& board) {
    // Cari sel kosong
    // sel kosong disini kalau sesuai kode adalah 0
    for (size_t i = 0; i < board.size(); i++){
        for (size_t j = 0; j < board.size(); j++){

            // Ketemu sel kosong
            if(board[i][j] == 0) {

                // Coba masukkan angka dari 1 - 9
                for (int n = 1; n <= 9; n++){
                    // Jika valid (gunakan fungsi isValid):
                    if(isValid(board, i, j, n)){

                        // Masukkan angka
                        board[i][j] = n;
                        
                        // Rekursi
                        if(solveSudoku(board)){
                            // Jika berhasil, kembalikan true
                            return true; 
                        }
                        // Jika gagal
                        else{
                            // kosongkan sel
                            board[i][j] = 0;
                        }
                    }
                }
                // Jika tidak ada angka yg valid, backtrack (return false)
                return false;
            }
        }
    }
    // Jika tidak ada lagi sel kosong (solusi telah ditemukan), return true
    return true;
}

int main() {
    system("cls");
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    

    cout << "Papan Sudoku awal:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board);
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;
}

/*

NB :

Tujuan Sudoku adalah
Dari koding kita isi yang nilainya 0 dengan angka 1-9 jadi:
1. Setiap baris (row) berisi angka 1–9 tanpa pengulangan.
2. Setiap kolom (column) berisi angka 1–9 tanpa pengulangan.
3. Setiap kotak kecil 3×3 juga berisi angka 1–9 tanpa pengulangan.

Hasil yang diharapkan seharusnya

Dari ini
5 3 0  0 7 0  0 0 0  
6 0 0  1 9 5  0 0 0  
0 9 8  0 0 0  0 6 0  

8 0 0  0 6 0  0 0 3  
4 0 0  8 0 3  0 0 1  
7 0 0  0 2 0  0 0 6  

0 6 0  0 0 0  2 8 0  
0 0 0  4 1 9  0 0 5  
0 0 0  0 8 0  0 7 9  


Ke sini ==> tiap 0 jadi angka yang sesuai anggap p (tapi gk boleh sama)
5 3 p  p 7 p  p p p  
6 p p  1 9 5  p p p  
p 9 8  p p p  p 6 p  

8 p p  p 6 p  p p 3  
4 p p  8 p 3  p p 1  
7 p p  p 2 p  p p 6  

p 6 p  p p p  2 8 p  
p p p  4 1 9  p p 5  
p p p  p 8 p  p 7 9  
*/