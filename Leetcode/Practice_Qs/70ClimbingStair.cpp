https://leetcode.com/problems/climbing-stairs/description/
https://leetcode.com/problems/climbing-stairs/submissions/1529383198/

class Solution {
public:
    int stairs(int n, vector<int> &arr){
        if(n<=3){
            arr[n] = n;
            return arr[n];
        }
        if(arr[n]== -1){
            arr[n] = stairs(n-1, arr)+stairs(n-2, arr);
        }
        return arr[n];
    }
    int climbStairs(int n) {
        vector<int>arr(n+1,-1);
        return stairs(n, arr);
    }
};
