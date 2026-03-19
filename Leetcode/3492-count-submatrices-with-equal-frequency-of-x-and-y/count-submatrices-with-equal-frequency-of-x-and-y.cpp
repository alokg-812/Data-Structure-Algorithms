class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int count = 0;
        vector<int>col_X(n, 0);
        vector<int>col_Y(n, 0);
        
        for(int i = 0;i<m;i++){
            int curr_X = 0;
            int curr_Y = 0;
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 'X'){
                    col_X[j]++;
                }else if(grid[i][j] == 'Y') {
                    col_Y[j]++;
                }
                curr_X += col_X[j];
                curr_Y += col_Y[j];
                if(curr_X == curr_Y and curr_X > 0){
                    count++;
                }
            }
        }
        
        return count;
    }
};