class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool low[26] = {false};
        bool up[26] = {false};
        for(char ch : word){
            if(islower(ch)) low[ch-'a'] = true;
            else if(isupper(ch)) up[ch-'A'] = true;
        }
        int cnt = 0;
        for(int i = 0; i<26;i++){
            if(low[i] and up[i]) cnt++;
        }
        return cnt;
    }
};