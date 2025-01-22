https://leetcode.com/problems/maximum-product-of-three-numbers/description/
https://leetcode.com/problems/maximum-product-of-three-numbers/submissions/1517049697/

class Solution {
public:
    int maximumProduct(vector<int>& arr) {
        int n= arr.size();
        sort(arr.begin(),arr.end());
        return max(arr[0]*arr[1]*arr[n-1], arr[n-1]*arr[n-2]*arr[n-3]);        
    }
};
