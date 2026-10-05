#include<bits/stdc++.h>
using namespace std;


int main(){

string namaBarang[5]={"","Beras","ikan","susu","jajan"};
int harga, barangl, hargaTotal, setelahDiskon=0, pembayaran=0;
hargaTotal=0;
double diskon;
vector <string>namaBarangl;
bool ulang=1;
cout<< "Selamat datang silahkan lihat barang yang ingin anda beli"<<endl;
for (int i = 1; i <5; i++)
{
    cout<<i<<"\t"<< namaBarang[i]<<endl;
    
}

while (ulang)
{
    cout<< "silahkan masukan id barang barang yang anda inginakan";
    cin>> barangl;

    switch (barangl)
    {
        case 1:
        namaBarangl.push_back( "Beras(Rp. 16.000)");
        harga=16000;
        break;

        case 2:
        namaBarangl.push_back("ikan(Rp. 10.000)");
        harga= 10000;
    break;
case 3:
    namaBarangl.push_back("Susu(Rp. 60.000)");
    harga= 60000;
    break;

case 4:
namaBarangl.push_back("Jajan(Rp. 5.000)");
harga= 5000;
break;

default:
break;
}
hargaTotal+=harga;

        cout<<"apakah ada lagi?(1=iya/0=tidak)";
        cin>> ulang;

if(hargaTotal>=100000){
    diskon=0.10;
}
else if(hargaTotal>=50000){
    diskon=0.05;
}
else {
    diskon=0.0;
}


}
setelahDiskon =hargaTotal -(hargaTotal*diskon);

cout<< "anda membeli barang= "<< endl;
for (int i = 0; i <namaBarangl.size(); i++)
{
    cout<<"-" <<  namaBarangl[i]<<endl;
}
cout<< "Total nya adalah= "<< setelahDiskon<< endl;

cout<< "masukan uang anda (harap masukan uang pas saja)= "<< endl;
cin>> pembayaran;

if(pembayaran== setelahDiskon){
    cout<<"terimaksih atas pembelian anda silahkan datang kembali";
}
else{
    cout<<"mohon maaf tolong masukan nominal yang valid";
}

}