// https://www.codechef.com/START201D/problems/MARKP

#include <bits/stdc++.h>
using namespace std;

bool check(const string &s){
    int n=s.size();
    for(int i =0;i<n;){
        if(s[i]=='1'){
            int len=0;
            while(i<n and s[i] =='1'){
                len++;
                i++;
            }
            if(len<3) return false;
        }
        else{
                i++;
        }
    }
    return true;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    string s;
	    cin>>n;
	    cin>>s;
        if(check(s)==true){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
	}
	return 0;
}