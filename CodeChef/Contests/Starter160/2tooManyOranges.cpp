https://www.codechef.com/problems/ORANGES

https://www.codechef.com/viewsolution/1113055302

#include <bits/stdc++.h>
using namespace std;

bool check(int n, int k){
    int mini = 10*n;
    int maxi = 12*n;
    if(k<mini || k>maxi){
        return false;
    }
    for(int x=0;x<=n;x++){
        for(int y=0;y<=n-x;y++){
            int z= n-x-y;
            int totl=10* x+ 11* y+ 12*z;
            if(totl==k){
                return true;
            }
        }
    }
    return false;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    if(check(n,k)) cout<<"YES\n";
	    else cout<<"NO\n";
	    
	}

}
