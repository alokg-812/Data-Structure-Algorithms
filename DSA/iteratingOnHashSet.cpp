#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<int>us;
    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(40);
    us.insert(50);
    us.insert(60);
    us.insert(70);
    for(auto i = us.begin(); i!= us.end(); i++){
        cout<<*i<<endl;
    }
}
