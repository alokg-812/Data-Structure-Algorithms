#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b;
        cin>>c>>d;
        if ((a>b and c>d) || (b>a and d>c )){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
}
