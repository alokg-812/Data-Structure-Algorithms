// https://leetcode.com/problems/toggle-light-bulbs/description/
// https://leetcode.com/submissions/detail/1919530045/

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int, int> freq;
        for(int num : bulbs){
            freq[num]++;
        }
        vector<int> res;
        for (auto& pair : freq){
            if (pair.second % 2 == 1){
                res.push_back(pair.first);
            }
        }
    
        return res;
    }
};
