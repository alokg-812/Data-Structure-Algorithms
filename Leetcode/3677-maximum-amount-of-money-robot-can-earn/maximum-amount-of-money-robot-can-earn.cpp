class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();        
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(3, -1e9)));
        dp[0][0][0] = coins[0][0];
        if(coins[0][0] < 0){
            dp[0][0][1] = 0;
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 and j == 0) continue;

                for(int k = 0;k<3;k++){
                    int maxi = -1e9;                    
                    if(i>0) maxi = max(maxi, dp[i-1][j][k]);
                    if(j>0) maxi = max(maxi, dp[i][j-1][k]);
                    if(maxi != -1e9){
                        dp[i][j][k] = max(dp[i][j][k], maxi + coins[i][j]);
                    }
                    if(k > 0 and coins[i][j] < 0){
                        int max_neut = -1e9;
                        if(i>0) max_neut = max(max_neut, dp[i-1][j][k-1]);
                        if(j>0) max_neut = max(max_neut, dp[i][j-1][k-1]);
                        if(max_neut != -1e9){
                            dp[i][j][k] = max(dp[i][j][k], max_neut); 
                        }
                    }
                }
            }
        }
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};