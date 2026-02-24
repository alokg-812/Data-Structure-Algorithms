class Solution {
public:
    bool hasAllCodes(string s, int k){
        int n = s.length();
        if(n<k){
            return false;
        }
        
        int req = 1 << k;
        unordered_set<string> seen;
        
        for(size_t i = 0; i<=n-k;i++){
            string substr = s.substr(i, k);
            seen.insert(substr);
            if(seen.size() == req){
                return true;
            }
        }
        return seen.size() == req;
    }
};