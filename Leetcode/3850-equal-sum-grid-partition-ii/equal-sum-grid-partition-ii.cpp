class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total_sum = 0;
        vector<long long> row_sums(m, 0);
        vector<long long> col_sums(n, 0);
        
        unordered_map<long long, int> min_row, max_row, min_col, max_col;        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                long long val = grid[r][c];
                total_sum += val;
                row_sums[r] += val;
                col_sums[c] += val;
                
                if (min_row.find(val) == min_row.end()) {
                    min_row[val] = r;
                    max_row[val] = r;
                    min_col[val] = c;
                    max_col[val] = c;
                } else {
                    max_row[val] = max(max_row[val], r);
                    min_col[val] = min(min_col[val], c);
                    max_col[val] = max(max_col[val], c);
                }
            }
        }
        
        auto check_H_A = [&](int i, long long D) -> bool {
            if (i == 0) return grid[0][0] == D || grid[0][n-1] == D; // 1D row
            if (n == 1) return grid[0][0] == D || grid[i][0] == D;   // 1D col
            return min_row.count(D) && min_row[D] <= i;              // 2D section
        };
        
        auto check_H_B = [&](int i, long long D) -> bool {
            if (i == m - 2) return grid[m-1][0] == D || grid[m-1][n-1] == D;
            if (n == 1) return grid[i+1][0] == D || grid[m-1][0] == D;
            return max_row.count(D) && max_row[D] >= i + 1;
        };
        
        auto check_V_A = [&](int j, long long D) -> bool {
            if (j == 0) return grid[0][0] == D || grid[m-1][0] == D;
            if (m == 1) return grid[0][0] == D || grid[0][j] == D;
            return min_col.count(D) && min_col[D] <= j;
        };
        
        auto check_V_B = [&](int j, long long D) -> bool {
            if (j == n - 2) return grid[0][n-1] == D || grid[m-1][n-1] == D;
            if (m == 1) return grid[0][j+1] == D || grid[0][n-1] == D;
            return max_col.count(D) && max_col[D] >= j + 1;
        };
        
        long long S_A = 0;
        long long S_B = total_sum;
        for (int i = 0; i < m - 1; ++i) {
            S_A += row_sums[i];
            S_B -= row_sums[i];
            
            if (S_A == S_B) return true;
            if (S_A > S_B && check_H_A(i, S_A - S_B)) return true;
            if (S_B > S_A && check_H_B(i, S_B - S_A)) return true;
        }
        
        S_A = 0;
        S_B = total_sum;
        for (int j = 0; j < n - 1; ++j) {
            S_A += col_sums[j];
            S_B -= col_sums[j];
            
            if (S_A == S_B) return true;
            if (S_A > S_B && check_V_A(j, S_A - S_B)) return true;
            if (S_B > S_A && check_V_B(j, S_B - S_A)) return true;
        }
        
        return false;
    }
};