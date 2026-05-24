class Solution {
public:
    int passwordStrength(string password) {
        string ans = password;
        unordered_set<char>st(ans.begin(), ans.end());
        int str= 0;
        for(char ch : st){
            if(ch>= 'a' and ch<='z') str +=1;
            else if(ch>='A' and ch<='Z') str += 2;
            else if(ch>='0' and ch<='9') str += 3;
            else if(ch=='!' or ch=='@' or ch=='#' or ch=='$') str+=5;
        }
        return str;
    }
};