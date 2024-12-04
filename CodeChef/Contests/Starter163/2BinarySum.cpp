https://www.codechef.com/START163D/problems/BINARYSUM

#include <bits/stdc++.h>
using namespace std;


string check(int n, int k){
    int maxi = (n+1)/2;
    int mini = n/2;
    if(k>=mini and k<=maxi){
        return "YES\n";
    }
    return "NO\n";
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<check(n,k);
    }
}
