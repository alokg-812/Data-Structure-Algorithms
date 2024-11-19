#include <bits/stdc++.h>
using namespace std;

bool check(unordered_map<int,int> um, int key){
    if (um.find(key) != um.end()){
        return true;
    }
    return false;
}

int main(){
    unordered_map<int,int> um;
    um[10] = 20;
    um[30] = 40; //insert
    um[50] = 60;
    um[70] = 80;
    cout<<um[48]<<endl; //access
    cout<<um[30]<<endl;
    cout<<check(um, 30)<<endl; //search
    um.erase(10); //erase
    cout<<um[10]<<endl;
    cout<<um[50]<<endl;
    um[50] = 900; //update
    cout<<um[50]<<endl;
    cout<<"Size: "<<um.size()<<endl;
    
}
