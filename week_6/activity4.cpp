#include<iostream>
int faktorial(int a){

    if (a>0)
    {
        return a * faktorial(a-1);
    }
    else{
        return 1;
    }

}

int main(){

    int hasil = faktorial(5) + faktorial(4);
    std:: cout<< "hasil dari penampilan faktorial 4 dan 5 ="<< hasil;

}