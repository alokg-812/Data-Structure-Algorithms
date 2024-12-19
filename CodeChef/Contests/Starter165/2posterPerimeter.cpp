https://www.codechef.com/START165D/problems/POSTPERI
https://www.codechef.com/viewsolution/1115892196

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n, m, k;
	    cin>>n>>m>>k;
	    int ans = INT_MAX;
	    for(int l=1;l<=n;l++){
            for(int w=1;w<=m;w++){
                int peri= 2*(l+w);
                int diff = abs(peri-k);
                ans = min(ans,diff);
            }
        }

        cout<<ans<<endl;
    }
}
