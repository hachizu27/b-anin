#include<iostream>
using namespace std;

int fibonaci(int n){

    return fibonaci(n - 1) + fibonaci(n - 2);

}
int main(){

    int angka;
     cout<<"masuan angka";
     cin>> angka;
     for (int i = 0; i < angka; i++)
     {
         cout << fibonaci(angka);
        
     }
     
}