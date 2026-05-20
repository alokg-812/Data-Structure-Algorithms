class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n);
        vector<bool> seenA(n+1, false);
        vector<bool> seenB(n+1, false);
        for(int i = 0;i<n;i++){
            seenA[A[i]] = true;
            seenB[B[i]] = true;
            int cnt = 0;
            for(int k = 1;k<=n;k++){
                if(seenA[k] and seenB[k]) cnt++;
            }
            C[i] = cnt;
        }
        return C;
    }
};