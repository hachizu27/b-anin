#include<iostream>
#include<string>
int main(){
    std:: string member[5] = {"ani","budi","wati","iwan","santi"};
    std::string ismember,nama;
    int memberID,sum,biaya_massuk;
    sum=0;

    std::cout<<"selamat datang di toko buku mentari"<<std::endl<<"apakah mau member (y/n)";
    std::cin>>ismember;
    if (ismember=="y")
    {
        std::cout<<"masukan member id(0-4)= ";
        std::cin>>memberID;
        nama= member[memberID];
        biaya_massuk=0;
    }
    else
    {
        nama="guest";
        biaya_massuk=2000;
    }
    std::cout<<"selamat datang " << nama <<" biaya masuk= "<<biaya_massuk;
}