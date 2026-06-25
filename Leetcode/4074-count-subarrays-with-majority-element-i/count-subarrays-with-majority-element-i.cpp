class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int valid = 0;
        for(int l = 0;l<n;l++){
            int sc = 0;
            
            for(int r = l;r<n;r++){
                if(nums[r] == target) sc +=1;
                else sc -= 1;
                if(sc > 0) valid++;
            }
        }

        return valid;
    }
};