class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;
        vector<vector<long long>> max_dp(m, vector<long long>(n, 0));
        vector<vector<long long>> min_dp(m, vector<long long>(n, 0));        
        max_dp[0][0] = min_dp[0][0] = grid[0][0];
        
        for(int i = 1;i<m;i++){
            max_dp[i][0] = max_dp[i-1][0] * grid[i][0];
            min_dp[i][0] = min_dp[i-1][0] * grid[i][0];
        }
        
        for(int j = 1;j<n;j++){
            max_dp[0][j] = max_dp[0][j-1] * grid[0][j];
            min_dp[0][j] = min_dp[0][j-1] * grid[0][j];
        }
        
        for(int i = 1; i<m;i++){
            for(int j = 1;j<n;j++){
                long long prev_max = max(max_dp[i-1][j], max_dp[i][j-1]);
                long long prev_min = min(min_dp[i-1][j], min_dp[i][j-1]);
                
                if (grid[i][j] < 0) {
                    max_dp[i][j] = prev_min * grid[i][j];
                    min_dp[i][j] = prev_max * grid[i][j];
                } else {
                    max_dp[i][j] = prev_max * grid[i][j];
                    min_dp[i][j] = prev_min * grid[i][j];
                }
            }
        }        
        long long ans = max_dp[m-1][n-1];
        
        if (ans >= 0) {
            return ans % MOD;
        } else {
            return -1;
        }
    }
};