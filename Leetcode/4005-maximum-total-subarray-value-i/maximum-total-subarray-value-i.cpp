class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = nums[0], maxi=nums[0];
        for(long long ele: nums){
            if(ele<mini) mini = ele;
            if(ele>maxi) maxi = ele;
        }
        return (long long)k * (maxi-mini);
    }
};