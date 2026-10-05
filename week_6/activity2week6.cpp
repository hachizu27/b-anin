#include<iostream>
int faktor(int a){
    int hasil=1;
    for ( int i = 1; i <=a ; i++)
    {
       
    hasil= hasil*i ;
    }
    return hasil;
}

int main(){


    int hasilFaktor= faktor(5)+faktor(4);
    std::cout<< "hasil penjumlahan dari faktorial  4 dan 5= "<< hasilFaktor;


}