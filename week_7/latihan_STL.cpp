#include<bits/stdc++.h>
using namespace std;

int main(){
// Latihan 1 array
    // int penjualaBuku[4][3]={
    //     {12,20,5},
    //     {8,15,7},
    //     {10,25,3},
    //     {14,18,6}
    // };

    // int total[3]= {0,0,0};
    // int harga[3]= {50000,30000,100000};

    // for (int i = 0; i <4; i++)
    // {
    //     for (int d = 0; d < 3; d++)
    //     {
    //         total[d]+= penjualaBuku[i][d]*harga[d];
    //     }
        
    // }
    // for (int i = 0; i <3; i++)
    // {
    //     cout<<total[i]<< endl;
    // }

// Latiha 2 array

int produkMotor[3][3]={
    {120,80,60},
    {150,90,70},
    {130,100,65},

};
long long hargaMotor[3]={15000000,20000000,25000000};
long long totalPeoduk[3]= {0,0,0};

for (int i = 0; i < 3; i++)
{
    for (int d = 0; d < 3; d++)
    {
        totalPeoduk[d]+=produkMotor[i][d]*hargaMotor[d];
    }
    
}
for (int i = 0; i < 3; i++)
{
    cout<< totalPeoduk[i]<< endl;

}

}