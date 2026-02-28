class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        long long MOD = 1e9 + 7;
        int length = 0;
        
        for(int i = 1;i<=n;i++){
            if((i & (i-1)) == 0){
                length++;
            }
            ans=((ans<<length) | i) % MOD;
        }
        return ans;
    }
};