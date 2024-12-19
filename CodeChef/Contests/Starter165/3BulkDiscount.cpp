https://www.codechef.com/START165D/problems/BDISC
https://www.codechef.com/viewsolution/1116025838

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>arr(n);
	    for(int i = 0;i<n;i++) cin>>arr[i];
	    sort(arr.rbegin(), arr.rend());
	    int ans = 0;
	    for(int i = 0;i<n;i++){
	        ans += max(0, arr[i] - i);
	    }
	    cout<<ans<<endl;
	}

}
