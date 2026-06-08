class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>less;
        vector<int>equal;
        vector<int>great;
        for(int i =0;i<nums.size();i++){
            if(nums[i]<pivot) less.push_back(nums[i]);
            else if(nums[i]>pivot) great.push_back(nums[i]);
            else equal.push_back(nums[i]);
        }
        vector<int>ans;
        for(int i : less) ans.push_back(i);
        for(int i : equal) ans.push_back(i);
        for(int i : great) ans.push_back(i);
        return ans;
    }
};