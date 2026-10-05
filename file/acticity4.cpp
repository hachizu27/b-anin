#include<iostream>
using namespace std;
int main(){
int number1, number2, i, sum;
sum=0;
cout<<"masukan angka 1= ";
cin >> number1;
cout<<"masukan angka 2 =";
cin>>number2;

    for ( i = number1; i <=number2; i++)
    {
        if (i%2==0 & i!=number1 & i!=number2)
        {
            sum +=i;
        }
        
    }
    cout <<sum;
    

}