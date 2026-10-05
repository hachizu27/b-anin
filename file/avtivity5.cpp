#include<iostream>
using namespace std;
int main(){

    // int banyka_ankga,sum,i, angka;
    // cout <<"berapa banyak angka= ";
    // cin >> banyka_ankga;
    // sum=0;
    // for ( i =1 ; i <= banyka_ankga; i++)
    // {
    //     cout<<"masukan angka= ";
    //     cin>>angka;
    //     sum +=angka;
    // }
    // cout<<sum;

    // int number,i,j;
    // cout<<"masukan angka";
    // cin>>number;

    // for ( i = 1; i <=number; i++)
    // {
    //     for (j = 1;  j<=i; j++)
    //     {
    //         cout<<j<<"\t";
    //     }
    //     cout<<endl;
    // }

    int number,i,j;
    cout<<"masukan angka";
    cin>>number;

    for ( i = 1; i <=number; i++)
    {
        for (j = 1;  j<=i; j++)
        {
            cout<<"\t" <<j;
        }
        cout<<endl;
    }
    
    
}