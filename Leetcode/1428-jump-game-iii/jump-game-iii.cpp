class Solution {
public:
    bool canReach(vector<int>& arr, int start){
        int n = arr.size();
        if(n == 0) return false;
        if(arr[start] == 0) return true;
        vector<bool>vis(n, false);
        queue<int> q;
        q.push(start);
        vis[start] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(arr[curr] == 0) return true;
            vector<int> next = {curr+arr[curr], curr- arr[curr]};
            for(int nxt : next){
                if(nxt >= 0 and nxt<n and !vis[nxt]){
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        return false;
    }
};