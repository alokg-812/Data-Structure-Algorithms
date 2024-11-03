#include<bits/stdc++.h>
using namespace std;

bool check(int n, const string& s){
    int k=sqrt(n);
    if(k*k !=n) return false;
    for(int i =0;i<k;i++){
        if(s[i]!='1' || s[n-k+1] != '1') return false; 
    }

    for(int i =1;i<k-1;i++){
        if(s[i*k] != '1' || s[(i+1) *k-1] != '1') return false;
        for(int j=1;j<k-1;j++){
            if(s[i*k+j] != '0') return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        if(check(n,s)) cout << "Yes\n";
        else cout << "No\n";
    }
}
