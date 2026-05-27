class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>first(26, -1);
        vector<int>last(26, -1);
        for(int i = 0;i<word.length();i++){
            char ch = word[i];
            if(islower(ch)){
                int idx = ch-'a';
                last[idx] = i;
            }
            else{
                int idx = ch-'A';
                if(first[idx] == -1) first[idx] = i;
            }
        }
        int cnt = 0;
        for(int i = 0;i<26;i++){
            if(last[i] != -1 and first[i] !=-1 and last[i]<first[i]) cnt++;
        }
        return cnt;
    }
};