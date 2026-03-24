class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;

        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j] = grid[i][j]%MOD;
            }
        }

        vector<int>pre(n*m, 1);
        vector<int>suf(n*m, 1);
        for(int i = 1;i<n*m;i++){
            int r = (i-1) /m;
            int c = (i-1) %m;
            pre[i] = (pre[i-1] * grid[r][c]) % MOD;
        }
        for(int i = n*m-2;i>=0;i--){
            int r = (i+1) /m;
            int c = (i+1) %m;
            suf[i] = (suf[i+1] * grid[r][c]) % MOD;
        }
        vector<vector<int>>ans(n, vector<int>(m, 1));
        for(int i = 0; i<n*m;i++){
            int r = i/m;
            int c = i%m;
            ans[r][c] = (pre[i] * suf[i]) %MOD;
        }

        return ans;
    }
};