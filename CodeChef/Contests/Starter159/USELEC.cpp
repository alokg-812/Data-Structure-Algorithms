#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n, x;
	    cin>>n>>x;
	    vector<int>arA(n), arB(n), ans;
	    
	    for(int i =0;i<n;i++) cin>>arA[i];
	    for(int i =0;i<n;i++) cin>>arB[i];
	    
	    int cntA=0,cntB=0;
	    for(int i=0;i<n;i++){
	        if(arA[i]>arB[i]){
	            cntA++;
	        }
	        else{
	            int temp=arB[i] -arA[i]+1;
	            ans.push_back(temp);
	        }
	    }
	    sort(ans.begin(), ans.end());
	    for(int i=0;i<ans.size();i++){
	        if(x>=ans[i]){
	            x-=ans[i];
	            cntA++;
	        }
	        else break;
	    }
	    if(cntA>n/2) cout<<"YES\n";
	    else cout<<"NO\n";
	}

}
