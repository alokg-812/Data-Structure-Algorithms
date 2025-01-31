#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int,int>um;
    um[10] = 20;
    um[30] = 40;
    um[50] = 60;
    um[70] = 80;
    for(auto i = um.begin(); i!=um.end();i++){
        cout<<(i->first)<<"->";
        cout<<(i->second)<<endl;
    }
}
Output:
70->80
50->60
30->40
10->20
