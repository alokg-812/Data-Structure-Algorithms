#include<bits/stdc++.h>
using namespace std;
// int fact(int n){
//     if(n==1) return 1;
//     else return n*fact(n-1);
// }


int nCr(int n, int r) {
    if (r > n) return 0;
    int dp[n + 1][r + 1];

    for(int i=0;i<=n;i++){
        for(int j=0; j<=min(i, r);j++){
            if(j==0 || j==i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][r];
}

int main(){
    int n,r;
    cout<<"Enter values of n and r: ";
    cin>>n>>r;
    cout<<nCr(n,r)<<endl;
}