#include<iostream>

int main(){
    std:: string member[5]= {"ani","budi","wati","iwan","santi"};
    std:: string apakah_member, nama;
    int member_id, biaya_masuk, book_id, total,i;
    std:: string judul[5]={"Harry Potter","Algorithm","Calcullus","Sharelock Holmes","Supernova"};
    int harga[5]={250000,85000,130000,270000,180000};
    std::string available[5]={"True","True","False","True","True"};

    std::cout<<"halo selamat datang di toko buku"<<std::endl<<"apakah kamu punya member (y or n)";
    std::cin>> apakah_member;
// Menentukan nama dengan memasukkan member id
    if (apakah_member=="y"||"Y")
    {
        std::cout<<"masukan member id mu (0-4)";
        std:: cin>> member_id;
        nama=member[member_id];
        biaya_masuk=0;
    }
    else{
        biaya_masuk=1000;
        nama="tamu";
    }
std:: cout<<"selamat datang "<<nama<<" biaya masuk mu adalah= "<<biaya_masuk<<std::endl;


//list dari buku yang tersedia
std::cout<<" berikut merupakan buku yang tersedia" <<std:: endl;
for ( i = 0; i <=4; i++)
{
    if (available[i]=="False")
    {
    continue;
    }
    std::cout<<"buku id "<<i<<" judul "<<judul[i]<<" harga "<< harga[i]<<std::endl;
    
}

//Proses pembelian buku setelah melihat buku yang tersedia
std:: cout<<"Masukan Id buYku yang ingin kamu beli= ";
std:: cin>>book_id;
total= biaya_masuk + harga[book_id];

std::cout<<"kamu memilih buku "<<judul[book_id]<< " dengan total "<< total;

}