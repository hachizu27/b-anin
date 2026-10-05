#include<iostream>
int main(){
std::string latters[2][4]={
    {"A","B","C","D"},
    {"E","F","G","H"}
};
//std::cout<< latters[0][2];
for (int i = 0; i <4; i++)
{
    for (int j = 0; j <2; j++)
    {
        
        std::cout<<latters[j][i]<<"\t";
    }
    std::cout<<std::endl;
}

}