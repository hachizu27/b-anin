#include <iostream>

using namespace std;

//buat fuction unutk decimal ke binary 
int decimal_to_binary(int n) {
    int binary = 0;//baut variabel baru di sini dengan nilai awal 0
    int remainder, i = 1;//remainder ini untuk sisa bagi 
    while (n != 0) {
        remainder = n % 2;//ini kita modulo karena biner cuma 1 dan 0
        n /= 2;
        binary += remainder * i;
        i *= 10;
    }
    return binary;
}

int binary_to_decimal(int n) {
    int decimal = 0;
    int base = 1; 
    
    while (n != 0) {
        int remainder = n % 10; // Mengambil digit paling belakang
        n /= 10;                // Membuang digit yang sudah diproses
        
        decimal += remainder * base; // Kalikan digit dengan nilai tempatnya (1, 2, 4, 8, dst.)
        base *= 2;                   // Nilai tempat dikalikan 2 untuk digit berikutnya
    }
    return decimal;
}

int main() {
    cout << "Quiz 2: Decimal & binary converter with function\n";
    
    int repeat = 1;
    //buat while di awal untuk perulangan agar jika kita input 1 bisa masuk ke prtogam lagi
    while (repeat == 1) {
        cout << "[1] Decimal to binary\n";
        cout << "[2] Binary to decimal\n";
        
        int option;
        cout << "Input your option: ";
        cin >> option;
        
        if (option == 1) {
            int dec_input;
            cout << "Input your decimal: ";
            cin >> dec_input;
            int result = decimal_to_binary(dec_input);
            cout << "Your binary is: " << result << endl;
        } else if (option == 2) {
            int bin_input;
            cout << "Input your binary: ";
            cin >> bin_input;
            int result = binary_to_decimal(bin_input);
            cout << "Your decimal is: " << result << endl;
        } else {
            cout << "Pilihan tidak valid.\n";
        }
        
        cout << "Repeat? [0:No/1:Yes]: ";
        cin >> repeat;
        if (repeat == 0) {
            cout << "Program ends\n";
        }
    }
    
    return 0;
}