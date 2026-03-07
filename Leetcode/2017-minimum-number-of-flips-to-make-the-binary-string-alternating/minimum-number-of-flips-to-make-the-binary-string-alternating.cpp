class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int ans = n;
        string s2 = s + s;
        int cost01 = 0;
        for(int i = 0;i<n;i++){
            if(s2[i] != (i & 1 ? '1' : '0')) ++cost01;
        }
        ans = min(ans, cost01);
        int cost10 = 0;
        for(int i = 0;i<n;i++){
            if(s2[i] != (i&1 ? '0' : '1')) ++cost10;
        }
        ans = min(ans, cost10);
        
        for(int i = 1;i<n;i++){
            if(s2[i-1] != ((i-1) & 1 ? '1' : '0')) --cost01;
            if(s2[i+n-1] != ((i+n-1) & 1 ? '1' : '0')) ++cost01;
            ans = min(ans, cost01);
            
            if (s2[i-1] != ((i-1) & 1 ? '0' : '1')) --cost10;
            if(s2[i+n-1] != ((i+n-1) & 1 ? '0' : '1')) ++cost10;
            ans = min(ans, cost10);
        }
        return ans;
    }
};