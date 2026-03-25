class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (grid.empty() or grid[0].empty()) {
            return false;
        }

        int n = grid.size();
        int m = grid[0].size();
        vector<long long> row(n, 0);
        vector<long long> col(m, 0);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long val = grid[i][j];
                row[i] += val;
                col[j] += val;
                sum += val;
            }
        }

        if (sum % 2 != 0) {
            return false;
        }

        long long target = sum / 2;
        long long curr = 0;

        for (int i = 0; i < n - 1; i++) {
            curr += row[i];
            if (curr == target) {
                return true;
            }
        }

        curr = 0;

        for (int j = 0; j < m - 1; j++) {
            curr += col[j];
            if (curr == target) {
                return true;
            }
        }

        return false;
    }
};