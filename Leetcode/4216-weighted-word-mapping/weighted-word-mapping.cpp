class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for(int i = 0;i<words.size();i++){
            int curr= 0;
            string word = words[i];
            for(int j = 0;j<word.length();j++){
                int idx = word[j]-'a';
                curr+=weights[idx];
            }
            int MOD = curr%26;
            char mapp = 'z'-MOD;
            res += mapp;
        }
        
        return res;
    }
};