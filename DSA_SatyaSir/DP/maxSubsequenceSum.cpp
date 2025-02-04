#include<bits/stdc++.h>
using namespace std;

int maxSubSeq(int n, vector<int> arr, vector<int>& dp){
    if(n<0) return 0;
    if(dp[n]== -1){
        dp[n] = max(maxSubSeq(n-1, arr, dp),arr[n] + maxSubSeq(n-2, arr, dp));
    }
    return dp[n];
}
int main(){
    vector<int>arr = {9, 4, 13, 24};
    int n = arr.size();
    vector<int>dp(n+1,-1);
    cout<<maxSubSeq(n, arr, dp)<<endl;
}