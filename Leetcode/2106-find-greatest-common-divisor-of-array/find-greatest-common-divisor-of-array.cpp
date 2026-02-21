class Solution {
public:
    int findGcd(int n1, int n2) {
        for(int i = min(n1, n2); i > 0; i--) {
            if(n1 % i == 0 && n2 % i == 0) {
                return i;
            }
        }
        return 1;
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zeroth = nums[0];
        int last = nums[nums.size()-1];
        return findGcd(zeroth, last);
    }
};