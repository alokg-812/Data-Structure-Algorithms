class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), cnt1 = 0, cnt0=0, ans=0;
        for(char c:s) if(c=='1') cnt1++;
        string mid = s;
        cnt0 = n-cnt1;
        ans = min(cnt0, cnt1);
        if(cnt1>0) ans = min(ans, cnt1-1);
        int temp = 0;
        if(n>=2){
            int temp1=0, temp2=0;
            if(s[0]=='1') temp1 = 1;
            else temp1 = 0;
            if(s[n-1]=='1') temp2 = 1;
            else temp2 = 0;
            temp = temp1+temp2;
            ans = min(ans, cnt1+2-2*temp);
        }
        return ans;
    }
};