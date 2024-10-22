#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        int cnt=0, ans=0;
        bool flag = false;
        for(char ch: s){
            if(ch == '.'){
                cnt++,ans++;
            }
            else{
                cnt=0;
            }
            if(cnt == 3){
                flag = true;
                break;
            }
        }
        if(flag) cout<<2<<"\n";
        else cout<<ans<<"\n";
    }
}