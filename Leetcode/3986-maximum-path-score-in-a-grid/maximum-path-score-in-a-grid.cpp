class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        dp[0][0] = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 and j == 0) continue;
                int cell_cost = (grid[i][j] > 0) ? 1 : 0;
                int cell_score = grid[i][j];                
                vector<int> next_dp_j(k+1, -1);
                
                for(int c = cell_cost;c<=k;c++){
                    int prev_c = c-cell_cost;
                    int max_prev = -1;
                    if(i > 0 and dp[j][prev_c] != -1){
                        max_prev = max(max_prev, dp[j][prev_c]);
                    }
                    if(j > 0 and dp[j-1][prev_c] != -1){
                        max_prev = max(max_prev, dp[j - 1][prev_c]);
                    }
                    if(max_prev != -1){
                        next_dp_j[c] = max_prev + cell_score;
                    }
                }                
                dp[j] = next_dp_j;
            }
        }
        int max_final_score = -1;
        for(int c = 0;c<=k;c++){
            if(dp[n-1][c] != -1) max_final_score = max(max_final_score, dp[n-1][c]);
        }
        return max_final_score;
    }
};