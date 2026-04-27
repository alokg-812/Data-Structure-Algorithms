class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            if(r == m-1 and c == n-1) return true;
            
            int type = grid[r][c];
            if(c+1 < n and !visited[r][c+1] and (type==1 or type==4 or type==6)){
                int nextType = grid[r][c+1];
                if(nextType==1 or nextType==3 or nextType==5){
                    visited[r][c+1] = true;
                    q.push({r,c+1});
                }
            }
            if(c-1 >=0 and !visited[r][c-1] and (type==1 or type==3 or type==5)){
                int nextType = grid[r][c-1];
                if(nextType==1 or nextType==4 or nextType==6){
                    visited[r][c-1] = true;
                    q.push({r, c-1});
                }
            }
            if(r+1 <m and !visited[r+1][c] and (type==2 or type==3 or type==4)){
                int nextType = grid[r+1][c];
                if(nextType==2 or nextType==5 or nextType==6){
                    visited[r+1][c] = true;
                    q.push({r+ 1, c});
                }
            }
            
            if(r-1 >=0 and !visited[r-1][c] and (type ==2 or type==5 or type == 6)){
                int nextType = grid[r-1][c];
                if(nextType == 2 or nextType==3 or nextType==4){
                    visited[r-1][c] = true;
                    q.push({r-1, c});
                }
            }
        }        
        return false;
    }
};