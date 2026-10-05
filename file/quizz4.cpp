#include <iostream>
using namespace std;
int main() {
    int number,jum;
    bool repeat=1;
    jum=0;

while (repeat)
{
    cout<<"masukan angka mu= ";
    cin>>number;
    jum+=number;
    cout<<"haslnya= "<<jum<< endl;
    cout<<"ada lagi (1=yes, 0=no)";
    cin>> repeat;
}
cout<<"haslnya= "<<jum;



}