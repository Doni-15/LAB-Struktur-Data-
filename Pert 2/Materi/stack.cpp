#include <iostream>
#include <stack>
using namespace std;

int main(){
    system("cls");

    stack<int> s;
    int input;

    cout << "Masukkan angka : \n";
    while (cin >> input){
        s.push(input);
    }
    
    do{
        cout << s.top() << " ";
        s.pop();
    } while (s.size() != 0);
    
    return 0;
}