class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return false;
        int m = n-1;
        int maxVal = 0;
        for(int x : nums){
            maxVal = max(maxVal, x);
        }
        if(maxVal != m) return false;
        vector<int>freq(m+1, 0);
        for(int x : nums){
            if(x<1 or x>m) return false;
            freq[x]++;
        }
        for(int i = 1;i<m;i++){
            if(freq[i] != 1) return false;
        }
        
        if(freq[m] != 2) return false;
        
        return true;
    }
};