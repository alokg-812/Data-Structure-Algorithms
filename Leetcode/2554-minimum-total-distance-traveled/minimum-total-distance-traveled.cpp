class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());        
        int n = robot.size();
        int m = factory.size();
        vector<vector<long long>> memo(n, vector<long long>(m, -1));
        const long long INF = 1e15; 
        auto dp = [&](auto& self, int i, int j) -> long long {
            if (i == n) return 0;           
            if (j == m) return INF;
            
            if (memo[i][j] != -1) return memo[i][j];
            
            long long ans = self(self, i, j + 1);
            long long curr_dist = 0;
            int limit = factory[j][1];
            long long position = factory[j][0];
            
            for (int k = 1; k <= limit; ++k) {
                if (i + k - 1 < n) {
                    curr_dist += abs(robot[i + k - 1] - position);
                    ans = min(ans, curr_dist + self(self, i + k, j + 1));
                } else break;
            }
            return memo[i][j] = ans;
        };
        return dp(dp, 0, 0);
    }
};