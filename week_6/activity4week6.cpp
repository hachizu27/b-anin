#include<iostream>

int faktor(int a){

    if (a>0)
    {
        return a*faktor(a-1);
    }
    else{
        return 1;
    }
    
}
int main(){

    int hasilFaktor= faktor(5)+faktor(4);
    std:: cout<< "hasil nya adalah= "<< hasilFaktor;
}