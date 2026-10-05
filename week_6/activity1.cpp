#include<iostream>

double luasLingkaran( double r){
    return 3.14*r*r ;
}
double volumeTabung(double r, double t){
    return luasLingkaran(r) * t ;
}
double volumeKerucut(double r, double t){
    return volumeTabung(r, t)/3 
}
int main(){

    double jarijari=10.0 ;
    double tinggi=30.0 ;
    std:: cout<< "luas lingkaran= " << luasLingkaran(jarijari)<< std:: endl ;
    std:: cout<< "volume tabung= " << volumeTabung(jarijari, tinggi)<< std:: endl ;
    std:: cout<< "volume kerucut= " << volumeKerucut(jarijari, tinggi)<< std:: endl ;

    
}