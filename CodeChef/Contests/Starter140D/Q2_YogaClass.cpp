#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,x,y;
	    cin>>n>>x>>y;
	    int maxi = 0;
	    int type1_earn = n*x;
	    int type2_earn = (n/2)*y;
	    int type2 = n/2;
	    int rem = n%2;
	    maxi = type2 * y + rem*x;
	    int ans1 = max(type1_earn , type2_earn);
	    int ans2 = max(ans1,maxi);
	    cout<<ans2<<"\n";
	}
}