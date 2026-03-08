class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        vector<int> nav = nums; 
        int n = nav.size();
        if(n==0) return -1;        
        long long MAX_SUM = 100000000000000LL; 
        
        vector<long long> right(n, 1);
        long long curr= 1;
        
        for(int i = n-1; i>=0; i--){
            right[i] = curr;
            if(curr<= MAX_SUM){
                if(nav[i] > MAX_SUM / curr){
                    curr= MAX_SUM + 1;
                } 
                else{
                    curr *= nav[i];
                }
            }
        }
        long long left = 0;
        for(int i = 0;i<n;i++){
            if(left == right[i]){
                return i;
            }
            left += nav[i];
        }        
        return -1;
    }
};