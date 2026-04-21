class UnionFind {
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); 
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UnionFind uf(n);
        for(const auto& swap : allowedSwaps){
            uf.unite(swap[0], swap[1]);
        }        
        unordered_map<int, unordered_map<int, int>> counts;        
        for(int i = 0;i<n;i++){
            int root = uf.find(i);
            counts[root][source[i]]++;
        }
        int dist = 0;
        
        for(int i = 0;i<n;i++){
            int root = uf.find(i);
            int required_val = target[i];
            if(counts[root][required_val]>0){
                counts[root][required_val]--;
            }
            else{
                dist++;
            }
        }
        return dist;
    }
};