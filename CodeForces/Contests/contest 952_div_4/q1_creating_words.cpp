#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s,r;
        cin>>s>>r;
        char t = s[0];
        s[0] = r[0];
        r[0] = t;
        cout<<s<<" "<<r<<"\n";        
    }
}
