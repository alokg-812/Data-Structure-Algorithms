class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> lens(n, 0);
        long long curr = 0;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == '*'){
                if(curr > 0) curr--;
            }
            else if(ch == '#'){
                if(curr > 2e15) curr = 2e15; 
                else curr *= 2;
            }
            else if(ch == '%') {
                curr = curr; 
            }
            else {
                curr++;
            }
            lens[i] = curr;
        }

        if(k < 0 || k >= curr) return '.';
        for(int i = n - 1; i >= 0; i--){
            char ch = s[i];
            long long prev = (i == 0) ? 0 : lens[i - 1];

            if(ch == '*') continue;
            else if(ch == '#') {
                if(k >= prev) {
                    k -= prev;
                }
            }
            else if(ch == '%') {
                k = prev - 1 - k;
            }
            else {
                if(k == prev) return ch;
            }
        }

        return '.';
    }
};