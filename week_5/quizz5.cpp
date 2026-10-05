#include<iostream>
using namespace std;
int main(){
//SEATMAP KITA KASIH BOOL SUPAYA KETIKA IF ELSE JIKA TERSEDIA =0 DAN SEBALIKNYA
 bool seatmap[5][6]={
    {},{}
 };
 //REPEAT MERUPAKAN VARIABEL YANG KITA GUNAKAN KETIKA INGIN MENGULANG DENGAN MEMASUKAN ANGKA 1
 bool repeat= 1;
 //INI BERFUNGSI UNTUK MENAMBAHKAN VARIABEL KOLOM DAN BARIS
 int baris,kolom,i,j;
//MENAMPLLKAN UCAPAN SELAMAT DATANG
 cout<< "Selamat datang di bioskop"<<endl<<"mohon perhatikan seatmap berikut"<<endl;

 //WHILE UNTUK PERULANGAN KETIKA INGIN MEMBELI KURSI LEBIH DARI 1
    while ( repeat )
    {
     
     for (i = 0; i <5; i++)
     {
         cout<<i<<"\t";
         
         for ( j = 0; j <6; j++)
         {
             if (seatmap[i][j]==0)
             {
                 cout<<"-"<<"\t";
                }
                else if(seatmap[i][j]!=0)
                {
                    cout<<"v\t";
                }
            }
            cout<<endl;
            
        }
        //COUT UNTUK MENMAMPIKAN USER KURSI YANG MANA YANG INGIN DI BELI DAN CIN UNTUK MEMASUKAN JAWABAN USER
        cout<<"pilih kamu mau duduk di baris mana= ";
        cin>>baris;
        cout<<"pilih kamu mau duduk di kolom mana= ";
        cin>>kolom;
        //UNTUK MENGUBAH TAMPILAN KURSI YANG SUDAH DI PILIH NYAMBUNG DENGAN ESLSE IF !=0 DAN MENGELUARKAN OUTPUT V
        seatmap[baris][kolom]=1;    

        //UNTUK MEMBERI PERINTAH APAKAH INGIN MEMBELI LAGI ATAU TIDAK JIKA INGIN MENG INGPUT 1 JIKA TIDAK 0
        cout <<"kamu membeli seat di"<<" baris= " <<baris<< " kolom "<<kolom;

        cout<<" ada lagi (1=ya 0=no)";
        cin>>repeat;
        
    }
}