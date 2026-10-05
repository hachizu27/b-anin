#include<iostream>
int Faktorial(int a){
    int jumlah_akhir=1;
    int i=0;
    while (i<=a)
    {
        jumlah_akhir= jumlah_akhir*i;
        i++;
    }
    
   return jumlah_akhir;
}
int main(){
int result= Faktorial(5) + Faktorial(4);
std:: cout<< "hasil penjumlahan dari faktorial 5 dan 4 adalah= "<< result;
}