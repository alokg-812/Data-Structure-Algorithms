class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        auto dfs = [&](auto& self, int r, int c, int parent_r, int parent_c, char target) -> bool {
            visited[r][c] = true;
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == target) {
                    if (visited[nr][nc]) {
                        if (nr != parent_r || nc != parent_c) {
                            return true;
                        }
                    } else {
                        if (self(self, nr, nc, r, c, target)) {
                            return true;
                        }
                    }
                }
            }
            return false;
        };
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (!visited[r][c]) {
                    if (dfs(dfs, r, c, -1, -1, grid[r][c])) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};