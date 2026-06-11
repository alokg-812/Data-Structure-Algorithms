class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        long long mod = 1e9 + 7;
        base %= mod;
        while(exp > 0){
            if(exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(int i = 0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        vector<int> dist(n+1, -1);
        
        q.push(1);
        dist[1] = 0;
        int max_depth = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            max_depth = max(max_depth, dist[curr]);
            for(int i = 0;i<adj[curr].size();i++){
                int neighbor = adj[curr][i];
                if(dist[neighbor] == -1){
                    dist[neighbor] = dist[curr] + 1;
                    q.push(neighbor);
                }
            }
        }
        if(max_depth == 0) return 0;
        return power(2, max_depth - 1);
    }
};
