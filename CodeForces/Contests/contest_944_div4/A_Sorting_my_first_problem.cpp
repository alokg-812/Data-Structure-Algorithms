#include<bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    for(int i = 0 ; i < k ; i++){
        int x, y;
        cin>>x>>y;
        if(x<=y){
            cout<<x<<" "<<y<<"\n";
        }
        else cout<<y<<" "<<x<<"\n";
    
    }
    
}
