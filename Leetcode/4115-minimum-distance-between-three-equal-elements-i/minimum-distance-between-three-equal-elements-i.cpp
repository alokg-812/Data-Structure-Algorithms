class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>>idx;
        for(int i = 0;i<n;i++){
            idx[nums[i]].push_back(i);
        }
        int min_dist = -1;
        for(const auto& pair : idx){
            const vector<int>& idxs = pair.second;
            if(idxs.size() >= 3){
                for(int p = 0;p<idxs.size()-2;p++){
                    int curr = 2*(idxs[p+2] - idxs[p]);
                    
                    if(min_dist == -1 or curr < min_dist){
                        min_dist = curr;
                    }
                }
            }
        }
        return min_dist;
    }
};