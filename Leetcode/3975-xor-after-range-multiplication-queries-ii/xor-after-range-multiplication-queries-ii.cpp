class Solution {
    const int mod= 1000000007;
    long long power(long long base, long long exp){
        long long res = 1;
        base %= mod;
        while(exp > 0){
            if(exp%2 == 1) res = (res*base) %mod;
            base = (base*base) %mod;
            exp/=2;
        }
        return res;
    }
    long long modInverse(long long n){
        return power(n, mod-2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int b = sqrt(n); 
        if(b<1) b = 1;
        vector<vector<int>> queries_by_k(b);
        for(int i = 0; i<queries.size();i++){
            int k = queries[i][2];
            if(k>=b){
                int l = queries[i][0];
                int r = queries[i][1];
                int v = queries[i][3];
                for(int idx = l;idx<=r;idx+=k){
                    nums[idx] = (1LL*nums[idx]* v) %mod;
                }
            } 
            else{
                queries_by_k[k].push_back(i);
            }
        }
        vector<int> diff(n);
        for(int k = 1;k<b;k++){
            if(queries_by_k[k].empty()) continue;
            fill(diff.begin(), diff.end(), 1);
            
            for(int q_idx : queries_by_k[k]){
                int l = queries[q_idx][0];
                int r = queries[q_idx][1];
                int v = queries[q_idx][3];
                diff[l] = (1LL*diff[l] *v) %mod;
                int r_prime = r - (r-l) %k;
                int nxt = r_prime+k;
                if(nxt<n){
                    long long inv_v = modInverse(v);
                    diff[nxt] = (1LL * diff[nxt] *inv_v)%mod;
                }
            }
            for(int i = 0;i<n;i++){
                if(i>=k) diff[i] = (1LL*diff[i]*diff[i - k]) %mod;
                nums[i] = (1LL*nums[i]*diff[i]) %mod;
            }
        }
        int res = 0;
        for(int num : nums){
            res^=num;
        }
        return res;
    }
};