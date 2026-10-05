#include<iostream>
void tanggal( int hari, int bulan, int tahun){
    std:: cout<<"sekarang hari ke " <<hari<< " sekarang bulan ke "<< bulan<< " dan sekarang tahun "<<tahun<< std:: endl;
}
void tanggal(int hari, std::string bulan, int tahun){
std:: cout<< "sekarang hari ke "<<hari<< " sekarang itu bulan "<< bulan<< " dan tahun "<< tahun<<std:: endl;
}
int main(){
    tanggal(12,12,2012);
    tanggal(13,"desember", 2013);
}
