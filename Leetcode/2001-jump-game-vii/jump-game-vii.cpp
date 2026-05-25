class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1] != '0') return false;
        queue<int> q;
        q.push(0);
        int far = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == n-1) return true;
            int start = max(curr+minJump, far+1);
            int end = min(curr+maxJump, n-1);
            for(int j = start;j<=end;j++){
                if(s[j] == '0'){
                    if(j == n-1) return true;
                    q.push(j);
                }
            }
            far = max(far, curr+maxJump);
        }
        return false;
    }
};