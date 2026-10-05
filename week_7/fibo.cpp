#include<iostream>
using namespace std;
// kita buat function untuk hitung fibonaci nya
int fibo(int x){
// di awal itu konsep nya kita harus verifikasi dulu apakah x nya itu 0 atau 1 jika iya nanti akan berhenti
    if (x==0)
    {
        return 0;
    }
    
    if (x==1)
    {
        return 1;
    }
    //ini rumus fibo yang aku cari di google  yang di implemanasikan ke cppp
    return (x-1)+ fibo(x-2);
}

int main(){
//jika sudah buat function bisa langsung ke  main dimana kita harus mengeluarkan output masukkan angka terlebih dahulu dann di input di dalam fariable ankga
    int angka;
    cout<< "masukan angka nya= ";
    cin>> angka;
    cout << "fibonaci squece: ";
    //kita for di sini untuk loop menampilkan ouput satu satu 
    for (int i = 0; i < angka; i++)
    {
    cout<< fibo(i);
    }
    return 0;

    
    
}