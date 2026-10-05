#include<iostream>
#include<string>
int main(){
    std:: string member[5] = {"ani","budi","wati","iwan","santi"};
    std::string judul[5] = {"Harry Potter","algorithm","calculus","sharelock holmes","supernova"};
    std::string avaible[5] = {"true","true","true","false","true"};
    std::string ismember,nama,judul_buku;
    int harga[5] = {250000,85000,130000,270000,180000};
    int memberID,sum,biaya_massuk,total_harga,bookid;
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
    std::cout<<"selamat datang " << nama <<" biaya masuk= "<<biaya_massuk<<std::endl;
    
    // list buku yang availbe
    std::cout<<"buku yang tersedia:"<<std::endl;
    for (int i = 0; i < 5; i++)
    {
        if (avaible[i]=="false")
        {
            continue;
        }
        std::cout<<"book id "<<i<<" judul buku "<<judul[i]<<" harga= "<<harga[i]<<std::endl;
        
            
        
    }

   std::cout<<"masukan id buku yang ingin di beli= ";
   std::cin>>bookid;
total_harga=biaya_massuk+harga[bookid];
   std::cout<<"total harga yang harus di bayar= "<<total_harga<<std::endl;

}