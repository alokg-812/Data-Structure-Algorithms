#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        string str;
        cin>>n>>str;
        int an=0;
        for(int i =0;i<n;i++){
            if(str[i]==str[0]) an = max(an,i+1);
            if(str[i]==str[n-1]) an = max(an,n-i);
        }
        cout<<an<<"\n";
    }
}
