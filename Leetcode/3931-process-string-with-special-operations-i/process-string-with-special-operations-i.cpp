class Solution {
public:
    string processStr(string s) {
        string result= "";        
        for(int i = 0; i<s.length();i++){
            char ch = s[i];
            if(ch >= 'a' and ch <= 'z') result += ch; 
            else if(ch== '*'){
                if(!result.empty()) result.pop_back();
            } 
            else if(ch=='#') result += result;
            else if(ch=='%') reverse(result.begin(), result.end());
        }
        
        return result;
    }
};