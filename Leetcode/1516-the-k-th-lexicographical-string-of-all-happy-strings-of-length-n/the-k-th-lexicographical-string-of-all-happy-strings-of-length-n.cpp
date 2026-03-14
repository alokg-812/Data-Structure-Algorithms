class Solution {
public:
    string getHappyString(int n, int k) {
        if (k < 1) return "";
        
        string res = "";
        vector<char> chars = {'a', 'b', 'c'};
        long long curr = k;
        
        for(int pos = 0;pos<n;pos++){
            bool flag = false;
            for(char ch : chars){
                if(!res.empty() && ch == res.back()) {
                    continue;
                }
                int rem = n - (int)res.size() - 1;
                long long count = (rem >= 1) ? (1LL << rem) : 1LL;
            
                if(curr <= count) {
                    res += ch;
                    flag = true;
                    break;
                }
                else{
                    curr -= count;
                }
            }
            
            if(!flag){
                return "";
            }
        }
        return res;
    }
};