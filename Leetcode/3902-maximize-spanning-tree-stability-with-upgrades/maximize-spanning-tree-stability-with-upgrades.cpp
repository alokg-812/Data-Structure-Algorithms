class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
            return true;
        }
        return false;
    }
};

class Solution {
    bool check(int X, int n, const vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int edges_added = 0;
        int upgrades_needed = 0;

        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (e[2] < X) return false;
                dsu.unite(e[0], e[1]);
                edges_added++;
            }
        }

        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] >= X) {
                if (dsu.unite(e[0], e[1])) {
                    edges_added++;
                }
            }
        }

        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] < X && 2LL * e[2] >= X) {
                if (dsu.unite(e[0], e[1])) {
                    edges_added++;
                    upgrades_needed++;
                }
            }
        }

        return edges_added == n - 1 && upgrades_needed <= k;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu_all(n);
        DSU dsu_must(n);
        int total_edges = 0;

        for (const auto& e : edges) {
            if (dsu_all.unite(e[0], e[1])) {
                total_edges++;
            }
            if (e[3] == 1) {
                if (!dsu_must.unite(e[0], e[1])) {
                    return -1;
                }
            }
        }
        
        if (total_edges < n - 1) return -1;

        int left = 1, right = 200000;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, n, edges, k)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};