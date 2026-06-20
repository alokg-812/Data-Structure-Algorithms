class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rest) {
        rest.push_back({1, 0});
        
        sort(rest.begin(), rest.end());
        if(rest.back()[0] != n){
            rest.push_back({n, n-1});
        }
        int m = rest.size();
        for(int i = 1;i<m;i++){
            int dist = rest[i][0] - rest[i-1][0];
            rest[i][1] = min(rest[i][1], rest[i-1][1] + dist);
        }
        
        for(int i = m-2;i>=0;i--){
            int dist = rest[i+1][0] - rest[i][0];
            rest[i][1] = min(rest[i][1], rest[i+1][1] + dist);
        }
        
        int maxi = 0;
        for(int i = 0; i< m-1;i++){
            int id1 = rest[i][0], h1 = rest[i][1];
            int id2 = rest[i+1][0], h2 = rest[i+1][1];
            
            int peak = (h1 + h2 + (id2-id1)) / 2;
            maxi = max(maxi, peak);
        }
        
        return maxi;
    }
};