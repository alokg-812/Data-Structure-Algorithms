class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i<n;i++) mp[arr[i]].push_back(i);
        vector<bool> vis(n, false);
        queue<int>q;
        q.push(0);
        vis[0] = true;
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                if(curr == n-1) return steps;
                if(curr-1 >= 0 and !vis[curr-1]){
                    vis[curr-1] = true;
                    q.push(curr-1);
                }
                if(curr+1 < n and !vis[curr+1]){
                    vis[curr+ 1] = true;
                    q.push(curr+1);
                }
                if(mp.count(arr[curr])){
                    for(int idx : mp[arr[curr]]){
                        if(!vis[idx]){
                            vis[idx] = true;
                            q.push(idx);
                        }
                    }
                    mp.erase(arr[curr]);
                }
            }
            steps++;
        }
        return -1;
    }
};