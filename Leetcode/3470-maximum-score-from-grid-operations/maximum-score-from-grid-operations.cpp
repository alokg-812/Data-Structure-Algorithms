class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return 0;
        vector<vector<long long>> pref(n+1, vector<long long>(n, 0));
        for(int r = 0;r<n;r++){
            for(int c = 0;c<n;c++) pref[r+1][c] = pref[r][c] + grid[r][c];
        }
        auto col_sum = [&](int j, int start, int end) -> long long {
            if (start > end) return 0;
            start = max(0, start);
            end = min(n - 1, end);
            if (start > end) return 0;
            return pref[end + 1][j] - pref[start][j];
        };

        const long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -INF));
        for (int p = 0; p <= n; ++p) {
            for (int c = 0; c <= n; ++c) {
                dp[p][c] = col_sum(0, p, c - 1);
            }
        }

        for (int j = 1; j < n - 1; ++j) {
            vector<vector<long long>> next_dp(n + 1, vector<long long>(n + 1, -INF));
            
            for (int c = 0; c <= n; ++c) {
                vector<long long> max_val_from(n + 2, -INF);
                for (int p = n; p >= 0; --p) {
                    long long val = dp[p][c] + col_sum(j, c, p - 1);
                    max_val_from[p] = max(max_val_from[p + 1], val);
                }
                
                long long pref_max = -INF;        
                for (int nxt = 0; nxt <= n; ++nxt) {
                    pref_max = max(pref_max, dp[nxt][c]);                    
                    long long opt1 = pref_max + col_sum(j, c, nxt - 1);
                    long long opt2 = max_val_from[nxt + 1];
                    next_dp[c][nxt] = max(opt1, opt2);
                }
            }
            dp = next_dp;
        }
        long long max_score = 0;
        for (int p = 0; p <= n; ++p) {
            for (int c = 0; c <= n; ++c) {
                max_score = max(max_score, dp[p][c] + col_sum(n - 1, c, p - 1));
            }
        }

        return max_score;
    }
};