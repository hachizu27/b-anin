#include<iostream>
double luasLingkaran( double  r){
    return  3.14*r*r;
}

double volumeTabung(double r, double t){
    return luasLingkaran(r)*t;
} 

double volumeKerucut(double r, double t){
    return volumeTabung(r,t)/3;
}
int main(){
    double jariJari=10.0;
    double Tinggi=30.0;
    std:: cout<< "luas ligkaran adalah "<<luasLingkaran(jariJari)<< std:: endl;
    std:: cout<< "volume tabung adalah "<<volumeTabung(jariJari, Tinggi)<<std:: endl;
    std:: cout<< "Volume kerucut adalah "<<volumeKerucut(jariJari, Tinggi)<<std:: endl;
}
