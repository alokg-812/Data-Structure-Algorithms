class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s(nums1.begin(), nums1.end());
        int ans = INT_MAX;
        for(int num : nums2){
            if(s.count(num)) ans = min(ans, num);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};