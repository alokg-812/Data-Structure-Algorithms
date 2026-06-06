class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++) sum += nums[i];
        
        int left = 0;
        int right = sum;
        vector<int> answer(n);
        for(int i = 0;i<n;i++){
            right -= nums[i];            
            answer[i] = abs(left-right);
            left += nums[i];
        }
        
        return answer;
    }
};