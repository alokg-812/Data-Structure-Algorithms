class Solution {
public:
    bool checkOnesSegment(string s) {
        bool zero = false;
        for(char c : s){
            if(c == '0'){
                zero = true;
            }
            else if(zero){
                return false;
            }
        }
        return true;
    }
};