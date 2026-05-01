class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long f0 = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            f0 += (long long)i*nums[i];
        }
        
        long long current_f = f0;
        long long max_f = f0;
        for(int k = 1;k<n;k++){
            current_f = current_f +sum -(long long)n *nums[n-k];
            max_f = max(max_f, current_f);
        }
        
        return max_f;
    }
};