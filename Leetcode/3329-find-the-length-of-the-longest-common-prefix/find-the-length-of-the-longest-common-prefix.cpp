class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>pre;
        for(int num : arr1){
            while(num > 0){
                pre.insert(num);
                num/= 10;
            }
        }
        int maxi = 0;
        for(int num : arr2){
            while(num> 0){
                if(pre.count(num)){
                    string s = to_string(num);
                    maxi = max(maxi, (int)s.length());
                    break;
                }
                num /=10;
            }
        }
        return maxi;
    }
};