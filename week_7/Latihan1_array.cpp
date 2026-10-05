#include <bits/stdc++.h>

int main(){
    std:: cout<<"======SELAMAT DATANG DI BIOSKOP NGAWI======"<< std::endl;
    
        bool KursiBioskop[10][12]={};
            bool ulang=1;
            int baris, kolom, hargaKursi,Pembayaran;
        int harga[3]={100000,30000,50000};
    while (ulang)
    {

        for (int i = 0; i < 10; i++)
        {
            std:: cout<<i<<"\t";
            std:: cout<< "-"<<"\t";
            for (int b = 1; b < 12; b++)
            {
                if (KursiBioskop[i][b]==0)
                {
                        std:: cout<< "-"<<"\t";

                    
                }
                else if(KursiBioskop[i][b]!=0)
                {
                    std::cout<< "X"<<"\t";
                }
            
            }
            std::cout<< std::endl;
        }
 
        std:: cout<< "silahkan lihat daftar kusi di atas"<< std:: endl<< "silahkan pilih mau duduk di sebalah mana"<< std:: endl;
    
        std:: cout<< "baris= ";
        std:: cin>> baris;
        std:: cout<< "kolom= ";
        std:: cin>> kolom;

        
        if (KursiBioskop[baris][kolom]==1)
        {
            std:: cout<<"kursi anda sudah di boking";
            break;
        }
        
        if (baris<=2){
            
        }
        std:: cout<< "harga kursi yang harus di baya adalah="<< harga[baris]<<std:: endl;
        std:: cout<<"masukan uang anda di sini mohon masukan uang pas saja";
        std:: cin>> Pembayaran;
        hargaKursi= KursiBioskop[baris][kolom]*harga[baris];
        if (Pembayaran>= hargaKursi)
        {
            std:: cout<< "terimakasih";
            
        }
        else {
            std:: cout<< "uang anda kurang";
        }
        
    
        std:: cout<<"apakah ada lagi (1=ya & 0=tidak)";
        std:: cin>> ulang;

        KursiBioskop[baris][kolom]=1;
    }


}