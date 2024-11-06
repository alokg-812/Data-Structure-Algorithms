#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n>>x;
	    int ev = n/2;
	    int odd=n-ev;
	    if(x%2 == 0) cout<<ev-1<<"\n";
	    else cout<<odd-1<<"\n";
	}
}
