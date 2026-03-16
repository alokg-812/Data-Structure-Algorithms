class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> top3;
        auto add_to_top3 = [&](int val){
            top3.insert(val);
            if(top3.size() > 3){
                top3.erase(top3.begin());
            }
        };

        for(int r = 0;r<m;r++){
            for(int c = 0; c<n;c++){
                int max_L = min({r, m-1-r, c, n-1-c});                
                for(int L = 0; L<=max_L;L++){
                    if(L == 0){
                        add_to_top3(grid[r][c]);
                    }
                    else{
                        int sum = 0;
                        int cur_r = r-L, cur_c = c;
                        for(int i = 0;i< L;i++) sum += grid[cur_r++][cur_c++];
                        for(int i = 0;i<L;i++) sum += grid[cur_r++][cur_c--];
                        for(int i = 0;i<L;i++) sum += grid[cur_r--][cur_c--];
                        for(int i = 0;i<L;i++) sum += grid[cur_r--][cur_c++];
                        
                        add_to_top3(sum);
                    }
                }
            }
        }
        vector<int> result(top3.rbegin(), top3.rend());
        return result;
    }
};