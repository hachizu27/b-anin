#include<iostream>
using namespace std;
int main(){


    int banyak_angka,angka,jum,i;

    jum=0;
    cout<<"mau menjumlhakan berapa angka";
    cin>> banyak_angka;
    for (size_t i = 1; i <=banyak_angka; i++)
    {
        cout<<"mau menjumlahkan bangka= ";
        cin>>angka;
        jum+=angka;

    }
    cout <<jum;


}