class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x){
        vector<int>nums;
        for(const auto& row : grid){
            for(int val : row) nums.push_back(val);
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if((nums[i]-nums[0])%x !=0) return -1;
        }        
        int median = nums[n / 2];
        int totalOperations = 0;
        for(int val : nums){
            totalOperations += abs(val-median) /x;
        }
        return totalOperations;
    }
};