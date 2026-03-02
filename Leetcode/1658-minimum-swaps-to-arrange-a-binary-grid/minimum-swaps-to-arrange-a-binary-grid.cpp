class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> req(n);
        for(int i = 0; i<n;i++){
            req[i] = -1;
            for(int j = 0; j<n;j++){
                if(grid[i][j] == 1){
                    req[i] = j;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            int j = i;
            while(j<n and req[j]>i){
                j++;
            }
            if(j == n){
                return -1;
            }
            ans += (j-i);
            int temp = req[j];
            for(int k = j;k>i;k--){
                req[k] = req[k-1];
            }
            req[i] = temp;
        }
        return ans;
    }
};