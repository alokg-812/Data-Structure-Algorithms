class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int ele:nums){
            int sum=0;
            while(ele>0){
                sum += ele%10;
                ele/=10;
            }
            if(sum<mini) mini = sum;
        }
        return mini;        
    }
};