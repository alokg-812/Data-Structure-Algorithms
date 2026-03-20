class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans(m-k+1, vector<int>(n-k+1, 0));

        for(int i = 0; i<= m-k;i++){
            for(int j = 0;j<=n-k;j++){
                vector<int> ele;
                for(int r = i;r<i+k;r++){
                    for(int c = j;c<j+k;c++){
                        ele.push_back(grid[r][c]);
                    }
                }
                sort(ele.begin(), ele.end());
                int min_diff = INT_MAX;
                bool flag = false;
                for(size_t p = 1;p<ele.size();p++){
                    if(ele[p] != ele[p-1]){
                        min_diff = min(min_diff, ele[p] - ele[p-1]);
                        flag = true;
                    }
                }
                ans[i][j] = flag ? min_diff : 0;
            }
        }
        return ans;
    }
};