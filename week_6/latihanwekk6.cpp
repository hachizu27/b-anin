#include<iostream>
int main(){
int jumlahMhs;

struct student{
    int niu;
    std:: string fullName;
    int year;
    char gender;
    
};
int a;
std::cout<< "masukan jumlah mahasiwa yang ingin di input= ";
std::cin>> a;
student mhs[a];
for (int i = 1; i <=a; i++)
{
    std:: cout<<"masukan niu= ";
    std::cin>> mhs[i].niu;
    std::cout<<"masukan nama= ";
    std::cin>> mhs[i].fullName;
    std::cout<<"masukan tahun= ";
    std::cin>> mhs[i].year;
    std:: cout<< "gender= ";
    std::cin>> mhs[i].gender;
    
}
std:: cout<< "=================================================================="<<std:: endl;
std::cout<< "|\tNIU\t"<<"|\tNama\t"<<"|\tTahun\t"<<"|\tGender\t|"<< std:: endl;
    
for (int i = 1; i <=a; i++)
{
 std:: cout<< "|\t" << mhs[i].niu<<"\t"<<std::endl;
 std:: cout<< "|\t" << mhs[i].fullName << "\t";
 std:: cout<< "|\t" << mhs[i].year << "\t|";
 std:: cout<< "\t"<<mhs[i].gender<<"\t|";
}

}