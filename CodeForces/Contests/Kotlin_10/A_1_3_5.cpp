#include<bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    for(int i = 0 ; i < k ; i++){
        int n;
        cin>>n;
        if((n == 1) or (n ==4) or (n ==7)){
            cout<<1<<"\n";
        }
        else if(n == 2){
            cout<<2<<"\n";
        }
        else {
            cout<<0<<"\n";
        }
    }
    return 0;
}
