class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for(int i = 0;i<n;i++){
            pos[nums[i]].push_back(i);
        }
        vector<int> min_dist(n, -1);
        for(const auto& [val, indices] : pos){
            int m = indices.size();
            if(m>1){
                for(int k = 0;k<m;k++){
                    int curr = indices[k];                    
                    int prev_idx = indices[(k-1 +m) %m];
                    int next_idx = indices[(k+1) %m];                    
                    int dist_to_prev = (curr-prev_idx+n) % n;
                    int dist_to_next = (next_idx-curr+n) % n;
                    
                    min_dist[curr] = min(dist_to_prev, dist_to_next);
                }
            }
        }        
        vector<int>ans;
        ans.reserve(queries.size());
        for(int q : queries){
            ans.push_back(min_dist[q]);
        }
        return ans;
    }
};