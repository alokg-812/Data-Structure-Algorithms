class Solution {
public:
    int reverseNum(int x){
        int rev = 0;
        while(x!=0){
            rev = rev*10 + x%10;
            x /=10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums){
        unordered_map<int, int>rev;
        int min_dist = INT_MAX;
        for(int j = 0;j<nums.size();j++){
            if(rev.count(nums[j])) min_dist = min(min_dist, j - rev[nums[j]]);
            int rev_num = reverseNum(nums[j]);
            rev[rev_num] = j;
        }
        if(min_dist == INT_MAX) return -1;
        return min_dist;
    }
};