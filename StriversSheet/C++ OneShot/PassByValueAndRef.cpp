#include<bits/stdc++.h>
using namespace std;


// Pass by value
void doSomething1(int num){
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
}

// Pass by reference
void doSomething2(int &num){
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
}

int main(){
    int num = 10;
    cout<<"----pass by value starts----\n";
    cout<<"Original value: "<<num<<endl;
    doSomething1(num);
    cout<<"Value after function call: "<<num<<endl;
    cout<<"----pass by value ends----\n";

    cout<<"----pass by reference starts----\n";
    cout<<"Original value: "<<num<<endl;
    doSomething2(num);
    cout<<"Value after function call: "<<num<<endl;
    cout<<"----pass by reference ends----\n";
    return 0;
}