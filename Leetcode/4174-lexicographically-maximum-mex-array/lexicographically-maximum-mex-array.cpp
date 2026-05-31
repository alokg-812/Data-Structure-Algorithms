class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        auto res = nums;
        int n = res.size();        
        vector<int> tot(n+2, 0);
        for(int i = 0;i<n;i++){
            if(res[i] <= n) tot[res[i]]++;
        }

        vector<int> result;
        int i = 0;
        
        while(i < n){
            int tar = 0;
            while(tot[tar] > 0) tar++;

            if(tar == 0){
                result.push_back(0);
                if(res[i] <= n) tot[res[i]]--;
                i++;
            }
            else{
                unordered_set<int>elem;
                int j = i;
                
                while(j < n and elem.size() < tar){
                    if(res[j] < tar){
                        elem.insert(res[j]);
                    }
                    j++;
                }

                result.push_back(tar);
                for(int k = i;k<j;k++){
                    if(res[k] <= n) tot[res[k]]--;
                }
                
                i = j;
            }
        }

        return result;
    }
};