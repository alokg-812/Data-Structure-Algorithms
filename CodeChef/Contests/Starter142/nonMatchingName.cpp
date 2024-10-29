#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    string sa, sb;
	    cin>>sa>>sb;
	    vector<int>arrA(26,0);
	    vector<int>arrB(26,0);
	    for(int i =0;i<n;i++){
	        arrA[sa[i]-'a']++;
	    }
	    for(int i =0;i<m;i++){
	        arrB[sb[i]-'a']++;
	    }
	    bool flag = false;
	    for(int i=0;i<26;i++){
	        if(!arrA[i] and !arrB[i]){
	            flag = true;
	            break;
	        }
	    }
	    if(flag) cout<<"YES\n";
	    else cout<<"NO\n";
	}
}
