#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n;
        string a;
        cin>>n;
        cin>>a;
        vector<int>pre(n+1,0);
        for(int i =0;i<n;i++){
            pre[i+1]=pre[i]+(a[i]-'0');
        }
        vector<long long>dp(n+1);
        dp[1]=pre[1]-pre[0];
        for(int i =1;i<=n;i++){
            vector<long long>dpp(n+1);
            for(int j=1;j<=n;j++){
                if(i==1 and j==1){
                    dpp[j]=dp[j];
                    continue;
                }
                int l=min(i,j);
                int r = max(i,j);
                int bij=pre[r]-pre[l-1];
                long long b=1e18;
                if(i>1) b=min(b,dp[j]);
                if(j>1) b=min(b,dpp[j-1]);
                dpp[j]=b+bij;
            }
            dp=dpp;
        }
        cout<<dp[n]<<"\n";
    }
}
