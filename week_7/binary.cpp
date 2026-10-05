#include<iostream>
using namespace std;

int desmalKeBinary(int des){
int binar[32];
int x=0;
if (des<0)
{
    return 0;

}


while (des>0)
{
   
    
        binar[x]=des%2;
        des=des/2;
    

}

for (int j = 0; j <x; j--)
{
    cout<<binar[j];
}



}
void biner(){
    int x;
    cout<< "masukan angka ";
    cin>> x;
    cout<<desmalKeBinary(x);
}


int menu(){
cout<< biner();
    
}