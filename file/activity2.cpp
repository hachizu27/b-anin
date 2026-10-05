#include <iostream> 
using namespace std ;
int main()
 {
   int number1,number2, i;
   cout<<"masukan ankga pertama= ";
   cin>>number1;
   cout<<"masukan anngka ke dua= ";
   cin>>number2;
   for (i = number1; i <=number2; i++)
   {
    if (i%2==0 & i!=number1 & i!=number2)
    {
       cout<<i;
    }
    
   }
   
}