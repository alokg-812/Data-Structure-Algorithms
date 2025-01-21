#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            pq.push(nums[i]);
        }
        int ans = 0;
        for(int i = 0;i<k;i++){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>nums = {3,2,1,5,6,4};
    int k = 2;
    cout<<s.findKthLargest(nums,k)<<endl;
}
