#include <iostream>
#include<vector>
using namespace std;
int main(){

int id_member,id_buku;
double diskon, harga,uang_masuk,kembalian,harga_tumpuk,diskon_tumpuk,harga_setelah_diskon;
string apakah_member,nama_member, pelayanan;
vector<string>judul_buku;
bool repeat=1;
cout <<"selamat datang di toko buku mentari" <<endl << "apakah kamu member toko buku mentari y/n= ";
cin>> apakah_member;
if (apakah_member=="y")
{
    cout<<"masukan member id mu= ";
    cin>>id_member;

    switch (id_member)
    {
    case 1:
        nama_member="anin";
        diskon= 0.15;
        break;
    case 2:
        nama_member="budi";
        diskon=0.15;
        break;
    case 3:
        nama_member="wati";
        diskon=0.15;
        break;
    case 4:
        nama_member="brayen";
        diskon=0.15;
        break;
    diskon_tumpuk+=diskon;
    default: 
    cout<<"kode salah"<<endl;
    return 0;
    break;
}
    
}
else {
    nama_member="guest";
    diskon=0.05;
}

while (repeat)
{
    cout<<"masukan id buku yang ingin di beli= ";
    cin>>id_buku;
    
    switch (id_buku)
    {
        case 1:
        judul_buku.push_back("Harry porter");
        harga=250000;
        break;
        case 2:
        judul_buku.push_back("Alghorithm");
        harga=85000;
        break;
        case 3:
        judul_buku.push_back("Calculus");
        harga=130000;
        break;
        case 4:
        judul_buku.push_back("Sherlock homes");
        harga=270000;
        break;
        case 5:
        judul_buku.push_back("Super nova");
        harga=180000;
        break;

        default:
        return 0;
        cout <<"kode buku tidak di temukan";
        break;
    }
    harga_tumpuk+=harga;
    cout<<"ada lagi buku yang ingin di beli?(y=1/n=o)=";
    cin>>repeat;
}
cout<<nama_member <<" membeli buku berjudul "<< endl;
for (int i = 0; i < judul_buku.size(); i++)
{
    cout<<"-"<<judul_buku[i]<<endl;
}
harga_setelah_diskon= harga_tumpuk-(harga_tumpuk*diskon);
cout<<"total harga setelah diskon= "<< harga_setelah_diskon<< endl;
cout<<"masukan uang mu= ";
cin>>uang_masuk;
kembalian= uang_masuk-harga_setelah_diskon;
cout<<"kembalian anda adalah= " << kembalian << " terimakasih sudah membeli buku di toko buku mentari";
cout<< "berikan penilaian anda untuk pelayanan kami (1-10)";
cin >> pelayanan;

}
