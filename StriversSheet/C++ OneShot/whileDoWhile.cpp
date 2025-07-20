#include<iostream>
using namespace std;
int main(){
    int i =2;
    while(i<=1){
        cout<<"Hello "<<i<<endl;
        i++;
    };
    cout<<i<<endl;


    do{
        cout<<"Hello "<<i<<endl;
        i++;
    }while(i<=1);
    cout<<i<<endl;
}